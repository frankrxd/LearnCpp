#include <stdlib.h>

#include <iostream>
using std::cout;
using std::endl;

//atexit + destroy

class Singleton
{
public:
    static Singleton * getInstance()
    {
        if(nullptr==_pInstance)
        {
            ::atexit(destroy);
            _pInstance = new Singleton();
        }
        return _pInstance;
    }
    static void destroy()
    {
        if(_pInstance)
            delete _pInstance;
    }

private:
    Singleton(){
        cout<<"Singleton()"<<endl;
    }
    ~Singleton(){
        cout<<"~Singleton()"<<endl;
    }
private:
    static Singleton * _pInstance;
};
//懒汉模式
//Singleton * Singleton::_pInstance=nullptr;
//饿汉模式
Singleton * Singleton ::_pInstance = getInstance();
int main()
{
    Singleton * p1=Singleton::getInstance();
    
    return 0;
}