#include <deque>
#include <iostream>
#include "MyDeque.hpp"
#include "deque_test.hpp"
int main()
{
	MyDeque<int> mdq;
	std::deque<int> dq;
	
	CompareDeque<int> cd;
	std::cout << cd.compare(mdq, dq) << std::endl;
	mdq.clear();
	dq.clear();
	//cd.measure_performance(mdq, dq);
	return 0;
}