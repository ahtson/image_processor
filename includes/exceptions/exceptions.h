#pragma once

#include "base_exception.h"

class ZeroArgumentsException : public BaseException {
    const char* what() const noexcept override {
        return "Arguments required";
    }
};

class ParserException : public BaseException {
    const char* what() const noexcept override {
        return "Invalid usage";
    }
};

class FilterException : public BaseException {
    const char* what() const noexcept override {
        return "Invalid filter name or invalid filter parameters";
    }
};

class FileException : public BaseException {
    const char* what() const noexcept override {
        return "Corrupted or incompatible file";
    }
};

class RatioException : public BaseException {
    const char* what() const noexcept override {
        return "A value is out of boundaries";
    }
};
