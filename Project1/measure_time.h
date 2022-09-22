#pragma once

#include <iostream>
#include <chrono>
#include <string>
class MeasureTime
{
public:
	MeasureTime(const std::string &task);
	void start();
	void end();
private:
	std::chrono::time_point<std::chrono::steady_clock> m_time;
	std::string m_task;
};