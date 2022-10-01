#include <deque>
#include <iostream>
#include "MyDeque.hpp"
#include "deque_test.hpp"
#include "Heap.hpp"
#include <queue>
#include "heap_test.h"
#include "practical_example_5.3.4.h"
//#include "MyQuickSort.h"
#include "quick_sort_test.h"

int main()
{
	Task task;
	task.problem_main();
	CompareDeque<int> cd;
	CompareHeap<int> ch;
	cd.main();
	ch.main();

	CompareSort<int> cs;
	cs.main();
	
	return 0;
}