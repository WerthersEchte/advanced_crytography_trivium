#include "mainwindow.h"

#include <sstream>
#include <iostream>

namespace trivium{

std::string bitstringToHexstring( const std::string& aBits );
std::string hexstringToBitstring( const std::string& aHex );

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

    connect(lEIVBin, SIGNAL(textEdited(QString)), this, SLOT(updateHexText(QString)) );
    connect(lEIVHex, SIGNAL(textEdited(QString)), this, SLOT(updateBinText(QString)) );
    connect(lEKeyBin, SIGNAL(textEdited(QString)), this, SLOT(updateHexText(QString)) );
    connect(lEKeyHex, SIGNAL(textEdited(QString)), this, SLOT(updateBinText(QString)) );
};


void MainWindow::updateHexText(const QString& aText){
    lEKeyHex->setText(QString::fromStdString(bitstringToHexstring(lEKeyBin->text().toStdString())));
    lEIVHex->setText(QString::fromStdString(bitstringToHexstring(lEIVBin->text().toStdString())));
};

void MainWindow::updateBinText(const QString& aText){
    lEKeyBin->setText(QString::fromStdString(hexstringToBitstring(lEKeyHex->text().toStdString())));
    lEIVBin->setText(QString::fromStdString(hexstringToBitstring(lEIVHex->text().toStdString())));
};

std::string bitstringToHexstring( const std::string& aBits ){

    std::vector<unsigned char> vReverseHexas;
    std::stringstream vHexas;
    std::locale vLocale;

    std::string vWurst(aBits);
    std::reverse(vWurst.begin(), vWurst.end());

    unsigned char vHex = 0, vCounter = 0;

    for( int vI = vWurst.size() - 1; vI >= 0; --vI ){

        vHex <<= 1;
        ++vCounter;

        if( vWurst[vI] == '1' ){

            vHex += 1;

        }

        if( vCounter == 4 ){

            vReverseHexas.push_back((char)(vHex > 9 ? vHex + 0x37 + 0x20 : vHex + 0x30));
            vCounter = 0;
            vHex = 0;

        }

    }

    if( vCounter > 0 ){

        vReverseHexas.push_back((char)(vHex^15 > 9 ? vHex^15 + 0x37 + 0x20 : vHex^15 + 0x30));

    }

    while(!vReverseHexas.empty()){

        vHexas << vReverseHexas.back();
        vReverseHexas.pop_back();

    }

    std::string vGrunz = vHexas.str();
    std::reverse(vGrunz.begin(), vGrunz.end());
    return vGrunz;

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
