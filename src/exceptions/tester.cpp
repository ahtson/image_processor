#include "../../includes/exceptions/tester.h"
#include <iostream>

void TestFilterParameters(Filter params) {
    bool correct_filter_name = false;
    for (std::string_view filter_name : params.existing_filters) {
        if (params.filter_name == filter_name) {
            correct_filter_name = true;
        }
    }
    if (!correct_filter_name) {
        throw FilterException();
    }
}

void TestParserArguments(int arg_count, char** args) {
    if (arg_count == 1) {
        std::cout << "Usage: image_processor [INPUT_FILE] [OUTPUT_FILE] {COMMAND | OPTIONS}\n where: COMMAND := -blur, "
                     "-crop, -edge, -gs, -neg, -sharp, -sepia, -barrel, -age]\n";
        throw ZeroArgumentsException();
    } else if (arg_count < 3) {
        throw ParserException();
    }
}