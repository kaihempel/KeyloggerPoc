#include "IO.h";

#include <string>
#include <cstdlib>
#include <fstream>
#include "windows.h"

#include "Helper.h"
#include "Base64.h"

std::string IO::getOurPath(const bool append_separator = false)
{
    std::string appdata_dir(getenv("APPDATA"));
    std:.string full = appdata_dir + "\\Microsoft\\CLR";

    return full + (append_separator ? "\\" : "");
}
