
#pragma once
#include "measure_time.h"
#include "Heap.hpp"
#include <queue>
#include <random>
#include <iomanip>

constexpr int HEAP_TEST_CASE = 1000000;
template <typename T>
class CompareHeap
{
public:
	void measure_performance(Heap<T>& my_heap, std::priority_queue<T>& std_heap)
	{
		my_heap.clear();
		while (!std_heap.empty())
			std_heap.pop();

		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<T> dis(0, 999);

		int test_size = HEAP_TEST_CASE;
		MeasureTime mt("custom heap performance");
		MeasureTime mt2("std heap performance");


		long long custom_total = 0;
		long long std_total = 0;

		mt.start();
		for (int i = 0; i < test_size; ++i)
		{
			my_heap.push(dis(gen));
		}
		custom_total += mt.end();

		mt2.start();
		for (int i = 0; i < test_size; ++i)
		{
			std_heap.push(dis(gen));

		}
		std_total += mt2.end();


		mt.start();
		while (!my_heap.empty())
		{
			my_heap.pop();
		}
		custom_total += mt.end();


		mt2.start();
		while (!std_heap.empty())
		{
			std_heap.pop();
		}
		std_total += mt2.end();

		std::cout << "==============================================" << std::endl;
		std::cout << "custom total time : " << std::setw(10) << custom_total << " micro sec" << std::endl;
		std::cout << "   std total time : " << std::setw(10) <<  std_total << " micro sec" << std::endl;

	}


	void push_random(Heap<T>& my_heap, std::priority_queue<T>& std_heap)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<T> dis(0, 999);

		int test_size = HEAP_TEST_CASE;
		T value;
		for (int i = 0; i < test_size; ++i)
		{
			value = dis(gen);
			my_heap.push(value);
			std_heap.push(value);
		}
	}
	bool compare(Heap<T>& my_heap, std::priority_queue<T>& std_heap)
	{
		my_heap.clear();
		while (!std_heap.empty())
			std_heap.pop();
		//std_heap.clear();
		push_random(my_heap, std_heap);
		if (my_heap.size() != std_heap.size())
			return false;
		T val1, val2;

		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<T> dis(0, 1);

		while (!my_heap.empty() && !std_heap.empty())
		{
			val1 = my_heap.top();
			val2 = std_heap.top();
			if (val1 != val2)
			{
				std::cout << "bad " << val1 << " " << val2 << std::endl;
				return false;
			}
			my_heap.pop();
			std_heap.pop();
		}

		return true;
	}
};
