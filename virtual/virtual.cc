/*
 * @Author: frank
 * @Date: 2020-01-14 19:57:44
 * @LastEditTime : 2020-01-14 21:05:15
 * @LastEditors  : Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \VS-Code-C++\20200114\virtual.cc
 */
#include <iostream>

using std::cout;
using std::endl;
using std::string;

const double pi = 3.1415926;
class Figure
{
protected:
    string _name;

public:
    virtual double getArea() = 0;
    virtual string getName() = 0;
    virtual void show() = 0;

public:
    Figure() {}
    Figure(const string &name)
        : _name(name) {}
};

class Circle : public Figure
{
protected:
    double _r;

public:
    Circle() {}
    Circle(const string &name, const double &r)
        : Figure(name), _r(r) {}

public:
    double getRadius()
    {
        return _r;
    }
    double getPerimeter()
    {
        return _r * 2 * pi;
    }
    double getArea()
    {
        return _r * _r * pi;
    }
    string getName()
    {
        return _name;
    }
    void show()
    {
        cout << "Figure: " << getName() << endl
             << "Radius: " << getRadius() << endl
             << "Perimeter: " << getPerimeter() << endl
             << "Area: " << getArea() << endl
             << endl;
    }
};

class Cylinder : public Circle
{
protected:
    double _h;

public:
    Cylinder() {}
    Cylinder(const string &name, const double &r, const double &h)
        : Circle(name, r), _h(h) {}

public:
    double getArea()
    {
        return getPerimeter() * _h + 2 * Circle::getArea();
    }
    string getName()
    {
        return _name;
    }
    double getHeight()
    {
        return _h;
    }
    double getVolume()
    {
        return _h * Circle::getArea();
    }
    void show()
    {
        cout << "Figure: " << getName() << endl
             << "Radius: " << getRadius() << endl
             << "Height: " << getHeight() << endl
             << "Volume: " << getVolume() << endl
             << "Area: " << getArea() << endl
             << endl;
    }
};
void show(Figure &fig)
{
    fig.show();
}
void show(Figure *fig)
{
    fig->show();
}
void test0()
{
    Circle cirl1("circle1", 7.7);
    Cylinder cylin1("cylinder1", 4.5, 2.6);
    show(cirl1);
    show(cylin1);
    
    show(&cirl1);
    show(&cylin1);
}
int main()
{
    test0();
    return 0;
}