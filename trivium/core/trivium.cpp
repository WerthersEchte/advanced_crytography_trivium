#include "trivium.h"

#include <iostream>

namespace trivium{

Trivium::Trivium():
    mA(),
    mB(),
    mC("111000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000")
{};

Trivium::Trivium(const std::bitset<80>& aKey, const std::bitset<80>& aIV):
    mA(),
    mB(),
    mC("111000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000")
{
    initalize(aKey, aIV);
};

void Trivium::initalize(const std::bitset<80>& aKey, const std::bitset<80>& aIV)
{

    mC = std::bitset<111>("111000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");

    for( int vI = 0; vI < aKey.size(); ++vI ){
        mA[vI] = aKey[vI];
    }

    for( int vI = 0; vI < aIV.size(); ++vI ){
        mB[vI] = aIV[vI];
    }

};

bool Trivium::step()
{
    bool vAin, vAout, vBin, vBout, vCin, vCout;

    vAout = mA[65]^mA[92];
    vBout = mB[68]^mB[83];
    vCout = mC[65]^mC[110];

    vAin = mA[68]^(mC[108]&mC[109])^vCout;
    vBin = mB[77]^(mA[90]&mA[91])^vAout;
    vCin = mC[86]^(mB[81]&mB[82])^vBout;

    mA <<= 1;
    mA[0] = vAin;
    mB <<= 1;
    mB[0] = vBin;
    mC <<= 1;
    mC[0] = vCin;

    return vAout^vBout^vCout;
};

void Trivium::warmUp()
{
    for(int vI = 1; vI <= 4*288; ++vI){
        step();
    }
};

void Trivium::print(){
    std::cout << "A: " << mA << std::endl;
    std::cout << "B: " << mB << std::endl;
    std::cout << "C: " << mC << std::endl;
}

}
