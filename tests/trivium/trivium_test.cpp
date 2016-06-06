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

BOOST_AUTO_TEST_CASE( hexstringToBitstring_first ) {

    std::string vHexString = "",
                vBinaryString = "";

    BOOST_CHECK_EQUAL( trivium::hexstringToBitstring( vHexString ), vBinaryString );

}

BOOST_AUTO_TEST_CASE( hexstringToBitstring_second ) {

    std::string vHexString = "8000",
                vBinaryString = "1000000000000000";

    BOOST_CHECK_EQUAL( trivium::hexstringToBitstring( vHexString ), vBinaryString );

}

BOOST_AUTO_TEST_CASE( hexstringToBitstring_third ) {

    std::string vHexString = "FEDCBA9876543210",
                vBinaryString = "1111111011011100101110101001100001110110010101000011001000010000";

    BOOST_CHECK_EQUAL( trivium::hexstringToBitstring( vHexString ), vBinaryString );

}

BOOST_AUTO_TEST_CASE( trivium_first ) {

    std::bitset<80> vKey(trivium::hexstringToBitstring("00000000000000000000"));
    std::bitset<80> vIV(trivium::hexstringToBitstring("00000000000000000000"));

    std::string vKeyStream = trivium::hexstringToBitstring( "FBE0BF265859051B517A2E4E239FC97F563203161907CF2DE7A8790FA1B2E9CDF75292030268B7382B4C1A759AA2599A285549986E74805903801A4CB5A5D4F2" );
    trivium::Trivium vTrivium(vKey, vIV);
    vTrivium.warmUp();

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

}

BOOST_AUTO_TEST_CASE( trivium_second ) {

    std::bitset<80> vKey(trivium::hexstringToBitstring("00020000000000000000"));
    std::bitset<80> vIV(trivium::hexstringToBitstring("00000000000000000000"));

    std::string vKeyStream = trivium::hexstringToBitstring( "61208D286BC1DC431171EDA5CAF79D9560B18ACEF26484417B651A47A3F7A80353F79AF8656DA4301A5E5A02E04265B182C67F5891220349F8CD1CD06597B77E" );
    trivium::Trivium vTrivium(vKey, vIV);
    vTrivium.warmUp();

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

}

BOOST_AUTO_TEST_CASE( trivium_third ) {

    std::bitset<80> vKey(trivium::hexstringToBitstring("00000400000000000000"));
    std::bitset<80> vIV(trivium::hexstringToBitstring("00000000000000000000"));

    std::string vKeyStream = trivium::hexstringToBitstring( "C8F9031DABF8DB03FF120D05512B5F24EAEA1BAB43201A5E93BF17F628E5B216D58577112F581A67DD5F962484ED4AC59202BA3509A73E119680B562F86DF0DC" );
    trivium::Trivium vTrivium(vKey, vIV);
    vTrivium.warmUp();

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

}

BOOST_AUTO_TEST_CASE( trivium_fourth ) {

    std::bitset<80> vKey(trivium::hexstringToBitstring("00000000000000000000"));
    std::bitset<80> vIV(trivium::hexstringToBitstring("01000000000000000000"));

    std::string vKeyStream = trivium::hexstringToBitstring( "F8901736640549E3BA7D42EA2D07B9F49233C18D773008BD755585B1A8CBAB86C1E9A9B91F1AD33483FD6EE3696D659C9374260456A36AAE11F033A519CBD5D7" );
    trivium::Trivium vTrivium(vKey, vIV);
    vTrivium.warmUp();

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

}

BOOST_AUTO_TEST_CASE( trivium_fifth ) {

    std::bitset<80> vKey(trivium::hexstringToBitstring("00000000000000000000"));
    std::bitset<80> vIV(trivium::hexstringToBitstring("00020000000000000000"));

    std::string vKeyStream = trivium::hexstringToBitstring( "ACBB386876653D15010DEFA7C65B36D701CFAF927B417550BE32D0444A24DEB589159B965C6740823F6BDFC378174AE2F664DCA0B68C621D2775BD13E6A788DF" );
    trivium::Trivium vTrivium(vKey, vIV);
    vTrivium.warmUp();

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

}

