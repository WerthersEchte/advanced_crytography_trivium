#include "mainwindow.h"

#include <sstream>

namespace trivium{

std::string bitstringToHexstring( const std::string& aBits );

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    mKey("1110001010"),
    mIV()
{
    setupUi(this);

    std::stringstream vStream;

    vStream << mKey;
    lEKeyBin->setText(QString::fromStdString(vStream.str()));
    lEKeyHex->setText(QString::fromStdString(bitstringToHexstring(vStream.str())));

    vStream.clear();
    vStream << mIV;
    lEIVBin->setText(QString::fromStdString(vStream.str()));
    lEIVHex->setText(QString::fromStdString(bitstringToHexstring(vStream.str())));
};

std::string bitstringToHexstring( const std::string& aBits ){

    std::vector<unsigned char> vReverseHexas;
    std::stringstream vHexas;
    std::locale vLocale;

    unsigned char vHex = 0, vCounter = 0;

    for( int vI = aBits.size() - 1; vI >= 0; --vI ){

        vHex <<= 1;
        ++vCounter;

        if( aBits[vI] == '1' ){

            vHex += 1;

        }

        if( vCounter == 4 ){

            vReverseHexas.push_back((char)(vHex > 9 ? vHex + 0x37 + 0x20 : vHex + 0x30));
            vCounter = 0;
            vHex = 0;

        }

    }

    while(!vReverseHexas.empty()){

        vHexas << vReverseHexas.back();
        vReverseHexas.pop_back();

    }

    return vHexas.str();

}


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
