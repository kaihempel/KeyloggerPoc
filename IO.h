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
    std::string getOurPath(const bool append_separator = false);

}

#endif // IO_H
