#ifndef DATABUFFER_HPP
#define DATABUFFER_HPP

#include <iostream>

class DataBuffer 
{
public :
    DataBuffer() : _t(2) {}
    virtual void showType() const { std::cout << _t << std::endl; }

private : 
    int _t;
};


class DataPuffer : public DataBuffer 
{
public :
    DataPuffer() : _p(69) {}
    void showType() const { std::cout << _p << " la trique." << std::endl; }
private:
    int _p;
};

#endif
