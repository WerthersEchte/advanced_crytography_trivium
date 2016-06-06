#ifndef _trivium_
#define _trivium_

#include <bitset>
#include <vector>

namespace trivium{

class Trivium{

public:
    std::bitset<93> mA;
    std::bitset<84> mB;
    std::bitset<111> mC;

    Trivium();
    Trivium(const std::bitset<80>& aKey, const std::bitset<80>& aIV);

    void initalize(const std::bitset<80>& aKey, const std::bitset<80>& aIV);

    bool step();
    void warmUp();

    void print();

};

std::vector<unsigned char> bitsetToByteArray( const std::string& aBitSet );
std::string hexstringToBitstring( const std::string& aHex );
}

#endif //_trivium_
