#ifndef RPN_CALCULATOR__HPP
#define RPN_CALCULATOR__HPP

#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <variant>
#include <regex>
#include <cctype>
#include <cassert>

/** A simple RPN calculator that supports variables passed in using an std::map
 */
class RpnCalculator {
    struct StackItem {
        enum {
            CONSTANT,       // [0-9]+
            VARIABLE,       // [A-Za-z_]+
            ADDITION,       // +
            SUBTRACTION,    // -
            MULTIPLY,       // *
            DIVISION        // /
        } type;
        std::variant<std::string,double> value;
    };
    std::vector<StackItem> m_opStack;
    const std::regex is_constant;
    const std::regex is_variable;
    const std::regex is_operator;

    void pushConstant(double n) {

    }

    void pushOperator(std::string op) {

    }

    void pushVariable(std::string op) {

    }

    void parsePushString(std::string& str) {
        if(std::regex_match(str, is_constant)) {

        }
    }

public:
    typedef std::map<std::string,double> VariableMap;

    RpnCalculator() 
        : is_constant("[0-9]+"), is_variable("A-Za-z_]+"), is_operator("[+-\\*/]") {}

    ~RpnCalculator() {}

    void loadOperations(std::string operations) {
        std::stringstream sstr(operations);
        std::string str;
        while(sstr >> str) {
            parsePushString(str);
        }
    }

    double getResult(VariableMap& vars) {

    }

};


#endif // RPN_CALCULATOR_HPP