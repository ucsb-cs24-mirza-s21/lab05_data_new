#include "postfix.hpp"
#include "operators.hpp"

#include <stack>
#include <cmath>

float evalPostfix(char const* s){
    // Trim incoming whitespace
    while(std::isspace(*s)) ++s;

    // If the string is empty, evaluate nothing.
    if(*s == '\0') return 0.0f;

    // Prep operand stack
    std::stack<float> vals;

    // Loop over the input string
    while(*s != '\0'){
        // TODO: What else goes in this loop?
        
        // Read an operand
        vals.push(readFloat(s,&s));

        // TODO: Don't just break out of the loop.
        break;
    }

    // Return result
    return vals.top();
}

std::string postfixToPrefix(char const* s){
    // Trim incoming whitespace
    while(std::isspace(*s)) ++s;

    // If the string is empty, translate nothing.
    if(*s == '\0') return "";

    // Prep stack
    std::stack<std::string> stack;

    while(*s != '\0'){
        // TODO: Fill in this space with something other than this!
        stack.push("STUB!");
        break;

        // Trim whitespace before next token
        while(std::isspace(*s)) ++s;
    }

    // Return result
    return stack.top();
}