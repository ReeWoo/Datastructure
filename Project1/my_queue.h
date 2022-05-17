#pragma once
#pragma once
#include <iostream>



template <typename T>
class Queue
{
public:
	Queue();
	void push(const T& data);
	void push(T* data);
	void pop();
	T& front();
private:
	static constexpr unsigned int SIZE = 15;
	unsigned char m_index;
	unsigned char m_top;
	T m_data[SIZE];
};

template <typename T>
Queue<T>::Queue()
{
	this->m_index = 0;
	this->m_top = 0;
}

template <typename T>
void Queue<T>::push(const T& data)
{

	this->m_data[m_index] = data;
	if (++m_index == SIZE) m_index = 0;
}

template <typename T>
void Queue<T>::push(T* data)
{

	this->m_data[m_index] = data;
	if (++m_index == SIZE) m_index = 0;
}

template <typename T>
void Queue<T>::pop()
{
	if (++m_top == SIZE) m_top = 0;
}

template <typename T>
T& Queue<T>::front()
{
	return this->m_data[m_top];
}
