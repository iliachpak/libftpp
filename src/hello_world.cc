#include "libftpp/public_header.hh"

void helloWorld(int it)
{
    if (it > 0)
        for (int i = 0; i < it; i++)
            std::cout << "Hello world !" << std::endl;
    else
        std::cout << "Hello world !" << std::endl;
}
