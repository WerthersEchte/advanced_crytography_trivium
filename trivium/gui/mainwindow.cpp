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

    vStream.str("");
    vStream << mIV;

    lEIVBin->setText(QString::fromStdString(vStream.str()));

    std::vector<unsigned char> vBytes;

    vStream.str("");
    vStream<<std::hex;

    vBytes = trivium::bitsetToByteArray(mKey.to_string());
    for( unsigned char vByte : vBytes ){
        vStream << static_cast<int>(vByte);
    }
    lEKeyHex->setText(QString::fromStdString(vStream.str()));

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

}
