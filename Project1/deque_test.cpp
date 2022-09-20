#include "MyDeque.h"
#include "measure_time.h"
#include <deque>
#include <random>

template <typename T>
void measure_performance(MyDeque<T>& deque1, std::deque<T>& deque2)
{

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<T> dis(0, 99);
	std::uniform_int_distribution<int> dis2(0, 1);

	int test_size = 100000;
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

template <typename T>
bool compare(MyDeque<T>& deque1, std::deque<T>& deque2)
{
	if (deque1.size() != deque2.size())
		return false;
	T val1, val2;
	while (!deque1.empty() && !deque2.empty())
	{
		val1 = deque1.front();
		val2 = deque2.front();
		if (val1 != val2)
			return false;
		deque1.pop_front();
		deque2.pop_front();
	}

	return true;
}