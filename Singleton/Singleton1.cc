#include <iostream>
using std::cout;
using std::endl;

//嵌套类+静态对象
class Singleton
{
public:
    static Singleton * getInstance()
    {
        if(nullptr==_pInstance)
            _pInstance = new Singleton();
        return _pInstance;
    }

private:
    class AutoRelease
    {
        public:
            AutoRelease(){}
            ~AutoRelease()
                {
                    if(_pInstance)
                    {
                        delete _pInstance;
                        cout<<"~AutoRelease()"<<endl;
                    }
                }
            
    };
private:
    Singleton(){
        cout<<"Singleton()"<<endl;
    }
    ~Singleton(){
        cout<<"~Singleton()"<<endl;
    }
private:
    static Singleton * _pInstance;
    static AutoRelease _ar;
};
//懒汉模式
Singleton * Singleton::_pInstance=nullptr;
//饿汉模式
Singleton::AutoRelease Singleton::_ar;
int main()
{
    Singleton * p1=Singleton::getInstance();
    
    return 0;
}