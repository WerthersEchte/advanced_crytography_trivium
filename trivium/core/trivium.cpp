#include "trivium.h"

#include <iostream>
#include <sstream>
#include <cmath>

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

std::vector<unsigned char> bitsetToByteArray( const std::string& aBitSet ){

    std::vector<unsigned char> vBytes;

    int vPosition = aBitSet.length() - 1, vValue;

    while( vPosition >= 0 ){

        vValue = 0;
        for( int vB = 0; vB < 8; ++vB ){
            if( (vPosition - vB) < 0 ){
                break;
            }
            vValue += (pow(2,vB) * (aBitSet[vPosition - vB] == '1'?1:0));
        }
        vBytes.push_back(vValue);
        vPosition -= 8;
    }

    return vBytes;
};

std::string hexstringToBitstring( const std::string& aHex ){

    std::stringstream vBits;
    std::locale vLocale;

    for( char vCharacter : aHex ){

        switch( std::tolower( vCharacter, vLocale ) ){

            case '0':
                vBits << "0000";
                break;
            case '1':
                vBits << "0001";
                break;
            case '2':
                vBits << "0010";
                break;
            case '3':
                vBits << "0011";
                break;
            case '4':
                vBits << "0100";
                break;
            case '5':
                vBits << "0101";
                break;
            case '6':
                vBits << "0110";
                break;
            case '7':
                vBits << "0111";
                break;
            case '8':
                vBits << "1000";
                break;
            case '9':
                vBits << "1001";
                break;
            case 'a':
                vBits << "1010";
                break;
            case 'b':
                vBits << "1011";
                break;
            case 'c':
                vBits << "1100";
                break;
            case 'd':
                vBits << "1101";
                break;
            case 'e':
                vBits << "1110";
                break;
            case 'f':
                vBits << "1111";
                break;
            default:
                break;

        }

    }

    return vBits.str();

}

}
