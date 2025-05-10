#include <iostream>
#include <string>
#include <vector>
#include "encode.h"
#include "decode.h"

int main(int argc, char* argv[]) // quantity of arguments and array of str-arguments
{
    // argv[1] - is a ptr, 
    bool decode = false;
    if (argc > 1) {
        std::string arg1 = argv[1];
        if (argc > 2 || !(arg1 == "-e" || arg1 == "-d")) {
            std::cerr << "You can use: \nascii85\nascii85 -e\nascii85 -d" << std::endl;
            return 1;
        }
        if (arg1 == "-d") {
            decode = true;
        }
    }
    // processing errors

    // EXECUTE TRANSFORMATIONS
    try {
        std::string inp;
        std::vector<char> outp;
        std::string change;
    
        // READ from "cin" into "inp", correct with binary data (as \0)
        char symb;
        while (std::cin.get(symb)) { 
            // .get(s) puts value from str to symb
            // then happens auto iterate to next symb
            // .get(s) also return condition of std::cin(end or not)
            inp.push_back(symb);
        }
    
        if (!decode) {
            change = EncodeASCII85(inp);
            for (char i : change) {
                outp.push_back(i);
            }
            // method write accept entry (ptr on start the array, the size of array)
            // method is correct for bunary data
            std::cout << "\n";
            std::cout.write(outp.data(), outp.size()) << std::endl;
        }
        else {
            change = DecodeASCII85(inp);
            for (char i : change) {
                outp.push_back(i);
            }
            // method write accept entry (ptr on start the array, the size of array)
            std::cout << "\n";
            std::cout.write(outp.data(), outp.size()) << std::endl;
        }
    }
    catch (std::exception& err) {
        std::cerr << "Error: " << err.what() << std::endl;
        return 1;
    }
    
    return 0;
}