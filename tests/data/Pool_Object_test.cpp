// #include "libftpp/data/data_structures.hpp"

// #include <string>
// #include <iostream>

// class Test_type
// {
// public :
//     Test_type() : _x(1), _y(2), _comp(" -> ") {}
//     Test_type(int x, int y, std::string comp) : _x(x), _y(y), _comp(comp) {}

//     int getX() const { return _x; }
//     int getY() const { return _y; }
//     std::string getComp() const { return _comp; }
// private :
//     int _x;
//     int _y;
//     std::string _comp;
// };

// bool operator==(const Test_type& lhs, const Test_type& rhs)
// {
//     if (lhs.getX() == rhs.getX() &&
//         lhs.getY() == rhs.getY() &&
//         lhs.getComp() == rhs.getComp())
//         return true;
//     return false;
// }

// std::ostream& operator<<(std::ostream& o, const Test_type& testObj)
// {
//     o   << testObj.getX()
//         << " " << testObj.getComp()
//         << " " << testObj.getY()
//         << std::endl; 
//     return o;
// }

// /*====TESTS====*/
    
// bool test_parameterized_constructor()
// {
//     Pool<int> tmp1(1);
//     Pool<std::string> tmp2(1);
//     Pool<Test_type> tmp3(1);

//     int x = 42;
//     std::string name("ilia");
//     Test_type Test_obj(2, 3, "smaller than");

//     // int* x_ptr = &x;
//     // std::string* name_ptr = &name;
//     // Test_type* test_ptr = &Test_obj;

//     Pool<int>::Object a(&tmp1, &x);
//     Pool<std::string>::Object b(&tmp2, &name);
//     Pool<Test_type>::Object c(&tmp3, &Test_obj);

//     return true;    
// }

// // bool test_copy_constructor()
// // {
// //     Test_type Test_obj(2, 3, "smaller than");

// //     Pool<int>::Object A(42);
// //     Pool<std::string>::Object B("Phantom is better than vandal.");
// //     Pool<Test_type>::Object C(Test_obj);

// //     Pool<int>::Object a(A);
// //     Pool<std::string>::Object b(B);
// //     Pool<Test_type>::Object c(C);

// //     if (a.getContent() != A.getContent())
// //         return false;
// //     if (b.getContent() != B.getContent())
// //         return false;
// //     if (!(c.getContent() == C.getContent()))
// //         return false;
// //     return true;
// // }

// // bool test_add_content()
// // {
// //     int x = 42;
// //     std::string name("ilia");

// //     Pool<int>::Object A(x);
// //     Pool<std::string>::Object B(name);

// //     Pool<int>::Object a;
// //     Pool<std::string>::Object b;

// //     a.addContent(x);
// //     b.addContent(name);

// //     if (a.getContent() != A.getContent())
// //         return false;
// //     if (b.getContent() != B.getContent())
// //         return false;
// //     return true;
// // }

// // bool test_copy_content()
// // {
// //     Test_type Test_obj(2, 3, "smaller than");

// //     Pool<Test_type>::Object A(Test_obj);

// //     Pool<Test_type>::Object a;
// //     a.copyContent(A);

// //     if (!(a.getContent() == A.getContent()))
// //         return false;
// //     return true;
// // }
