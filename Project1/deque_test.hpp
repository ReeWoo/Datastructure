
#pragma once
#include "measure_time.h"
#include "MyDeque.hpp"
#include <deque>
#include <random>
constexpr int TEST_CASE = 600;
template <typename T>
class CompareDeque
{
public:
	void measure_performance(MyDeque<T>& deque1, std::deque<T>& deque2)
	{

		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<T> dis(0, 99);
		std::uniform_int_distribution<int> dis2(0, 1);

		int test_size = TEST_CASE;
		MeasureTime mt("custom deque performance");
		MeasureTime mt2("std deque performance");

		mt.start();
		for (int i = 0; i < test_size; ++i)
		{
			if (dis2(gen) == 0)
				deque1.push_back(dis(gen));
			else
				deque1.push_front(dis(gen));
		}
		mt.end();

		mt2.start();
		for (int i = 0; i < test_size; ++i)
		{
			if (dis2(gen) == 0)
				deque2.push_back(dis(gen));
			else
				deque2.push_front(dis(gen));
		}
		mt2.end();


		mt.start();
		while (!deque1.empty())
		{
			if (dis2(gen) == 0)
				deque1.pop_back();
			else
				deque1.pop_front();
		}
		mt.end();


		mt2.start();
		while (!deque1.empty())
		{
			if (dis2(gen) == 0)
				deque2.pop_back();
			else
				deque2.pop_front();
		}
		mt2.end();
	}


	void push_random(MyDeque<T>& deque1, std::deque<T>& deque2)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<T> dis(0, 99);
		std::uniform_int_distribution<int> dis2(0, 1);

		int test_size = TEST_CASE;
		T value;
		for (int i = 0; i < test_size; ++i)
		{
			value = dis(gen);
			if (dis2(gen) == 0)
			{
				deque1.push_back(value);
				deque2.push_back(value);
			}
			else
			{
				deque1.push_front(value);
				deque2.push_front(value);
			}
		}
	}
	bool compare(MyDeque<T>& deque1, std::deque<T>& deque2)
	{
		deque1.clear();
		deque2.clear();
		push_random(deque1, deque2);
		if (deque1.size() != deque2.size())
			return false;
		T val1, val2;

		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<T> dis(0, 1);

		while (!deque1.empty() && !deque2.empty())
		{
			val1 = deque1.front();
			val2 = deque2.front();
			if (val1 != val2)
			{
				std::cout << "bad " << val1 << " " << val2 << std::endl;
				return false;
			}
			if (dis(gen) == 0)
			{
				deque1.pop_front();
				deque2.pop_front();
			}
			else
			{
				deque1.pop_back();
				deque2.pop_back();
			}
		}

		return true;
	}
};
