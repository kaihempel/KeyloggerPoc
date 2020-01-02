#include "Helper.h"

#include <ctime>
#include <string>
#include <sstream>
#include <fstream>

template <class T>
/**
* String converter implementation
*/
std::string Helper::toString(const T &input)
{
    std::ostringstream s;
    s << input;

    return s.str();
}

/**
* Writes the log
*/
void Helper::writeLog(const std::string &s)
{
    std::ofstream file(std::string(LOG_FILE_NAME), std::ios::app);

    file << "[" << Helper::DateTime().getDateTimeString() << "]" <<
    "\n" << s << std::endl << "\n";
    file.close();
}
