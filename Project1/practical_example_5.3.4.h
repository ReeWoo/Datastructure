#pragma once
#include <iomanip>
class Task
{
public:
	Task() : m_id(-1), m_start_time(-1), m_end_time(-1) {} 
	Task(int id, int start_time, int end_time)
	{
		m_id = id;
		m_start_time = start_time;
		m_end_time = end_time;
	}

	friend bool operator==(const Task& str, const Task& str2) {
		return (str.m_id == str2.m_id && str.m_end_time == str2.m_end_time && str.m_start_time == str2.m_start_time);
	}

	void problem_main();

	friend std::ostream& operator << (std::ostream& out, const Task& task)
	{
		out << "( id : " << task.m_id << ", s : " << std::setw(4) << task.m_start_time << ", e : " << std::setw(4) << task.m_end_time << " )";

		return out;
	}

	int m_id, m_start_time, m_end_time;
private:

};