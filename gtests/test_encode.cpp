#include <gtest/gtest.h>
#include "encode.h"
#include <string>
#include <sstream>
// tests with 1, 2, 3 and 0 symbls in remainder
TEST(EncodeTest, RemainOne) {

    std::string s = "q";
    std::string enc = "E<";
    std::string inp;
    std::string outp;
    char symb;

    // creating flow from start (input) string, like in main.cpp
    std::istringstream flow(s);
    while (flow.get(symb)) {
        inp.push_back(symb);
    }
    outp = EncodeASCII85(inp);
    EXPECT_EQ(outp, enc);
}

TEST(EncodeTest, RemainTwo) {

    std::string s = "qw";
    std::string enc = "EH_";
    std::string inp;
    std::string outp;
    char symb;

    // creating flow from start (input) string, like in main.cpp
    std::istringstream flow(s);
    while (flow.get(symb)) {
        inp.push_back(symb);
    }
    outp = EncodeASCII85(inp);
    EXPECT_EQ(outp, enc);
}

TEST(EncodeTest, RemainThree) {

    std::string s = "qwe";
    std::string enc = "EHbs";
    std::string inp;
    std::string outp;
    char symb;

    // creating flow from start (input) string, like in main.cpp
    std::istringstream flow(s);
    while (flow.get(symb)) {
        inp.push_back(symb);
    }
    outp = EncodeASCII85(inp);
    EXPECT_EQ(outp, enc);
}

TEST(EncodeTest, RemainZero) {

    std::string s = "qwer";
    std::string enc = "EHbu7";
    std::string inp;
    std::string outp;
    char symb;

    // creating flow from start (input) string, like in main.cpp
    std::istringstream flow(s);
    while (flow.get(symb)) {
        inp.push_back(symb);
    }
    outp = EncodeASCII85(inp);
    EXPECT_EQ(outp, enc);
}

// with space
TEST(EncodeTest, Space) {

    std::string s = "hello, world!";
    std::string enc = "BOu!rD_*#TDfTZ)+T";
    std::string inp;
    std::string outp;
    char symb;

    // creating flow from start (input) string, like in main.cpp
    std::istringstream flow(s);
    while (flow.get(symb)) {
        inp.push_back(symb);
    }
    outp = EncodeASCII85(inp);
    EXPECT_EQ(outp, enc);
}

// with zero
TEST(EncodeTest, Zero) {

    std::string s = "0";
    std::string enc = "0E";
    std::string inp;
    std::string outp;
    char symb;

    // creating flow from start (input) string, like in main.cpp
    std::istringstream flow(s);
    while (flow.get(symb)) {
        inp.push_back(symb);
    }
    outp = EncodeASCII85(inp);
    EXPECT_EQ(outp, enc);
}

// with zeros and space
TEST(EncodeTest, ZerosSpace) {

    std::string s = "0 0";
    std::string enc = "0H`%";
    std::string inp;
    std::string outp;
    char symb;

    // creating flow from start (input) string, like in main.cpp
    std::istringstream flow(s);
    while (flow.get(symb)) {
        inp.push_back(symb);
    }
    outp = EncodeASCII85(inp);
    EXPECT_EQ(outp, enc);
}