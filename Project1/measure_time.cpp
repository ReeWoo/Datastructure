#include "measure_time.h"

MeasureTime::MeasureTime(const std::string& task)
{
	m_task = task;
}

void MeasureTime::start()
{
	m_time = std::chrono::steady_clock::now();
}

void MeasureTime::end()
{
	auto sec = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - m_time);
	std::cout << m_task + "time : " << sec.count() << " micro sec" << std::endl;
}