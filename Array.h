#ifndef __ARRAY_H
#define __ARRAY_H

#include "MainHeader.h"

template<class T>
class Array
{
public:
	void setDelimiter(char delimiter){m_delimiter = delimiter;}
	int getLogicalSize() const {return m_logical_Size;}
	int getPhsicalSize() const {return m_physical_Size;}
	char getDelimiter() const { return m_delimiter; }

	T& operator[](int index){return this->m_arr[index]; }
	const Array& operator=(const Array & other)
	{
		if (this != &other)
		{
			delete[] m_arr;
			m_physical_Size = other.m_physical_Size;
			m_logical_Size = other.m_logical_Size;
			m_delimiter = other.m_delimiter;
			m_arr = new T[m_physical_Size];
			for (int i = 0; i < m_logical_Size; i++)
				m_arr[i] = other.m_arr[i];
		}
		return *this;
	}
	const Array& operator+=(const T& newVal)
	{
		if (m_logical_Size < m_physical_Size)
			m_arr[m_logical_Size++] = newVal;
		else
		{
			auto newArr = new T[m_physical_Size * 2];
			this->m_physical_Size = m_physical_Size * 2;
			for (int i = 0; i < m_logical_Size; i++)
				newArr[i] = m_arr[i];
			newArr[m_logical_Size++] = newVal;
			delete[] m_arr;
			m_arr = newArr;
		}
		return *this;
	}
	friend ostream& operator<<(ostream& os, const Array& arr)
	{
		for (int i = 0; i < m_arr.m_logical_Size; i++)
			os << arr.arr[i] << arr.m_delimiter;
		return os;
	}

	Array(int maxSize = 2, char delimiter = ' ')
	{
		m_physical_Size = maxSize;
		m_logical_Size = 0;
		m_delimiter = delimiter;
		m_arr = new T[m_physical_Size];
	}
	Array(const Array & other) : m_arr(nullptr)
	{
		*this = other;
	}
	~Array();

private:
	int m_physical_Size, m_logical_Size;
	char m_delimiter;
	T* m_arr;
};

template<class T>
Array<T>::~Array()
{
	delete[] m_arr;
}
#endif // !__ARRAY_H