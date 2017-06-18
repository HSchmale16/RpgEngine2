#ifndef RPN_CALCULATOR__HPP
#define RPN_CALCULATOR__HPP

#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <variant>
#include <regex>
#include <cctype>
#include <cassert>
#include <iostream>

typedef std::map<std::string,double> VariableMap;


/** A simple RPN calculator that supports variables passed in using an std::map
 */
class RpnCalculator {
    struct StackItem {
        enum {
            CONSTANT,           // [0-9]+
            VARIABLE,           // [A-Za-z_]+
            ADDITION = '+',     // +
            SUBTRACTION = '-',  // -
            MULTIPLY = '*',     // *
            DIVISION = '/'      // /
        } type;
        std::variant<std::string,double> value;

        // constants
        StackItem(double n) {
            type = CONSTANT;
            value = n;
        }

        // var
        StackItem(std::string& var) {
            type = VARIABLE;
            value = var;
        }

        // operator
        StackItem(char op) {
            switch(op) {
            case '+':
                type = ADDITION; break;
            case '-':
                type = SUBTRACTION; break;
            case '*':
                type = MULTIPLY; break;
            case '/':
                type = DIVISION; break;
            default:
                throw "RPNCALCULATOR UNKNOWN OPERATOR";
            }
        }

        void dump(std::ostream& out) {
            if(type == CONSTANT) {
                out << "CONST = " << std::get<double>(value) << std::endl;
            } else if(type == VARIABLE) {
                out << "VARIA = " << std::get<std::string>(value) << std::endl;
            } else {
                out << "OPERA = " << static_cast<char>(type) << std::endl;
            }
        }
    };
    std::vector<StackItem> m_opStack;

    // vars that must be in the variable map for this to execute
    std::set<std::string> m_requiredVars;

    // Regexes used for paring the expression
    const std::regex is_constant;
    const std::regex is_variable;
    const std::regex is_operator;

    void pushConstant(double n) {
        StackItem si(n);
        m_opStack.push_back(si);
    }

    void pushOperator(std::string op) {
        assert(!op.empty());
        StackItem si(op[0]);
    }

    void pushVariable(std::string op) {
        StackItem si(op);
        m_requiredVars.insert(op);
        m_opStack.push_back(si);
    }

    void parsePushString(std::string& str) {
        if(std::regex_match(str, is_constant)) {
            pushConstant(stod(str));
        } else if (std::regex_match(str, is_variable)) {
            pushVariable(str);
        } else if(std::regex_match(str, is_operator)) {
            pushOperator(str);
        }
        std::cerr << str << "\t" << m_opStack.size() << std::endl;
    }

    bool validateVariableMap(VariableMap& vars) {
        return false;
    }

public:
    RpnCalculator() 
        : is_constant("[:d:]+"), is_variable("[:alpha:]+"), 
            is_operator("[\\+\\-\\*\\/]") {}

    ~RpnCalculator() {}

    void loadOperations(std::string operations) {
        std::stringstream sstr(operations);
        std::string str;
        while(sstr >> str) {
            parsePushString(str);
        }
    }

    double getResult(VariableMap& vars) {
        return 0;
    }

    void dump(std::ostream& out) {
        for(auto& i : m_opStack)
            i.dump(out);   
    }

};


#endif // RPN_CALCULATOR_HPP