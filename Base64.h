#ifndef BASE64_H
#define BASE64_H

#include <vector>
#include <string>

namespace Base64
{
    const std::string CHARPOOL = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz/+";

    std::string encode(const std::string &);
}

#endif // BASE64_H
