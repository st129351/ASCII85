#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <cmath>
#include "encode.h"

int main()
{
    std::cout << "Encode ASCII85 : " << EncodeASCII85("hello, world!") << std::endl;
    return 0;
}