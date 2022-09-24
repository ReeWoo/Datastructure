#include <deque>
#include <iostream>
#include "MyDeque.hpp"
#include "deque_test.hpp"
#include "Heap.hpp"
#include <queue>
#include "heap_test.h"
int main()
{
	//MyDeque<int> mdq;
	//std::deque<int> dq;
	//
	//CompareDeque<int> cd;
	////std::cout << cd.compare(mdq, dq) << std::endl;
	//mdq.clear();
	//dq.clear();
	//std::cout << mdq.m_start << " " << mdq.m_end << std::endl;
	//cd.measure_performance(mdq, dq);

	std::cout << "\n=============================================" << std::endl;
	std::cout << "========== custom heap VS std heap ==========" << std::endl;
	std::cout << "=============================================\n" << std::endl;

	std::priority_queue<int> pq;
	Heap<int> h;
	std::cout << "datatype std size : " << sizeof(pq) << " custom size : " << sizeof(h) << std::endl;
	CompareHeap<int> ch;
	ch.compare(h, pq) == 1 ? std::cout << "\n *** 일치 여부 테스트 통과 *** \n" << std::endl : std::cout << "\n *** 일치 여부 테스트 실패 *** \n" << std::endl;


	ch.measure_performance(h, pq);


	return 0;
}