#include "timer.h"

Timer::Timer()
{
    update();
}

char* Timer::get_time()
{
    update();
    return std::ctime(&time_);
}

void Timer::update()
{
    auto end = std::chrono::system_clock::now();
    time_ = std::chrono::system_clock::to_time_t(end);
}
