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
#include <cstdint>

typedef std::map<std::string,int64_t> VariableMap;

/** A simple RPN calculator that supports variables passed in using an std::map
 */
class RpnCalculator {
private:
    typedef std::vector<int64_t> ValueStack;

    /* Defines an operation or constant in the operation stack
     */
    struct StackItem {
        enum Type {
            CONSTANT,           // [0-9]+
            VARIABLE,           // [A-Za-z_]+
            ADDITION = '+',     // +
            SUBTRACTION = '-',  // -
            MULTIPLY = '*',     // *
            DIVISION = '/'      // /
        } type;
        std::variant<std::string,int64_t> value;

        // constants
        StackItem(int64_t n) {
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
                throw "RPN CALCULATOR UNKNOWN OPERATOR";
            }
        }

        void dump(std::ostream& out) {
            if(type == CONSTANT) {
                out << "CONST = " << std::get<int64_t>(value) << std::endl;
            } else if(type == VARIABLE) {
                out << "VARIA = " << std::get<std::string>(value) << std::endl;
            } else {
                out << "OPERA = " << static_cast<char>(type) << std::endl;
            }
        }
    };

    // The operations involved and loaded into place
    std::vector<StackItem> m_opStack;

    // vars that must be in the variable map for this to execute
    std::set<std::string> m_requiredVars;

    void pushConstant(int64_t n) {
        StackItem si(n);
        m_opStack.push_back(si);
    }

    void pushOperator(std::string op) {
        assert(!op.empty());
        StackItem si(op[0]);
        m_opStack.push_back(si);
    }

    void pushVariable(std::string op) {
        StackItem si(op);
        m_requiredVars.insert(op);
        m_opStack.push_back(si);
    }

    void parsePushString(std::string& str) {
        const std::regex is_constant("[0-9]+");
        const std::regex is_variable("[A-Za-z_]+");
        const std::regex is_operator("[\\+\\-\\*\\/]");
        if(std::regex_match(str, is_constant)) {
            pushConstant(stod(str));
        } else if (std::regex_match(str, is_variable)) {
            pushVariable(str);
        } else if(std::regex_match(str, is_operator)) {
            pushOperator(str);
        }
    }

    /** Checks if a given variable map has all of the required keys to 
     *  execute using the given map;
     */
    bool validateVariableMap(VariableMap& vars) {
        for(auto var : m_requiredVars) {
            if(vars.find(var) == vars.end())
                return false;
        }
        return true;
    }

    void performOperation(ValueStack& stack, StackItem::Type type) {
        assert(type != StackItem::VARIABLE && type != StackItem::CONSTANT);
        assert(stack.size() > 1);

        // load operands
        int64_t op1, op2;
        op1 = stack.back();
        stack.pop_back();
        op2 = stack.back();
        stack.pop_back();

        // place result
        switch(type) {
        case StackItem::ADDITION:
            stack.push_back(op2 + op1);
            break;
        case StackItem::SUBTRACTION:
            stack.push_back(op2 - op1);
            break;
        case StackItem::MULTIPLY:
            stack.push_back(op2 * op1);
            break;
        case StackItem::DIVISION:
            stack.push_back(op2 / op1);
            break;
        }
    }

    void printStack(ValueStack& stack, std::ostream& out) {
        out << "=====" << std::endl;
        for(auto it = stack.rbegin(); it != stack.rend(); ++it)
            out << *it << "\n";
    }
public:
    RpnCalculator() {
        m_opStack.reserve(10);
    }

    ~RpnCalculator() {}

    void loadOperations(std::string operations) {
        // clear old ops and required variables
        m_opStack.clear();
        m_requiredVars.clear();

        // load new ops
        std::stringstream sstr(operations);
        std::string str;
        while(sstr >> str) {
            parsePushString(str);
        }
    }

    int64_t getResult(VariableMap& vars) {
        if(!validateVariableMap(vars))
            throw "RPNCALCULATOR Invalid Variable Map";
        ValueStack valueStack;
        for(auto& si : m_opStack) {
            //printStack(valueStack, std::cerr);
            switch(si.type) {
            case StackItem::CONSTANT:
                valueStack.push_back(std::get<int64_t>(si.value));
                break;
            case StackItem::VARIABLE:
                valueStack.push_back(vars[std::get<std::string>(si.value)]);
                break;
            default:
                performOperation(valueStack, si.type);
                break;
            }
        }
        return valueStack.back();
    }

    void dump(std::ostream& out) {
        for(auto& i : m_opStack)
            i.dump(out);   
    }
};


#endif // RPN_CALCULATOR_HPP