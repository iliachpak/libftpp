#ifndef POOL_HPP
#define POOL_HPP

#include <cstddef>
#include <iostream>
#include <sstream>
#include <stdexcept>

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

        TType* operator->():
        TType& operator*();

        bool valid() const;

    private :
        Pool* _pool;
        TType* _ptr;
    };

public :
    Object acquire();
private:
    void release(TType* ptr);
};

#include "Pool.tpp"

/*-----------Template Practice-----------*/

template<typename ELEMENT>
class Array
{
public :
    Array(size_t size = 10);
    Array(const Array<ELEMENT>& original);
    ~Array();

    size_t getSize() const;

    Array<ELEMENT>& operator=(const Array<ELEMENT>& original);
    ELEMENT& operator[](size_t position) const;
private :
    ELEMENT* _rawArray;
    size_t _size;
};

template<typename ELEMENT>
std::ostream& operator<<(std::ostream& os, const Array<ELEMENT>& array)
{
    os << "The Array contain :\n";

    for (size_t i = 0; i < array.getSize(); i++)
        os << i << " : " << array[i] << "\n";
    return os;
}

/*----------methodes---------*/

template<typename ELEMENT>
Array<ELEMENT>::Array(size_t size) : _size(size)
{
    _rawArray = new ELEMENT[size];
}

template <typename ELEMENT>
Array<ELEMENT>::Array( const Array<ELEMENT>& original ) {
    this->_rawArray = nullptr;
    *this = original;
}

template <typename ELEMENT>
Array<ELEMENT>::~Array()
{
    delete[] _rawArray;
}

template<typename ELEMENT>
size_t Array<ELEMENT>::getSize() const 
{
    return _size;
}

template<typename ELEMENT>
Array<ELEMENT>& Array<ELEMENT>::operator=(const Array<ELEMENT>& original)
{
    if (this != &original)
    {
        delete[] _rawArray;
        _size = original._size;
        _rawArray = new ELEMENT[_size];

        for (size_t i = 0; i < _size; i++)
            _rawArray[i] = original._rawArray[i];
    }

    return *this;
}

template<typename ELEMENT>
ELEMENT& Array<ELEMENT>::operator[](size_t position) const
{
    if (position >= _size)
    throw std::out_of_range("Index out of range");

    return _rawArray[position];
}

#endif
