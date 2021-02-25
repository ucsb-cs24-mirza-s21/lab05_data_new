#include <gtest/gtest.h>
#include <limits>
#include <sstream>
#include <vector>
#include "operators.hpp"
#include "prefix.hpp"
#include "postfix.hpp"

bool isNan(float x){return x != x;}



// Translation testing
// The datastructure below is for testing purposes only and should not be
//  taken as an example of how to complete the assignment. You'll find it
//  woefully convoluted, inefficient and slow, as well as not at all
//  representative of the operation precedence in the underlying equation.

union TokData{
    float f;
    char op;

    TokData(float f_):f(f_){}
    TokData(char op_):op(op_){}
};

enum TokKind{
    Operand,
    Operator
};

struct Tok{
    const TokData dat;
    const TokKind kind;

    Tok(float f):dat(f),kind(Operand){}
    Tok(char op):dat(op),kind(Operator){}
    Tok(Tok const&) = default;

    bool operator==(Tok const& o) const{
        return (this->kind == o.kind) && (this->dat.f == o.dat.f || this->dat.op == o.dat.f);
    }
};

Tok readTok(char const*& s){
    if(isOperator(*s) && (std::isspace(*(s+1)) || *(s+1)=='\0')){
        return Tok(*s++); 
    }else{
        float f = readFloat(s,&s);
        return Tok(f);
    }
}

std::vector<Tok> readTokStr(char const* a){
    while(std::isspace(*a) && *a != '\0') ++a;

    std::vector<Tok> toks{};

    while(*a != '\0'){
        toks.push_back(readTok(a));

        while(std::isspace(*a) && *a != '\0') ++a;
    }

    return toks;
}

::testing::AssertionResult TOK_EQ(char const* const a, char const* const b){

    ::testing::AssertionResult result = ::testing::AssertionSuccess();

    if(std::isspace(*a))
        result = (result ? ::testing::AssertionFailure() : result)
            <<"There should not be extra whitespace at the beginning.\n";
    if(strlen(a)>=1 && std::isspace(*(a+strlen(a)-1))) 
        result = (result ? ::testing::AssertionFailure() : result)
            <<"There should not be extra whitespace at the end.\n";
    
    if(std::isspace(*b))
        result = (result ? ::testing::AssertionFailure() : result)
            <<"There should not be extra whitespace at the beginning.\n";
    if(strlen(b)>=1 && std::isspace(*(b+strlen(b)-1))) 
        result = (result ? ::testing::AssertionFailure() : result)
            <<"There should not be extra whitespace at the end.\n";
    
    {
        auto const endptr = a + strlen(a);
        auto const badChar = std::find_if(a,endptr,[](char c){return !(isOperator(c)||std::isdigit(c)||c==' '||c=='.');});
        if(badChar != endptr){
            result = (result ? ::testing::AssertionFailure() : result)
                <<"The character '"<<*badChar<<"' should not be present in the actual.\n";
            
            return result;
        }
    }
    {
        auto const endptr = b + strlen(b);
        auto const badChar = std::find_if(a,endptr,[](char c){return !(isOperator(c)||std::isdigit(c)||c==' '||c=='.');});
        if(badChar != endptr){
            result = (result ? ::testing::AssertionFailure() : result)
                <<"The character '"<<*badChar<<"' should not be present in the expected.\n";
            
            return result;
        }
    }
    
    auto const aTokens = readTokStr(a);
    auto const bTokens = readTokStr(b);

    auto aIter = aTokens.cbegin();
    auto bIter = bTokens.cbegin();
    for(;(aIter != aTokens.cend()) && (bIter != bTokens.cend()) && (*aIter == *bIter);++aIter,++bIter);

    auto const tokenNum = std::distance(aTokens.cbegin(),aIter);

    if(aIter != aTokens.cend() && bIter != bTokens.cend()){
        result = (result ? ::testing::AssertionFailure() : result)
            <<"Actual differs from expectation at token "<<tokenNum<<'\n';
    }else if(aIter == aTokens.cend() && bIter != bTokens.cend()){
        result = (result ? ::testing::AssertionFailure() : result)
            <<"Actual runs out of tokens before expectation at token "<<tokenNum<<'\n';
    }else if(aIter != aTokens.cend() && bIter == bTokens.cend()){
        result = (result ? ::testing::AssertionFailure() : result)
            <<"Actual has unexpected extra tokens, starting at token "<<tokenNum<<'\n';
    }

    if(result){
    }else{
        result 
            <<"\tExpected: "<<b<<'\n'
            <<"\t  Actual: "<<a<<'\n';
    }

    return result;
}

::testing::AssertionResult TOK_EQ(std::string const& a, char const* const b){
    return TOK_EQ(a.c_str(),b);
}
