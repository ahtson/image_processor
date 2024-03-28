#pragma once

#include <string>

class BaseException : public std::exception {
public:
    const char* what() const noexcept override = 0;
};
