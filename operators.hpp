#ifndef OPERATORS_HPP_
#define OPERATORS_HPP_

#include <cmath>
#include <stdexcept>

inline bool isOperator(char c){
    switch(c){
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
            return true;
        default:
            return false;
    }
}

inline float doOperator(char op, float v1, float v2){
    switch(op){
        case '+':
            return v1+v2;
            break;
        case '-':
            return v1-v2;
            break;
        case '*':
            return v1*v2;
            break;
        case '/':
            return v1/v2;
            break;
        case '%':
            return std::fmod(v1,v2);
            break;
        default:
            throw std::invalid_argument("op");
    }
}

inline float readFloat(char const* const readHead, char const** newReadHead){
    char* readAhead = NULL;
    float const f = std::strtof(readHead,&readAhead);
    *newReadHead = readAhead;
    return f;
}

#endif //OPERATORS_HPP_