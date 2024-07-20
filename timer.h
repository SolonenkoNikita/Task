#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <ctime>

class Timer
{
public:
    Timer();

    char* get_time();

private:

    void update();

    std::time_t time_;

};

#endif // TIMER_H
