#ifndef IO_H
#define IO_H

#include <string>
#include <cstdlib>
#include <fstream>
#include "windows.h"

#include "Helper.h"
#include "Base64.h"

namespace IO
{
    std::string getOurPath(const bool append_separator);

    bool mkOneDir(std::string path);

    bool mkDir(std::string path);

    template <class T>
    std::string writeLog(const T &message);
}

#endif // IO_H
