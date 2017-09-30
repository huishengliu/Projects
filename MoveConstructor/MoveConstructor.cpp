// MoveConstructor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

using namespace std;

template<class T>
class A
{
public:
	A(T* t)
	{
		m_t = t;
		cout << "Ctor 1: " << this << endl;
	}

	A(A& a)
	{
		m_t = a.m_t;
		cout << "Ctor 2: " << this << endl;
	}

	A(A&& a)
	{
		m_t = a.m_t;
		a.m_t = 0;
		cout << "Ctor 3: " << this << endl;
	}

	~A()
	{
		cout << "Dtor: " << this << endl;
	}

	void Print()
	{
		cout << this << endl;
	}

private:
	T* m_t;
};

int g = 10;
A<int> GetA()
{
	A<int> a(&g);

	return std::move(a);
}

int main()
{
	A<int> b(GetA());
	b.Print();
    return 0;
}

