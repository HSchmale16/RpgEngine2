#include "../include/RpnCalculator.hpp"
#include <fstream>
#include <streambuf>
#include <iostream>

std::string loadFile(std::string file) {
    std::ifstream t(file);
    if(!t)
        throw "requested file does not exist";
    std::string str((std::istreambuf_iterator<char>(t)),
                     std::istreambuf_iterator<char>());
    return str;
}

int main(int argc, char** argv) {
    try {
        RpnCalculator c;
        c.loadOperations("4 5 +");
        VariableMap m = {
            {"VAR", 3}
        };
        
        int64_t n = c.getResult(m);
        std::cout << "RESULT = " << n << std::endl;
    } catch (const char* c) {
        std::cerr << std::endl;
        std::cerr << c << std::endl;
        return 1;
    }
    return 0;
}