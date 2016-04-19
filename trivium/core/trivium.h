#ifndef _trivium_
#define _trivium_

#include <bitset>

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

}

#endif
