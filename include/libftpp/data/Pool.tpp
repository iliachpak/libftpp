#include <new>
#include <utility>
#include <stdexcept>

//
// Pool::Object
//

template<typename TType>
Pool<TType>::Object::Object() noexcept :
    _pool(nullptr),
    _ptr(nullptr)
{
}

template<typename TType>
Pool<TType>::Object::Object(Pool* pool, TType* ptr) noexcept :
    _pool(pool),
    _ptr(ptr)
{
}

template<typename TType>
Pool<TType>::Object::Object(Object&& other) noexcept :
    _pool(other._pool),
    _ptr(other._ptr)
{
    other._pool = nullptr;
    other._ptr = nullptr;
}

template<typename TType>
typename Pool<TType>::Object&
Pool<TType>::Object::operator=(Object&& other) noexcept
{
    if (this != &other)
    {
        if (_ptr)
        {
            _ptr->~TType();
            _pool->release(_ptr);
        }

        _pool = other._pool;
        _ptr = other._ptr;

        other._pool = nullptr;
        other._ptr = nullptr;
    }

    return *this;
}

template<typename TType>
Pool<TType>::Object::~Object()
{
    if (_ptr)
    {
        _ptr->~TType();
        _pool->release(_ptr);
    }
}

template<typename TType>
TType* Pool<TType>::Object::operator->()
{
    return _ptr;
}

template<typename TType>
const TType* Pool<TType>::Object::operator->() const
{
    return _ptr;
}

template<typename TType>
TType& Pool<TType>::Object::operator*()
{
    return *_ptr;
}

template<typename TType>
const TType& Pool<TType>::Object::operator*() const
{
    return *_ptr;
}

template<typename TType>
Pool<TType>::Object::operator bool() const noexcept
{
    return _ptr != nullptr;
}

template<typename TType>
bool Pool<TType>::Object::valid() const noexcept
{
    return _ptr != nullptr;
}

//
// Pool
//

template<typename TType>
Pool<TType>::Pool() :
    _memory(nullptr),
    _capacity(0),
    _available(0),
    _freeList(nullptr)
{
}

template<typename TType>
Pool<TType>::~Pool()
{
    ::operator delete(_memory);
    delete[] _freeList;
}

template<typename TType>
void Pool<TType>::resize(const size_t& numberOfObjectStored)
{
    ::operator delete(_memory);
    delete[] _freeList;

    _capacity = numberOfObjectStored;
    _available = numberOfObjectStored;

    _memory = static_cast<TType*>(
        ::operator new(sizeof(TType) * _capacity));

    _freeList = new TType*[_capacity];

    for (size_t i = 0; i < _capacity; ++i)
        _freeList[i] = _memory + i;
}

template<typename TType>
template<typename... TArgs>
typename Pool<TType>::Object
Pool<TType>::acquire(TArgs&&... args)
{
    if (_available == 0)
        throw std::runtime_error("Pool is empty.");

    TType* ptr = _freeList[--_available];

    new (ptr) TType(std::forward<TArgs>(args)...);

    return Object(this, ptr);
}

template<typename TType>
void Pool<TType>::release(TType* ptr)
{
    _freeList[_available++] = ptr;
}
