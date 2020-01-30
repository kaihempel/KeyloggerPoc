#include "Timer.h"

#include <thread>
#include <chrono>

void Timer::sleepAndRun()
{
    std::this_thread::sleep_for(interval);

    if (alive) {
       handler()();
    }
}

void Timer::threadHandler()
{
    if (callNumber == Timer::infinite) {
        while (alive) sleepAndRun();
    } else {
        while (repeatCount--) sleepAndRun();
    }
}

bool Timer::isAlive()
{
    return alive;
}

void Timer::start(bool async = true)
{
    if (isAlive()) {
        return;
    }

    alive = true;
    repeatCount = callNumber;

    if (async) {
        timerThread = std::thread(&Timer::threadHandler, this);

    } else {
        this->threadHandler();
    }
}

void Timer::stop()
{
    alive = false;
    timerThread.join();
}

void Timer::setThreadCallbackFunction(const std::function<void(void)>& f)
{
    functPtr = f;
}

void Timer::setRepeatCount(const long repeat)
{
    if (isAlive()) {
        return;
    }

    callNumber = repeat;
}

long Timer::getLeftCount() const
{
    return repeatCount;
}

long Timer::getCallNumber() const
{
    return callNumber;
}

void Timer::setInterval(const unsigned long& i)
{
    if (isAlive()) {
        return;
    }

    interval = std::chrono::milliseconds(i);
}

unsigned long Timer::getInterval() const
{
    return interval.count();
}

const std::function<void(void)>& Timer::handler() const
{
    return functPtr;
}