#include "Base64.h"

#include <string>

std::string Base64::encode(const std::string &s)
{
    std::string encoded;

    // Current bit stream
    int val = 0;

    // Current bits
    int bits = -6;

    // Bit mask to unmask the
    const unsigned int mask = 0x3F;

    // Loop over the given string
    for (const auto &c : s) {

        // Shift the eight bits and and the eight bits of the next char
        val = (val << 8) + c;

        // One char added: Add 8 to current bit counter
        bits += 8;

        while (bits >= 0) {

            // Calculate the index and push the
            // corresponding char into the encoded string.
            int index = (val >> bits) & mask;
            encoded.push_back(CHARPOOL[index]);

            // Reduce the current bits
            bits -= 6;
        }
    }

    // Unencoded bits left
    if (bits > -6) {
        int index = ((val << 8) >> (bits + 8));
        encoded.push_back(CHARPOOL[index]);
    }

    // Fill the encoded string
    while (encoded.size() %4) {
        encoded.push_back('=');
    }

    return encoded;
}
