#ifndef POOL_HPP
#define POOL_HPP


#include <cstddef>

template<typename TType>
class Pool
{
public:
    class Object
    {
    public :
        Object();
        Object(Pool* pool, TType* ptr);

        Object(const Object&) = delete;
        Object& operator=(const Object&) = delete;

        Object(Object&& other) noexcept;
        Object& operator=(Object&& other) noexcept;

        ~Object();

        TType* operator->();
        const TType* operator->() const;

        TType& operator*();
        const TType& operator*() const;

        explicit operator bool() const noexcept;
        bool valid() const noexcept;

    private :
        Pool* _pool;
        TType* _ptr;
    };

public :

    Pool();
    ~Pool();

    Pool(const Pool&) = delete;
    Pool& operator=(const Pool&) = delete;

    Pool(Pool&&) = delete;
    Pool& operator=(Pool&&) = delete;

    void resize(const size_t& numberOfObjectStored);

    template<typename... TArgs>
    Object acquire(TArgs&&... args);

private:

    void release(TType* ptr);

private:

    TType* _memory;
    size_t _capacity;
    size_t _available;

    TType** _freeList;

    friend class Object;
};

#include "Pool.tpp"

#endif
