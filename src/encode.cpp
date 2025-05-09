#include "encode.h"

// encoding string to ASCII85
std::string EncodeASCII85(std::string data) {

    std::vector<char> vec;
    int excess = 0;
    std::vector<uint32_t> result;
    int count = 0;
    std::string ascii85 = "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
    std::string out;

    for (char i : data) {
        count += 1;
        vec.push_back(i);

        if (vec.size() == 4) {
            uint32_t curr32 = 0; // 0000...
            int shift = 0;
            for (char item : vec) {
                uint8_t curr8 = static_cast<uint8_t> (item); // 4 times 8 bits each
                curr32 |= (static_cast<uint32_t> (curr8) << (24 - shift * 8)); // big-endian order; << left shift
                shift += 1;
            }
            result.push_back(curr32);
            vec.clear(); // clear vector and go to next 4 bytes (1 char = 1 byte)
        }
        
        if (count == data.size() && count % 4 != 0) {
            uint32_t curr32 = 0;
            int shift = 0;
            for (char item : vec) {
                uint8_t curr8 = static_cast<uint8_t> (item);
                curr32 |= (static_cast<uint32_t> (curr8) << (24 - shift * 8));
                shift += 1;
            } // write symbols
            int temp = 4 - vec.size();
            for (int i = 0; i < temp; i++) {
                excess += 1;
                curr32 |= (static_cast<uint32_t> (0) << (24 - shift * 8));
                shift += 1;
            } // write 0
            // without add 0 i have trash in last symbols, instead of 0
            result.push_back(curr32);
        }
    }

    for (uint32_t item : result) {
        if (item == 0) {
            out += 'z'; // zero 4 bytes
        }
        else {
            std::vector<int> ascii_symb;
            uint32_t whole = item;
            for (int i = 0; i  < 5; i++) {
                int symbol = whole % 85;
                whole /= 85;
                ascii_symb.push_back(symbol);
            }
            for (int i = ascii_symb.size() - 1; i >= 0; --i) { // in ascii85 symbols are written from big to little
                out += ascii85[ascii_symb[i]];
            }
        }
    }
    return out.substr(0, out.size() - excess);
}