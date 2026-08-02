/*=======Pool:Object========*/

// constructor

template<typename TType>
Pool<TType>::Object::Object() : _pool(nullptr), _ptr(nullptr)
{
}

template<typename TType>
Pool<TType>::Object::Object(Pool* pool, TType* ptr) : _pool(pool), _ptr(ptr)
{
}

// move

template<typename TType>
Pool<TType>::Object::Object(Object&& other) noexcept
    : _pool(other._pool), _ptr(other._ptr)
{
    other.pool = nullptr;
    other.ptr = nullptr;
}

template<typename TType>
Pool<TType>::Object& Pool<TType>::Object::operator=(Object&& other) noexcept
{
    _pool = other._pool;
    _ptr = other._ptr;
    other._pool = nullptr;
    other._ptr = nullptr;
    return *this;
}

// destructor

template<typename TType>
Pool<TType>::Object::~Object()
{
    _pool->release(_ptr);
}

// operator

template<typename TType>
TType* Pool<TType>::Object::operator->()
{
    return _ptr;
}

template<typename TType>
TType& Pool<TType>::Object::operator*()
{
    return *_ptr;
}

// methodes

template<typename TType>
bool Pool<TType>::Object::valid() const
{
    if (_ptr != nullptr)
        return true;
    return false;
}

/*====Pool====*/

//private

template<typename TType>
void Pool<TType>::release(TType* ptr)
{
    ptr = nullptr;
}

// public
// constructor

template<typename TType>
Pool<TType>::Pool(int size)
{
    _pool = new Pool[size];
}

template<typename TType>
Pool<TType>::~Pool()
{
    delete[] _pool;
}

template<typename TType>
Pool<TType>::Object Pool<TType>::acquire()
{
    Object res(*this, _pool[0]);
    return res;
}
