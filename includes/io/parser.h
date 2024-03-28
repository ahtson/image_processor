#pragma once

#include <string>
#include <vector>

struct Filter {
    std::string_view filter_name;
    std::vector<std::string_view> filter_params;
    std::vector<std::string_view> existing_filters = {"-crop",  "-gs",    "-barrel", "-blur", "-poster",
                                                      "-sepia", "-sharp", "-edge",   "-neg",  "-age", "-swap"};

    void Clear() {
        filter_name = "";
        filter_params.clear();
    }

    bool Empty() const {
        return (filter_params.empty() && filter_name.empty());
    }
};

using Filters = std::vector<Filter>;

class Parser {
public:
    Parser(int, char **);
    std::string_view GetInputFile() const;
    std::string_view GetOutputFile() const;
    std::string_view GetProgramName() const;
    Filters &GetFilters();

private:
    Filters filter_param_;
    enum console_arguments { program_name_ = 0, input_file_name_, output_file_name_ };
    std::string_view input_;
    std::string_view output_;
    std::string_view program_;
};