
#pragma once
#include "measure_time.h"
#include "MyQuickSort.h"
#include <algorithm>
#include <random>
#include <iomanip>

constexpr int SORT_TEST_CASE = 1000000;
template <typename T>
class CompareSort
{
public:
	void main()
	{
		std::cout << "\n=============================================" << std::endl;
		std::cout << "========== custom quick sort VS std sort ==========" << std::endl;
		std::cout << "=============================================\n" << std::endl;


		compare() == 1 ? std::cout << "\n *** 일치 여부 테스트 통과 *** \n" << std::endl : std::cout << "\n *** 일치 여부 테스트 실패 *** \n" << std::endl;
		measure_performance();
	}

	void measure_performance()
	{

		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<T> dis(0, 999);

		int test_size = SORT_TEST_CASE;
		MeasureTime mt("custom quick sort performance");
		MeasureTime mt2("std sort performance");


		long long custom_total = 0;
		long long std_total = 0;
		
		T val;
		std::vector<T> my_vec, std_vec;
		for (int i = 0; i < test_size; ++i)
		{
			val = dis(gen);
			my_vec.push_back(val);
			std_vec.push_back(val);
		}

		mt.start();
		custom_quicksort(my_vec.data(), 0, my_vec.size() - 1);
		custom_total += mt.end();

		mt2.start();
		std::sort(std_vec.begin(), std_vec.end());
		std_total += mt2.end();

		std::cout << "==============================================" << std::endl;
		std::cout << "custom total time : " << std::setw(10) << custom_total << " micro sec" << std::endl;
		std::cout << "   std total time : " << std::setw(10) << std_total << " micro sec" << std::endl;

	}


	void push_random(std::vector <T>& my_vec, std::vector<T>& std_vec)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<T> dis(0, 999);

		T value;
		for (int i = 0; i < SORT_TEST_CASE; ++i)
		{
			value = dis(gen);
			my_vec.push_back(value);
			std_vec.push_back(value);
		}
	}
	bool compare()
	{
		std::vector<T> my_vec, std_vec;
		push_random(my_vec, std_vec);
		if (my_vec.size() != std_vec.size())
			return false;
		T val1, val2;
		std::cout << "random push complete" << std::endl;
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<T> dis(0, 1);
		custom_quicksort(my_vec.data(), 0, my_vec.size() - 1);
		std::sort(std_vec.begin(), std_vec.end());
		for(int i = 0; i < my_vec.size(); ++i)
		{
			val1 = my_vec[i];
			val2 = std_vec[i];
			if (val1 != val2)
			{
				std::cout << "bad " << val1 << " " << val2 << std::endl;
				return false;
			}
		}

		return true;
	}
};
