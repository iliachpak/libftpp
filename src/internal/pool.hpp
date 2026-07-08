#ifndef POOL_HPP
#define POOL_HPP

class Pool
{
public:
    class Object
    {
    public : 
        int x;
        Object() { x = 3; y = 5; }
        int getY() { return y; }
    private :
        int y;
    };

    Object _prototype;
private:

};

#endif
