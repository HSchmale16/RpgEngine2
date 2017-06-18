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
        if(argc < 2)
            throw "FILE ARG REQUIRED";
        std::string operation = loadFile(argv[1]);
        RpnCalculator c;
        std::cout << sizeof c << std::endl;
        c.loadOperations(operation);
        c.dump(std::cerr);
        VariableMap m;
        m.insert(std::make_pair("VAR", 3));
        
        int64_t n = c.getResult(m);
        std::cout << "RESULT = " << n << std::endl;
    } catch (const char* c) {
        std::cerr << std::endl;
        std::cerr << c << std::endl;
        return 1;
    }
    return 0;
}