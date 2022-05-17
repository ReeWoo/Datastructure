
#include "my_queue.h"
#include <time.h>
#include <chrono>
#include <queue>
#include <vector>
class my_type
{
public:
	my_type()
	{

	}
	my_type(int a, int b)
	{
		a = a;
		b = b;
	}
	int a, b;
private:

};

int main()
{
	Queue<my_type> que;
	std::queue<my_type> std_que;
	std::vector<my_type> std_vec;
	srand(time(NULL));
	int times = 10000000;
	int temp_val = 0;
	int max = times;
	int val;

	my_type tmp(0, 0);
	my_type tmp1;
	

	auto start = std::chrono::steady_clock::now();
	
	for (int i = 0; i < max; ++i)
	{
		tmp.a = rand() % 100;
		tmp.b = rand() % 100;
		que.push(tmp);
		tmp1 = que.front();
		que.pop();
	}
	auto end = std::chrono::steady_clock::now();

	std::cout << "nanoseconds: " << std:: chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << " ms" << std::endl;
		
	

	auto start2 = std::chrono::steady_clock::now();
	for (int i = 0; i < max; ++i)
	{
		tmp.a = rand() % 100;
		tmp.b = rand() % 100;
		std_que.push(tmp);
		tmp1 = std_que.front();
		std_que.pop();
	}
	auto end2 = std::chrono::steady_clock::now();

	std::cout << "std queue nanoseconds: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - start2).count() << " ms" << std::endl;

	auto start3 = std::chrono::steady_clock::now();
	for (int i = 0; i < max; ++i)
	{
		tmp.a = rand() % 100;
		tmp.b = rand() % 100;
		std_vec.push_back(tmp);
		tmp1 = std_vec.front();
		std_vec.erase(std_vec.begin());
	}
	auto end3 = std::chrono::steady_clock::now();

	std::cout << "std vec nanoseconds: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end3 - start3).count() << " ms" << std::endl;
	
	

	return 0;
}