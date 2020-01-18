#ifndef TIMER_H
#define TIMER_H

#include <thread>
#include <chrono>


class Timer
{
    std::thread timerThread;
    bool alive = false;
    long callNumber = -1L;
    long repeatCount = -1L;
    std::chrono::milliseconds interval = std::chrono::milliseconds(0);
    std::function<void(void)> functPtr = nullptr;

    void sleepAndRun();

    void threadHandler();

public:
    static const long infinite = -1L;

    Timer() {}

    Timer(const std::function<void(void)> &f) : functPtr(f) {}

    Timer(
          const std::function<void(void)> &f,
          const unsigned long &i,
          const long repeat = Timer::infinite
    ) : functPtr(f), interval(std::chrono::milliseconds(i)), callNumber(repeat) {}

    bool isAlive();
    void start(bool async);
    void stop();
}

#endif // TIMER_H
