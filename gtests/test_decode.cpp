#include <gtest/gtest.h>
#include "decode.h"
#include <string>
#include <sstream>
// tests with 2, 3, 4 and 0 symbls in remainder
TEST(DecodeTest, RemainTwo) {

    std::string s = "E<";
    std::string dec = "q";
    std::string inp;
    std::string outp;
    char symb;

    // creating flow from start (input) string, like in main.cpp
    std::istringstream flow(s);
    while (flow.get(symb)) {
        inp.push_back(symb);
    }
    outp = DecodeASCII85(inp);
    EXPECT_EQ(outp, dec);
}

TEST(DecodeTest, RemainThree) {

    std::string s = "EH_";
    std::string enc = "qw";
    std::string inp;
    std::string outp;
    char symb;

    // creating flow from start (input) string, like in main.cpp
    std::istringstream flow(s);
    while (flow.get(symb)) {
        inp.push_back(symb);
    }
    outp = DecodeASCII85(inp);
    EXPECT_EQ(outp, enc);
}

TEST(DecodeTest, RemainFour) {

    std::string s = "EHbs";
    std::string enc = "qwe";
    std::string inp;
    std::string outp;
    char symb;

    // creating flow from start (input) string, like in main.cpp
    std::istringstream flow(s);
    while (flow.get(symb)) {
        inp.push_back(symb);
    }
    outp = DecodeASCII85(inp);
    EXPECT_EQ(outp, enc);
}

TEST(DecodeTest, RemainZero) {

    std::string s = "EHbu7";
    std::string enc = "qwer";
    std::string inp;
    std::string outp;
    char symb;

    // creating flow from start (input) string, like in main.cpp
    std::istringstream flow(s);
    while (flow.get(symb)) {
        inp.push_back(symb);
    }
    outp = DecodeASCII85(inp);
    EXPECT_EQ(outp, enc);
}

// with space
TEST(DecodeTest, Space) {

    std::string s = "BOu!rD_*#TDfTZ)+T";
    std::string enc = "hello, world!";
    std::string inp;
    std::string outp;
    char symb;

    // creating flow from start (input) string, like in main.cpp
    std::istringstream flow(s);
    while (flow.get(symb)) {
        inp.push_back(symb);
    }
    outp = DecodeASCII85(inp);
    EXPECT_EQ(outp, enc);
}

// with zeros
TEST(DecodeTest, Zeros) {

    std::string s = "0E";
    std::string enc = "0";
    std::string inp;
    std::string outp;
    char symb;

    // creating flow from start (input) string, like in main.cpp
    std::istringstream flow(s);
    while (flow.get(symb)) {
        inp.push_back(symb);
    }
    outp = DecodeASCII85(inp);
    EXPECT_EQ(outp, enc);
}

// with zeros and space
TEST(DecodeTest, ZerosSpace) {

    std::string s = "0H`%";
    std::string enc = "0 0";
    std::string inp;
    std::string outp;
    char symb;

    // creating flow from start (input) string, like in main.cpp
    std::istringstream flow(s);
    while (flow.get(symb)) {
        inp.push_back(symb);
    }
    outp = DecodeASCII85(inp);
    EXPECT_EQ(outp, enc);
}