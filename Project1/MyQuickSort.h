#pragma once
#include <vector>

template <typename T>
void custom_quicksort(T* arr, int start, int end)
{
	if (start >= end) return;
	int left = start - 1;
	int right = end + 1;
	T pivot = arr[(left + right) / 2];
	T temp;
	while (true)
	{
		while (arr[++left] < pivot);
		while (arr[--right] > pivot);
		if (left >= right) break;
		temp = arr[left];
		arr[left] = arr[right];
		arr[right] = temp;
	
	}
	custom_quicksort(arr, start, left - 1);
	custom_quicksort(arr, right + 1, end);
}