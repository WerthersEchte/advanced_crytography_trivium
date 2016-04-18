#define BOOST_TEST_MAIN
#if !defined( WIN32 )
    #define BOOST_TEST_DYN_LINK
#endif
#include <boost/test/unit_test.hpp>

#include "core/trivium.h"

#include <bitset>
#include <string>
#include <vector>
#include <sstream>
#include <locale>
//TODO: Debug remove
#include <iostream>


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

BOOST_AUTO_TEST_CASE( hexstringToBitstring_first ) {

    std::string vHexString = "",
                vBinaryString = "";

    BOOST_CHECK_EQUAL( hexstringToBitstring( vHexString ), vBinaryString );

}

BOOST_AUTO_TEST_CASE( hexstringToBitstring_second ) {

    std::string vHexString = "8000",
                vBinaryString = "1000000000000000";

    BOOST_CHECK_EQUAL( hexstringToBitstring( vHexString ), vBinaryString );

}

BOOST_AUTO_TEST_CASE( hexstringToBitstring_third ) {

    std::string vHexString = "FEDCBA9876543210",
                vBinaryString = "1111111011011100101110101001100001110110010101000011001000010000";

    BOOST_CHECK_EQUAL( hexstringToBitstring( vHexString ), vBinaryString );

}

BOOST_AUTO_TEST_CASE( trivium_first ) {

    std::bitset<80> vKey(hexstringToBitstring("00400000000000000000"));
    std::bitset<80> vIV(hexstringToBitstring("00000000000000000000"));

    std::string vKeyStream = hexstringToBitstring( "6120" );
    trivium::Trivium vTrivium(vKey, vIV);
    vTrivium.print();
    vTrivium.warmUp();
    vTrivium.print();

    std::vector<bool> vByte;
    std::stringstream vKeyBits;

    for( int vI = 0; vI < vKeyStream.size(); ++vI ){

        vByte.push_back(vTrivium.step());
        if( vByte.size() == 8 ){

            for( int vJ = 7; vJ >= 0; --vJ ){

                vKeyBits << vByte[vJ];

            }

            vByte.clear();
        }

    }

    BOOST_CHECK_EQUAL( vKeyBits.str().size(), vKeyStream.size() );
    BOOST_CHECK_EQUAL( vKeyBits.str(), vKeyStream );

    std::cout << vKeyBits.str() << std::endl;
    std::cout << vKeyStream << std::endl;

}

//1000000000000000000000000000000000000000000000000000000000000000
//10000000000000000000000000000000000000000000000000000000000000000000000000000000
