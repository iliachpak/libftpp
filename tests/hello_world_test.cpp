#include "libftpp/data_structures.hpp"

int main() 
{
    Pool A;

    helloWorld(A._prototype.x);
    std::cout << "===\n";
    helloWorld(A._prototype.getY());
    std::cout << "===\n";

    return (0);
}
