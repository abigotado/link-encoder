#include "url_encoder.hpp"
#include <algorithm>
#include <cctype>
#include <sstream>
#include <iomanip>

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
        throw std::invalid_argument("Input string cannot be null");
    }
    return encode(input, std::strlen(input));
}

std::string UrlEncoder::encode(const char* input, size_t length) {
    if (!input) {
        throw std::invalid_argument("Input string cannot be null");
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
        throw std::invalid_argument("Input string cannot be null");
    }
    return decode(input, std::strlen(input));
}

std::string UrlEncoder::decode(const char* input, size_t length) {
    if (!input) {
        throw std::invalid_argument("Input string cannot be null");
    }

    std::string result;
    result.reserve(length);

    for (size_t i = 0; i < length; ++i) {
        if (input[i] == '%' && i + 2 < length) {
            try {
                result += hexToChar(input + i + 1);
                i += 2;
            } catch (...) {
                throw std::runtime_error("Invalid URL encoding");
            }
        } else {
            result += input[i];
        }
    }

    return result;
} 