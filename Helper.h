#ifndef HELPER_H
#define HELPER_H

#define LOG_FILE_NAME "applog.txt"

#include <ctime>
#include <string>
#include <sstream>
#include <fstream>

namespace Helper
{
    template <class T>

    /**
    * Template string converter function
    */
    std::string toString(const T &);

    /**
    * Date time helper datatype
    */
    struct DateTime
    {
        int day;
        int month;
        int year;
        int hour;
        int minute;
        int second;

        /**
        * Default constructor
        */
        DateTime()
        {
            time_t ms;
            time(&ms);

            struct tm *info = localtime(&ms);

            day = info->tm_mday;
            month = info->tm_mon + 1;
            year = 1900 + info->tm_year;
            hour = info->tm_hour;
            minute = info->tm_min;
            second = info->tm_sec;
        }

        /**
        * Constructor for all attributes
        */
        DateTime(int day, int mon, int year, int hour, int min, int sec) : day(day), month(mon), year(year), hour(hour), minute(min), second(sec) {
        }

        /**
        * Date only constructor
        */
        DateTime(int day, int mon, int year) : day(day), month(mon), year(year), hour(0), minute(0), second(0) {
        }

        /**
        * Returns the current date time
        */
        DateTime now() const
        {
            return DateTime();
        }

        /**
        * Returns the date as a string
        */
        std::string getDateString() const
        {
            return
                std::string( day < 10 ? "0" : "" ) + toString(day) +
                std::string( month < 10 ? ".0" : ".") + toString(month) +
                toString(year);
        }

        /**
        * Returns the time as a string
        */
        std::string getTimeString(const std::string &sep = ":") const
        {
            return
                std::string( hour < 10 ? "0" : "" ) + toString(hour) + sep +
                std::string( minute < 10 ? "0" : "") + toString(minute) + sep +
                std::string( second < 10 ? "0" : "") + toString(second);
        }

        /**
        * Returns the whole date time as string
        */
        std::string getDateTimeString(const std::string &sep = ":") const
        {
            return getDateString() + " " + getTimeString(sep);
        }
    };

    template <class T>

    /**
    * String converter implementation
    */
    std::string toString(const T &input)
    {
        std::ostringstream s;
        s << input;

        return s.str();
    }

    /**
    * Writes the log
    */
    void writeLog(const std::string &s)
    {
        std::ofstream file(std::string(LOG_FILE_NAME), std::ios::app);

        file << "[" << Helper::DateTime().getDateTimeString() << "]" <<
        "\n" << s << std::endl << "\n";
        file.close();
    }
}

#endif // HELPER_H
