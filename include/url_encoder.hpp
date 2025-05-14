#pragma once

#include <string>
#include <stdexcept>

class UrlEncoder {
public:
    // Encode functions
    static std::string encode(const std::string& input);
    static std::string encode(const char* input);
    static std::string encode(const char* input, size_t length);

    // Decode functions
    static std::string decode(const std::string& input);
    static std::string decode(const char* input);
    static std::string decode(const char* input, size_t length);

private:
    static bool isUrlSafe(char c);
    static char hexToChar(const char* hex);
    static std::string charToHex(char c);
}; 