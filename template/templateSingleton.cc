/*
 * @Author: your name
 * @Date: 2020-01-20 20:42:13
 * @LastEditTime : 2020-01-20 22:43:34
 * @LastEditors  : Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \VS-Code-C++\20200120\templateSingleton.cc
 */
#include <iostream>

using std::cout;
using std::endl;
using std::string;

template <class T>
class Singleton
{
public:
    template <class... Args>
    static T *getInstance(Args... args) 
    {
        if (pInstance == nullptr)
            pInstance = new T(args...);
        return pInstance;
    }
    static void destroy()
    {
        if (pInstance)
            delete pInstance;
    }
    void print() const
    {
        cout << "print" << endl;
    }

private:
    Singleton() {}
    ~Singleton()
    {
        if (pInstance)
            pInstance = nullptr;
        cout << "~Singleton()" << endl;
    }

    static T *pInstance;
};
template <class T>
T *Singleton<T>::pInstance = nullptr;

class Point
{
public:
    Point(double x, double y)
        : _x(x), _y(y)
    {
        cout << "Point(double x, double y)" << endl;
    }
    void display()
    {
        cout << "(" << _x << "," << _y << ")" << endl;
    }

private:
    double _x;
    double _y;
};
class Computer
{
public:
    Computer(string brand, double price)
        : _brand(brand), _price(price) {}
    void display()
    {
        cout << "brand: " << _brand << endl
             << "price: " << _price << endl;
    }

private:
    string _brand;
    double _price;
};

void test()
{

    Computer *p1 = Singleton<Computer>::getInstance("Xiaomi", 6666);
    p1->display();
    // Computer* p2 = Singleton<Computer>::getInstance("Xiaomi", 6666);

    Point *p3 = Singleton<Point>::getInstance(1, 2);
    p3->display();
    //	 Point* p4 = Singleton<Point>::getInstance(1, 2);
}
int main()
{
    test();
    return 0;
}