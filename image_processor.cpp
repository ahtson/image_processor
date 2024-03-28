#include "../includes/bmp/bmp.h"
#include "../includes/exceptions/exceptions.h"
#include <iostream>
#include "../includes/io/parser.h"
#include "../includes/io/runner.h"

int main(int argc, char** argv) {
    try {
        Parser commands = Parser(argc, argv);
        Run(commands);
    } catch (const BaseException& error) {
        std::cerr << error.what() << '\n';
    } catch (...) {
        std::cerr << "Unknown error\n";
        throw;
    }
    return 0;
}
