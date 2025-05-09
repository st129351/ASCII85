#include "decode.h"

std::string DecodeASCII85(std::string data) {
    std::string out;
    std::string ascii85 = "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstu";
    std::vector<unsigned int> vec;
    std::vector<char> result;
    int count = 0;
    
    // correcting input string
    if (data[0] == '<' && data[1] == '~' && data[data.length() - 2] == '~' && data[data.length() - 1] == '>') {
        data = data.substr(2, data.size() - 4); // string.substr(start_simb_pos, quantity of items)
    }

    // splitting the string into 5 symbols &&
    // convert a symbol to a number
    for (char item : data) {
        if (item == 'z') {
            out += '\0';
            out += '\0';
            out += '\0';
            out += '\0';
        }
        count += 1;
        unsigned int ind;
        for (int index = 0; index < ascii85.size(); index++) {
            if (item == ascii85[index]) {
                ind = index;
            }
        }
        vec.push_back(ind);

        if (count % 5 == 0) {
            // calculate the original 32-bits number
            unsigned long long curr = 0;
            for (int i = 0; i < 5; ++i) {
                curr = curr * 85 + vec[i]; // (((a1 * 85) + a2) * 85) + a3)...
            }
            uint32_t num = static_cast<uint32_t>(curr);
            // convert a orig 32-bits num back to a 4 bytes (big-endian)
            unsigned int shift = 8;

            for (int i = 3; i >= 0; i--) { 
                // >> - right shift, 100 >> 2 -> 001
                // 0xFF - mask of 11111111, take only 8 junior bits
                uint8_t byte = (num >> i * shift) & 0xFF;
                // or i also can use static_cast<uint8_t>(num>>i*shift)
                out.push_back(static_cast<char>(byte));
            }
            vec.clear();
        }
    }
    // if isn't 5 -> use u instead of zeros
    if (!vec.empty()) {
        int size = vec.size(); // quantity of significant symbols ascii85
        while (vec.size() < 5) {
            vec.push_back(84); // equal 'u'
        }
        unsigned long long curr = 0;
        for (int i = 0; i < 5; ++i) {
            curr = curr * 85 + vec[i]; // (((a1 * 85) + a2) * 85) + a3)...
        }
        uint32_t num = static_cast<uint32_t>(curr);

        for (int i = 0; i < size - 1; i++) { // 1 byte -> 2 symbols ascii, 2 byte -> 3symbols ascii
            out += static_cast<char>((num >> (24 - i * 8)) & 0xFF);
        }
    }

    return out;
}