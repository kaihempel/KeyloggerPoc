#ifndef TIMER_H
#define TIMER_H

#include <thread>
#include <chrono>
#include <functional>

/**
* Timer class
*/
class Timer
{
    /**
    * Thread for the timer jobs
    */
    std::thread timerThread;

    /**
    * Status of the timer thread
    */
    bool alive = false;
    long callNumber = -1L;
    long repeatCount = -1L;

    /**
    * Thread interval
    */
    std::chrono::milliseconds interval = std::chrono::milliseconds(0);

    /**
    * Callback function for the thread
    */
    std::function<void(void)> functPtr = nullptr;

    /**
    * Executes the thread
    */
    void sleepAndRun();

    /**
    * Main thread handler method
    */
    void threadHandler();

public:
    static const long infinite = -1L;

    Timer() {}

    Timer(const std::function<void(void)>& f) : functPtr(f) {}

    Timer(
        const std::function<void(void)>& f,
        const unsigned long& i,
        const long repeat = Timer::infinite
    ) : functPtr(f), interval(std::chrono::milliseconds(i)), callNumber(repeat) {}

    /**
    * Returns the alive flag
    */
    bool isAlive();

    /**
    * Starts the thread
    */
    void start(bool async);

    /**
    * Stops the thread
    */
    void stop();

    /**
    * Sets the callback handler function
    */
    void setThreadCallbackFunction(const std::function<void(void)>& f);

    /**
    * Sets the repeate count
    */
    void setRepeatCount(const long repeat);

    /**
    * Return the current repeat count
    */
    long getLeftCount() const;

    /**
    * Returns the numbers of successful executions
    */
    long getCallNumber() const;

    /**
    * Sets a interval value in milliseconds
    */
    void setInterval(const unsigned long& i);

    /**
    * Returns the current interval
    */
    unsigned long getInterval() const;

    /**
    * Returns the thread callback function
    */
    const std::function<void(void)>& handler() const;
};

#endif // TIMER_H
