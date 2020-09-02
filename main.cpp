#include"mstack.h"
#include"mstack.cpp"
#include<iostream>
using namespace std;

void test_int()
{
	Mystack<int> ms;
	for (int i = 0; i < 2002; i++)
	{
		ms.push(i);
	}

	while (!ms.isempty())
	{
		cout << ms.top() << endl;
		ms.pop();
	}
}

void test_intarr()
{
	int a[100];
	for (int i = 0; i < 100; i++)
	{
		a[i] = i;
	}
	Mystack<int> ms(a,100);
	ms.push(100000);
	while (!ms.isempty())
	{
		cout << ms.top() << endl;
		ms.pop();
	}
}

void test_vector()
{
	vector<int> a;
	for (int i = 0; i < 102; i++)
	{
		a.push_back(i);
	}
	Mystack<int> ms(a);
	ms.push(100000);
	while (!ms.isempty())
	{
		cout << ms.top() << endl;
		ms.pop();
	}
}

void test_iterator()
{
	Mystack<int> ms;
	for (int i = 0; i < 2002; i++)
	{
		ms.push(i);
	}

	Mystack<int>::iterator p,q;
	for (p = ms.start(), q = ms.end(); p < q; p++)
	{
		cout << *p << endl;
	}
}

int main()
{
	//test_int();
	//test_intarr();
	//test_vector();
	test_iterator();
	return 0;
}