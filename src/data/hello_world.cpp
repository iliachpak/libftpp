#include "libftpp/data/data_structures.hpp"

void helloWorld(int it)
{
    std::cout << "the number is " << it << std::endl;
}

void showData(DataBuffer const& data)
{
    data.showType();
}

///////////////////

template <typename ... Targs>
Pool::Object<TType>acquire(Targs&& p_args);

/////////////////////////
/////////////////////

template<typename T>
class Pool
{
public:
    template<typename T>
    class Object
    {
    private:
        T* _value;
        
    }

}