#include"mstack.h"

template<class T>
Mystack<T>::Mystack()
{
	this->data = nullptr;
	len = 0;
	maxsize = 0;
}

template<class T>
Mystack<T>::Mystack(T arr[],int n)
{
	this->data = new T[n];
	if (data == nullptr)
	{
		exit(0);
	}
	for (int i = 0; i < n; i++)
	{
		data[i] = arr[i];
	}
	len = n;
	maxsize = n;
}

template<class T>
Mystack<T>::Mystack(std::vector<T> v)
{
	this->data = new T[v.size()];
	if (data == nullptr)
	{
		exit(0);
	}
	for (int i = 0; i < v.size(); i++)
	{
		data[i] = v[i];
	}
	len = v.size();
	maxsize = v.size();
}


template<class T>
Mystack<T>::~Mystack()
{
	delete[] data;
	len = 0;
	maxsize = 0;
}


template<class T>
int Mystack<T>::size()
{
	return len;
}

template<class T>
bool Mystack<T>::push(T ele)
{
	if (data == nullptr)
	{
		data = new T[more_mem];
		if (data == nullptr)return false;
		maxsize = more_mem;
		data[0] = ele;
		len = 1;
		return true;
	}
	if (len >= maxsize)
	{
		T* temp = new T[maxsize + more_mem];
		if (temp == nullptr)return false;
		memcpy(temp, data, sizeof(T)*maxsize);
		delete[] data;
		data = temp;
		maxsize += more_mem;
		data[len++] = ele;
		return true;
	}
	data[len++] = ele;
	return true;
}

template<class T>
bool Mystack<T>::pop() 
{
	if (isempty())return false;
	len--;
	return true;
}

template<class T>
T Mystack<T>::top()
{
	return data[len - 1];
}

template<class T>
bool Mystack<T>::isempty()
{
	return len==0;
}