#include <map>
#include "../includes/io/parser.h"
#include "../../includes/exceptions/tester.h"

Parser::Parser(int argc, char** argv) {
    TestParserArguments(argc, argv);
    program_ = argv[program_name_];
    input_ = argv[input_file_name_];
    output_ = argv[output_file_name_];
    std::map<std::string_view, std::vector<std::string_view>> raw_arguments;
    std::string_view filter;
    if (argc > 3) {
        for (int i = 3; i < argc; ++i) {
            if (*argv[i] == '-') {
                if (!raw_arguments.empty()) {
                    filter_param_.push_back({filter, raw_arguments.at(filter)});
                    raw_arguments.clear();
                }
                filter = argv[i];
                raw_arguments[filter];
            } else {
                raw_arguments[filter].push_back(argv[i]);
            }
        }
        filter_param_.push_back({filter, raw_arguments.at(filter)});
    }
}

std::string_view Parser::GetInputFile() const {
    return input_;
}

std::string_view Parser::GetOutputFile() const {
    return output_;
}

std::string_view Parser::GetProgramName() const {
    return program_;
}

Filters& Parser::GetFilters() {
    return filter_param_;
}