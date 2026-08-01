#include "libftpp/data/data_structures.hpp"

#include <string>
#include <iostream>

class Test_type
{
public :
    Test_type(int x, int y, std::string comp) : _x(x), _y(y), _comp(comp) {}

    int getX() const { return _x; }
    int getY() const { return _y; }
    std::string getComp() const { return _comp; }
private :
    int _x;
    int _y;
    std::string _comp;
};

bool operator==(const Test_type& lhs, const Test_type& rhs)
{
    if (lhs.getX() == rhs.getX() &&
        lhs.getY() == rhs.getY() &&
        lhs.getComp() == rhs.getComp())
        return true;
    return false;
}

std::ostream& operator<<(std::ostream& o, const Test_type& testObj)
{
    o   << testObj.getX()
        << " " << testObj.getComp()
        << " " << testObj.getY()
        << std::endl; 
    return o;
}

/*====TESTS====*/
    
bool test_parameterized_constructor()
{
    Test_type Test_obj(2, 3, "smaller than");

    Pool<int>::Object A(42);
    Pool<std::string>::Object B("Phantom is better than vandal.");
    Pool<Test_type>::Object C(Test_obj);

    if (A.getContent() != 42)
        return false;
    if (B.getContent() != "Phantom is better than vandal.")
        return false;
    if (!(C.getContent() == Test_obj))
        return false;
    return true;
}

bool test_copy_constructor()
{
    Test_type Test_obj(2, 3, "smaller than");

    Pool<int>::Object A(42);
    Pool<std::string>::Object B("Phantom is better than vandal.");
    Pool<Test_type>::Object C(Test_obj);

    Pool<int>::Object a(A);
    Pool<std::string>::Object b(B);
    Pool<Test_type>::Object c(C);

    if (a.getContent() != A.getContent())
        return false;
    if (b.getContent() != B.getContent())
        return false;
    if (!(c.getContent() == C.getContent()))
        return false;
    return true;
}
