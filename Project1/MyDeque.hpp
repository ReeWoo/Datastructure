#pragma once
#include <iostream>



template <typename T>
class MyDeque
{
public:
	MyDeque() : DATA_BLOCK_SIZE(64), CHUNK_BLOCK_SIZE(32), VACCANCY_TERM(3), m_size(0), m_data_start(-1), m_data_end(-1)/*, m_start(VACCANCY_TERM), m_end(VACCANCY_TERM)*/
	{
		m_start = VACCANCY_TERM;
		m_end = VACCANCY_TERM;

		m_data = new T*[CHUNK_BLOCK_SIZE];
		for (int i = 0; i < CHUNK_BLOCK_SIZE; ++i)
			m_data[i] = nullptr;
		m_data[m_start] = new T[DATA_BLOCK_SIZE];
		m_head = m_data[m_start];
		m_tail = m_data[m_start];
	}
	~MyDeque()
	{
		for (int i = 0; i < CHUNK_BLOCK_SIZE; ++i)
		{
			if (m_data[i] != nullptr)
			{	
				delete[] m_data[i];
				m_data[i] = nullptr;
			}
			
		}
		if (m_data != nullptr)
			delete[] m_data;
		m_data = nullptr;
	}
	int size()
	{
		return m_size;
	}
	void clear()
	{
		while (!empty())
		{
			pop_back();
		}
		m_data_start = -1;
		m_data_end = -1;
		m_start = VACCANCY_TERM;
		m_end = VACCANCY_TERM;

	}
	bool empty()
	{
		return m_size == 0 ? true : false;
	}
	T& front()
	{
	
		_STL_VERIFY(!empty(), "front() called on empty deque");

		return m_head[m_data_start];
	}
	T& back()
	{
		_STL_VERIFY(!empty(), "back() called on empty deque");
		return m_tail[m_data_end];
	}
	void pop_front()
	{
		if (empty())
			return;
		++m_data_start;
		if (m_data_start == DATA_BLOCK_SIZE)
		{
			m_data_start = 0;
			++m_start;
			if (m_start > m_end)
				m_start = m_end;
			m_head = m_data[m_start];

		}
		--m_size;

	}
	void pop_back()
	{
		if (empty())
			return;
		--m_data_end;
		if (m_data_end == -1)
		{
			m_data_end = DATA_BLOCK_SIZE - 1;
			--m_end;
			if (m_start > m_end)
				m_end = m_start;
			m_tail = m_data[m_end];
		}
		--m_size;
		
	}
	void push_back(const T& data)
	{
	
		if (m_data_end == DATA_BLOCK_SIZE - 1)
		{
			++m_end;
			m_data_end = -1;
			if (m_end >= CHUNK_BLOCK_SIZE)
			{
				
				T** temp_chunk = new T * [CHUNK_BLOCK_SIZE * 2];
				VACCANCY_TERM *= 2;
				for (int i = 0; i < VACCANCY_TERM / 2; ++i)
					temp_chunk[i] = nullptr;
				for (int i = VACCANCY_TERM / 2; i < CHUNK_BLOCK_SIZE + VACCANCY_TERM / 2; ++i)
					temp_chunk[i] = new T[DATA_BLOCK_SIZE];
				for (int i = CHUNK_BLOCK_SIZE + VACCANCY_TERM / 2; i < CHUNK_BLOCK_SIZE * 2; ++i)
					temp_chunk[i] = nullptr;
				for (int i = m_start; i < m_end; ++i)
					std::copy(&m_data[i][0], &m_data[i][0] + DATA_BLOCK_SIZE, &temp_chunk[VACCANCY_TERM / 2+ i - m_start][0]);
				for (int i = 0; i < CHUNK_BLOCK_SIZE; ++i)
				{
					if (m_data[i] != nullptr)
					{
						delete[] m_data[i];
						m_data[i] = nullptr;
					}
				}
				delete[] m_data;
				m_data = temp_chunk;
				//temp_chunk = nullptr;
				m_end = m_end - m_start + VACCANCY_TERM / 2;
				m_start = VACCANCY_TERM / 2;
				//m_end = CHUNK_BLOCK_SIZE + VACCANCY_TERM;
				CHUNK_BLOCK_SIZE *= 2;
			}
		}
		try
		{
			if (m_data[m_end] == nullptr)
				m_data[m_end] = new T[DATA_BLOCK_SIZE];
		}
		catch (std::bad_alloc& ba)
		{
			std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
		}

		//std::cout << m_end << " " << m_data_end << std::endl;
		m_data[m_end][++m_data_end] = data;
		
		if (m_data_start == -1)
		{
			m_data_start = m_data_end;
		}
		
		++m_size;
		m_tail = m_data[m_end];
		
	}
	void push_front(const T& data)
	{		
		if (m_data_start == 0)
		{
			--m_start;
			m_data_start = DATA_BLOCK_SIZE;
			if (m_start == -1)
			{
				VACCANCY_TERM *= 2;
				T** temp_chunk = new T * [CHUNK_BLOCK_SIZE * 2];
				/*VACCANCY_TERM *= 2;*/
				for (int i = 0; i < VACCANCY_TERM / 2; ++i)
					temp_chunk[i] = nullptr;
				for (int i = VACCANCY_TERM / 2; i < CHUNK_BLOCK_SIZE + VACCANCY_TERM / 2; ++i)
					temp_chunk[i] = new T[DATA_BLOCK_SIZE];
				for (int i = CHUNK_BLOCK_SIZE + VACCANCY_TERM / 2; i < CHUNK_BLOCK_SIZE * 2; ++i)
					temp_chunk[i] = nullptr;
				for (int i = 0; i <= m_end; ++i)
					std::copy(&m_data[i][0], &m_data[i][0] + DATA_BLOCK_SIZE, &temp_chunk[VACCANCY_TERM / 2+ i][0]);
				for (int i = 0; i < CHUNK_BLOCK_SIZE; ++i)
				{
					if (m_data[i] != nullptr)
					{
						delete[] m_data[i];
						m_data[i] = nullptr;
					}
				}
				delete[] m_data;
				m_data = temp_chunk;
				//temp_chunk = nullptr;
				CHUNK_BLOCK_SIZE *= 2;
				m_end = m_end - m_start - 1 + VACCANCY_TERM / 2;
				m_start = VACCANCY_TERM / 2 - 1;
				
			}
		}
		try
		{
			if (m_data[m_start] == nullptr)
				m_data[m_start] = new T[DATA_BLOCK_SIZE];
		}
		catch (std::bad_alloc& ba)
		{
			std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
		}
		
		if (m_data_start == -1) m_data_start = 1;
		m_data[m_start][--m_data_start] = data;
		
		if (m_data_end == -1)
		{
			m_data_end = m_data_start;
		}
		
		++m_size;
		m_head = m_data[m_start];

	}
	int m_size, m_start, m_end, m_data_start, m_data_end;
private:
	
	T* m_head, *m_tail;
	T** m_data;

	int DATA_BLOCK_SIZE = 64;
	int CHUNK_BLOCK_SIZE = 10;
	int VACCANCY_TERM = 3;


};