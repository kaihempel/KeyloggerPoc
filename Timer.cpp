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
        timerThread = std::thread(threadHandler, this);

    } else {
        this->threadHandler();
    }
}

void Timer::stop()
{
    alive = false;
    timerThread.join();
}
