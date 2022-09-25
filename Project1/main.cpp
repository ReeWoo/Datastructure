#include <deque>
#include <iostream>
#include "MyDeque.hpp"
#include "deque_test.hpp"
#include "Heap.hpp"
#include <queue>
#include "heap_test.h"
int main()
{
	CompareDeque<int> cd;
	CompareHeap<int> ch;
	cd.main();
	ch.main();

	
	return 0;
}