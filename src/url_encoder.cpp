#include "url_encoder.hpp"
#include <algorithm>
#include <cctype>
#include <sstream>
#include <iomanip>
#include <vector>

bool UrlEncoder::isUrlSafe(char c) {
    return std::isalnum(static_cast<unsigned char>(c)) || c == '-' || c == '_';
}

std::string UrlEncoder::charToHex(char c) {
    std::stringstream ss;
    ss << '%' << std::uppercase << std::setw(2) << std::setfill('0') 
       << std::hex << static_cast<int>(static_cast<unsigned char>(c));
    return ss.str();
}

char UrlEncoder::hexToChar(const char* hex) {
    char hexStr[3] = {hex[0], hex[1], '\0'};
    int value;
    std::stringstream ss;
    ss << std::hex << hexStr;
    ss >> value;
    return static_cast<char>(value);
}

std::string UrlEncoder::encode(const std::string& input) {
    return encode(input.c_str(), input.length());
}

std::string UrlEncoder::encode(const char* input) {
    if (!input) {
        throw std::invalid_argument("Входная строка не может быть пустой");
    }
    return encode(input, std::strlen(input));
}

std::string UrlEncoder::encode(const char* input, size_t length) {
    if (!input) {
        throw std::invalid_argument("Входная строка не может быть пустой");
    }

    std::string result;
    result.reserve(length * 3); // Maximum possible size after encoding

    std::for_each(input, input + length, [&result](char c) {
        if (isUrlSafe(c)) {
            result += c;
        } else {
            result += charToHex(c);
        }
    });

    return result;
}

std::string UrlEncoder::decode(const std::string& input) {
    return decode(input.c_str(), input.length());
}

std::string UrlEncoder::decode(const char* input) {
    if (!input) {
        throw std::invalid_argument("Входная строка не может быть пустой");
    }
    return decode(input, std::strlen(input));
}

std::string UrlEncoder::decode(const char* input, size_t length) {
    if (!input) {
        throw std::invalid_argument("Входная строка не может быть пустой");
    }

    std::string result;
    result.reserve(length);

    // Find all percent signs
    std::vector<size_t> percentPositions;
    std::for_each(input, input + length, [&percentPositions, input](const char& c) {
        if (c == '%') {
            percentPositions.push_back(std::distance(input, &c));
        }
    });

    // Process the string in chunks
    size_t lastPos = 0;
    std::for_each(percentPositions.begin(), percentPositions.end(), 
        [&](size_t pos) {
            // Copy characters before the percent sign
            std::copy(input + lastPos, input + pos, std::back_inserter(result));
            
            // Check if we have enough characters for a hex code
            if (pos + 2 < length) {
                // Check if the next two characters are valid hex digits
                if (std::isxdigit(input[pos + 1]) && std::isxdigit(input[pos + 2])) {
                    result += hexToChar(input + pos + 1);
                    lastPos = pos + 3;
                } else {
                    throw std::runtime_error("Некорректное URL-кодирование: неверные шестнадцатеричные цифры");
                }
            } else {
                throw std::runtime_error("Некорректное URL-кодирование: неполный шестнадцатеричный код");
            }
        });

    // Copy remaining characters
    std::copy(input + lastPos, input + length, std::back_inserter(result));

    return result;
} 