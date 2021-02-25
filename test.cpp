#include "test_helper.hpp"


//------------------------------------------------------------------------------
// EvaluatePrefix
//------------------------------------------------------------------------------

TEST(EvaluatePrefix,Addition){
    EXPECT_FLOAT_EQ(evalPrefix("+ 3 4"),7.0f);
    EXPECT_FLOAT_EQ(evalPrefix("+ -3 4"),1.0f);
}

TEST(EvaluatePrefix,Subtraction){
    EXPECT_FLOAT_EQ(evalPrefix("- 3 4"),-1.0f);
    EXPECT_FLOAT_EQ(evalPrefix("- -3 4"),-7.0f);
}

TEST(EvaluatePrefix,Multiplication){
    EXPECT_FLOAT_EQ(evalPrefix("* 3 4"),12.0f);
    EXPECT_FLOAT_EQ(evalPrefix("* -3 4"),-12.0f);
}

TEST(EvaluatePrefix,Division){
    EXPECT_FLOAT_EQ(evalPrefix("/ 3 4"),0.75f);
    EXPECT_FLOAT_EQ(evalPrefix("/ -3 4"),-0.75f);
}

TEST(EvaluatePrefix,Modulo){
    EXPECT_FLOAT_EQ(evalPrefix("% 3 4"),3.0f);
    EXPECT_FLOAT_EQ(evalPrefix("% -3 4"),-3.0f);
}

TEST(EvaluatePrefix,Complex){
    EXPECT_FLOAT_EQ(evalPrefix("+ % 16 8 / 4 2"),2.0f);
    EXPECT_FLOAT_EQ(evalPrefix("+ % -17 8 / 4 2"),1.0f);
}

// EvaluatePostfix
TEST(EvaluatePostfix,Addition){
    EXPECT_FLOAT_EQ(evalPostfix("3 4 +"),7.0f);
    EXPECT_FLOAT_EQ(evalPostfix("-3 4 +"),1.0f);
}

TEST(EvaluatePostfix,Subtraction){
    EXPECT_FLOAT_EQ(evalPostfix("3 4 -"),-1.0f);
    EXPECT_FLOAT_EQ(evalPostfix("-3 4 -"),-7.0f);
}

TEST(EvaluatePostfix,Multiplication){
    EXPECT_FLOAT_EQ(evalPostfix("3 4 *"),12.0f);
    EXPECT_FLOAT_EQ(evalPostfix("-3 4 *"),-12.0f);
}

TEST(EvaluatePostfix,Division){
    EXPECT_FLOAT_EQ(evalPostfix("3 4 /"),0.75f);
    EXPECT_FLOAT_EQ(evalPostfix("-3 4 /"),-0.75f);
}

TEST(EvaluatePostfix,Modulo){
    EXPECT_FLOAT_EQ(evalPostfix("3 4 %"),3.0f);
    EXPECT_FLOAT_EQ(evalPostfix("-3 4 %"),-3.0f);
}

TEST(EvaluatePostfix,Complex){
    EXPECT_FLOAT_EQ(evalPostfix("16 8 % 4 2 / +"),2.0f);
    EXPECT_FLOAT_EQ(evalPostfix("-17 8 % 4 2 / +"),1.0f);
}


//-----------------------------------------------------------------------------
// PrefixToPostfix
//-----------------------------------------------------------------------------
TEST(PrefixToPostfix,Addition){
    EXPECT_TRUE(TOK_EQ(prefixToPostfix("+ 3 4"),"3 4 +"));
    EXPECT_TRUE(TOK_EQ(prefixToPostfix("+ -3 4"),"-3 4 +"));
}


TEST(PrefixToPostfix,Subtraction){
    EXPECT_TRUE(TOK_EQ(prefixToPostfix("- 3 4"),"3 4 -"));
    EXPECT_TRUE(TOK_EQ(prefixToPostfix("- -3 4"),"-3 4 -"));
}

TEST(PrefixToPostfix,Multiplication){
    EXPECT_TRUE(TOK_EQ(prefixToPostfix("* 3 4"),"3 4 *"));
    EXPECT_TRUE(TOK_EQ(prefixToPostfix("* -3 4"),"-3 4 *"));
}

TEST(PrefixToPostfix,Division){
    EXPECT_TRUE(TOK_EQ(prefixToPostfix("/ 3 4"),"3 4 /"));
    EXPECT_TRUE(TOK_EQ(prefixToPostfix("/ -3 4"),"-3 4 /"));
}

TEST(PrefixToPostfix,Modulo){
    EXPECT_TRUE(TOK_EQ(prefixToPostfix("% 3 4"),"3 4 %"));
    EXPECT_TRUE(TOK_EQ(prefixToPostfix("% -3 4"),"-3 4 %"));
}

TEST(PrefixToPostfix,Complex){
    EXPECT_TRUE(TOK_EQ(prefixToPostfix("+ % 16 8 / 4 2"),"16 8 % 4 2 / +"));
    EXPECT_TRUE(TOK_EQ(prefixToPostfix("+ % -17 8 / 4 2"),"-17 8 % 4 2 / +"));
}

// PostfixToPrefix
TEST(PostfixToPrefix,Addition){
    EXPECT_TRUE(TOK_EQ(postfixToPrefix("3 4 +"),"+ 3 4"));
    EXPECT_TRUE(TOK_EQ(postfixToPrefix("-3 4 +"),"+ -3 4"));
}


TEST(PostfixToPrefix,Subtraction){
    EXPECT_TRUE(TOK_EQ(postfixToPrefix("3 4 -"),"- 3 4"));
    EXPECT_TRUE(TOK_EQ(postfixToPrefix("-3 4 -"),"- -3 4"));
}

TEST(PostfixToPrefix,Multiplication){
    EXPECT_TRUE(TOK_EQ(postfixToPrefix("3 4 *"),"* 3 4"));
    EXPECT_TRUE(TOK_EQ(postfixToPrefix("-3 4 *"),"* -3 4"));
}

TEST(PostfixToPrefix,Division){
    EXPECT_TRUE(TOK_EQ(postfixToPrefix("3 4 /"),"/ 3 4"));
    EXPECT_TRUE(TOK_EQ(postfixToPrefix("-3 4 /"),"/ -3 4"));
}

TEST(PostfixToPrefix,Modulo){
    EXPECT_TRUE(TOK_EQ(postfixToPrefix("3 4 %"),"% 3 4"));
    EXPECT_TRUE(TOK_EQ(postfixToPrefix("-3 4 %"),"% -3 4"));
}

TEST(PostfixToPrefix,Complex){
    EXPECT_TRUE(TOK_EQ(postfixToPrefix("16 8 % 4 2 / +"),"+ % 16 8 / 4 2"));
    EXPECT_TRUE(TOK_EQ(postfixToPrefix("-17 8 % 4 2 / +"),"+ % -17 8 / 4 2"));
}