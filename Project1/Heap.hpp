#pragma once
#include <iostream>

constexpr unsigned int MAX_SIZE = 100000;
template <typename T>
class Heap
{
public:
	Heap() : m_size(0), m_top(0), m_initial_size(64)
	{
		m_data = new T[m_initial_size];
	}
	~Heap()
	{
		delete[] m_data;
	}
	bool empty()
	{
		return m_size == 0 ? true : false;
	}
	int size()
	{
		return m_size;
	}
	T& top()
	{
		_STL_VERIFY(!this->empty(), "top() called on empty deque");
		return m_data[m_top];
	}
	void clear()
	{
		while (!empty())
		{
			pop();
		}
	}
	void top_down_heapify(int current_idx, int left, int right)
	{
		if (current_idx >= m_size || left >= m_size || right >= m_size)
			return;

		T temp;
		if (m_data[left] > m_data[right])
		{
			if (m_data[left] > m_data[current_idx])
			{
				temp = m_data[left];
				m_data[left] = m_data[current_idx];
				m_data[current_idx] = temp;
				current_idx = left;
				left = current_idx * 2 + 1;
				right = left + 1;
				top_down_heapify(current_idx, left, right);
			}
		}
		else
		{
			if (m_data[right] > m_data[current_idx])
			{
				temp = m_data[right];
				m_data[right] = m_data[current_idx];
				m_data[current_idx] = temp;
				current_idx = right;
				left = current_idx * 2 + 1;
				right = left + 1;
				top_down_heapify(current_idx, left, right);
			}
		}
	}
	void bottom_up_heapify()
	{
		int current_idx = m_size - 1;
		int parent_idx = current_idx % 2 == 0 ? current_idx / 2 - 1 : current_idx / 2;
		T temp;
		while (parent_idx >= 0)
		{
			if (m_data[parent_idx] < m_data[current_idx])
			{
				temp = m_data[parent_idx];
				m_data[parent_idx] = m_data[current_idx];
				m_data[current_idx] = temp;
			}
			else
			current_idx = parent_idx;
			parent_idx = current_idx % 2 == 0 ? current_idx / 2 - 1 : current_idx / 2;
		}

	}
	void push(const T& data)
	{
		if (m_size >= m_initial_size)
		{
			T* temp_data = new T[m_initial_size * 2];
			std::copy(m_data, m_data + m_initial_size, temp_data);
			delete[] m_data;
			m_data = temp_data;
			temp_data = nullptr;
			m_initial_size *= 2;
		}
		m_data[m_size] = data;
		++m_size;
		bottom_up_heapify();
	}
	void pop()
	{
		_STL_VERIFY(!this->empty(), "pop() called on empty deque");
		--m_size;
		m_data[m_top] = m_data[m_size];

		int current_idx = m_top;
		int left = current_idx * 2 + 1;
		int right = left + 1;
		top_down_heapify(current_idx, left, right);
		
	}
private:
	T *m_data;
	unsigned int m_top, m_initial_size;
	int m_size;
};