#include "libftpp/data/data_structures.hpp"

int main() 
{
    Pool A;
    DataBuffer B;
    DataPuffer P;

    std::cout << "=========NESTED CLASS & ERITAGE=========" << std::endl;
    helloWorld(A._prototype.x);
    std::cout << "===\n";
    helloWorld(A._prototype.getY());
    std::cout << "===\n";
    showData(B);
    std::cout << "===\n";
    showData(P);

    std::cout << "=========TEMPLATE TESTS=========" << std::endl;

    // size_t size = 6;
    Array<int> array(6);

    array[0] = 2;
    array[1] = 12;
    array[2] = 42;

    std::cout << array;

    Array<int> brray;
    brray = array;
    std::cout << brray;

    return (0);
}
