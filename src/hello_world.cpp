#include "libftpp/data_structures.hpp"

void helloWorld(int it)
{
    std::cout << "the number is " << it << std::endl;
}

void showData(DataBuffer const& data)
{
    data.showType();
}
