#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <cmath>
#include "encode.h"
#include "decode.h"

int main()
{
    std::cout << "Encode ASCII85 : " << EncodeASCII85("000") << std::endl;
    std::cout << "Decode ASCII85 : " <<  DecodeASCII85(EncodeASCII85("000")) << std::endl;
    return 0;
}