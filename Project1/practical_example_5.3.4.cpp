#include <iostream>
#include <list>
#include <algorithm>
#include "practical_example_5.3.4.h"
#include <functional>

int min_end_time;

bool compare(const Task& task1, const Task& task2)
{
	if (task1.m_end_time == task2.m_end_time)
		return task1.m_end_time > task2.m_end_time;
	return task1.m_end_time < task2.m_end_time;
}


bool remove_check(const Task& task)
{
	if (task.m_start_time < min_end_time)
		return true;
	return false;
}

int MAX_TASK = 20;
void print_tasks(const std::list<Task>& task)
{
	for (auto it = task.begin(); it != task.end(); ++it)
	{
		std::cout << "[ " << std::setw(3) << it->m_id << " ] " << std::setw(3) << it->m_start_time << " -> " << std::setw(3) << it->m_end_time << " |";
		for (int i = 0; i < it->m_start_time; ++i)
			std::cout << " ";
		for (int i = it->m_start_time; i < it->m_end_time; ++i)
			std::cout << "*";
		for (int i = it->m_end_time; i < MAX_TASK; ++i)
			std::cout << " ";
		std::cout << "|" << std::endl;
	}
	std::cout << std::endl;
}

std::list<Task> solution(const std::list<Task> &tasks)
{
	std::list<Task> tmp_tasks = tasks;
	std::list<Task> result;

	std::cout << " [ 전체 작업 ] " << std::endl;
	print_tasks(tmp_tasks);

	tmp_tasks.sort(compare);
	
	while (!tmp_tasks.empty())
	{
		result.push_back(tmp_tasks.front());
		min_end_time = tmp_tasks.front().m_end_time;
		tmp_tasks.remove(tmp_tasks.front());
		tmp_tasks.remove_if(remove_check);
	}

	std::cout << " [ 스케쥴 조정한 작업 ] " << std::endl;
	print_tasks(result);

	return result;
}

void Task::problem_main()
{
	std::cout << "\n=============================================" << std::endl;
	std::cout << "=============== 실습문제 5.3.4 ===============" << std::endl;
	std::cout << "=============================================\n" << std::endl;


	std::list<Task> tasks;
	
	tasks.push_back(Task(1, 5, 9));
	tasks.push_back(Task(2, 6, 20));
	tasks.push_back(Task(3, 16, 19));
	tasks.push_back(Task(4, 7, 10));
	tasks.push_back(Task(5, 9, 19));
	tasks.push_back(Task(6, 10, 19));
	tasks.push_back(Task(7, 6, 12));
	tasks.push_back(Task(8, 2, 17));
	tasks.push_back(Task(9, 10, 13));
	tasks.push_back(Task(10, 4, 7));

	solution(tasks);
}