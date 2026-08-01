#include "libftpp/data/data_structures.hpp"

bool test_parameterized_constructor();
bool test_copy_constructor();

int main() 
{
    std::string owner("ilia");
    Pool A(owner);

    std::cout << "=========NESTED CLASS & ERITAGE=========" << std::endl;

    std::cout << "The object : " << A._prototype.getContent() << std::endl;
    std::cout << "===\n";

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

    std::cout << "=========TESTS=========" << std::endl;

    if (test_parameterized_constructor() && test_copy_constructor())
        std::cout<< "The Pool::Object tests have passed successfully." << std::endl;
    else 
        std::cout<< "The Pool::Object tests have failed." << std::endl;

    return (0);
}
