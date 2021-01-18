/*
 * @Author: your name
 * @Date: 2020-01-20 19:58:15
 * @LastEditTime : 2020-01-20 20:41:24
 * @LastEditors  : Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \VS-Code-C++\20200120\templatequeue.cc
 */
#include <iostream>

using std::cout;
using std::endl;
using std::cerr;

template <class T, int kMax = 100>
class Myqueue
{
public:
	Myqueue()
		: _front(-1)
		,_rear(0)
		, _base(new T[kMax]) {}
	~Myqueue()
	{
		if (_base)
			delete[] _base;
	}

public:
	bool empty() const
	{
		if ((_front + 1 - _rear + kMax) % kMax == 0)
			return true;
		else
			return false;
	}
	bool full() const
	{
		if ((_front + 2 - _rear + kMax) % kMax == 0)
			return true;
		else
			return false;
	}
	void push(T t)
	{
		if (!full())
		{
			_base[(++_front) % kMax] = t;
		}
		else cerr << "queue is full,push error. " << endl;
	}
	void pop()
	{
		if (!empty())
			++_rear;
		else cerr << "queue is empty,pop error. " << endl;
	}

	T front()
	{
		return _base[_front];
	}

	T back()
	{
		return _base[_rear];
	}

private:
	T* _base;
	size_t _front;
	size_t _rear;
};


void test()
{
	Myqueue<int> test1;
	test1.push(0);
	test1.push(1);
	test1.push(2);
	test1.push(3);
	test1.pop();
	cout << "test1.front()" << test1.front() << endl;
	cout << "test1.back()" << test1.back() << endl;
}
int main()
{
	test();
	return 0;
}