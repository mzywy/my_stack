#pragma once
#include<iostream>
#include<vector>

template<class T>
class Mystack
{
public:
	Mystack();
	Mystack(T arr[], int n);
	Mystack(std::vector<T> arr);
	~Mystack();
	int size();
	bool push(T ele);
	bool pop();
	T top();
	bool isempty();

	class iterator
	{
	public:
		iterator()
		{
			p = nullptr;
		}
		iterator(T* k)
		{
			p = k;
		}
		void operator = (Mystack<T>::iterator k)
		{
			p = k.p;
		}
		bool operator < (const Mystack<T>::iterator k)
		{
			return p < k.p;
		}
		void operator ++(int)
		{
			p++;
		}
		T operator [](int n)//判断有没有超过范围
		{
			if (p + n >= end())return data[0];
			return p[n];
		}

		T operator *()
		{
			return *p;
		}
	private:
		T* p;
	};

	Mystack<T>::iterator start()
	{
		return Mystack<T>::iterator(&data[0]);
	}
	Mystack<T>::iterator end()
	{
		return Mystack<T>::iterator(&data[len]);
	}
private:
	T* data;
	int len;
	int maxsize;
	const int more_mem = 100;
};