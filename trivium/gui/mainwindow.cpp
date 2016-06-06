#include "mainwindow.h"

#include <QRegExp>
#include <QRegExpValidator>
#include <QVBoxLayout>

#include <sstream>
#include <iostream>
#include <algorithm>

namespace trivium{

std::string bitstringToHexstring( const std::string& aBits );
std::string hexstringToBitstring( const std::string& aHex );

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    mKey(),
    mIV(),
    mTrivium(),
    mA(),
    mB(),
    mC()
{
    setupUi(this);

    QRegExp vRegExp("[01]{1,80}");
    QRegExpValidator* vValidator = new QRegExpValidator(vRegExp, this);

    lEKeyBin->setValidator(vValidator);
    lEIVBin->setValidator(vValidator);

    vRegExp = QRegExp("[0-9a-fA-F]{1,20}");
    vValidator = new QRegExpValidator(vRegExp, this);

    lEKeyHex->setValidator(vValidator);
    lEIVHex->setValidator(vValidator);

    vRegExp = QRegExp("[0-9]{1,5}");
    vValidator = new QRegExpValidator(vRegExp, this);

    lESteps->setValidator(vValidator);

    std::stringstream vStream;
    vStream << mKey;

    lEKeyBin->setText(QString::fromStdString(vStream.str()));

    vStream.str("");
    vStream << mIV;

    lEIVBin->setText(QString::fromStdString(vStream.str()));

    updateHexText("");

    connect(lEIVBin, SIGNAL(textEdited(QString)), this, SLOT(updateHexText(QString)) );
    connect(lEIVHex, SIGNAL(textEdited(QString)), this, SLOT(updateBinText(QString)) );
    connect(lEKeyBin, SIGNAL(textEdited(QString)), this, SLOT(updateHexText(QString)) );
    connect(lEKeyHex, SIGNAL(textEdited(QString)), this, SLOT(updateBinText(QString)) );

    tEKeyStreamBin->setReadOnly(true);
    tEKeyStreamHex->setReadOnly(true);

    connect(bInit, SIGNAL(clicked(bool)), this, SLOT(initalizeTrivium(bool)) );
    connect(bWarmUp, SIGNAL(clicked(bool)), this, SLOT(warmupTrivium(bool)) );
    connect(bStep, SIGNAL(clicked(bool)), this, SLOT(stepTrivium(bool)) );
    connect(bSteps, SIGNAL(clicked(bool)), this, SLOT(multistepTrivium(bool)) );

    trivium::Bit* vBit;

    for( int vI = 0; vI < mTrivium.mA.size(); ++vI ){
        vBit = new Bit( mTrivium.mA[vI], vI+1 );
        vBit->setMaximumSize(14,40);
        vBit->setMinimumSize(14,40);
        mA.push_back(vBit);

        fA->layout()->addWidget(vBit);

    }
    for( int vI = 0; vI < mTrivium.mB.size(); ++vI ){
        vBit = new Bit( mTrivium.mB[vI], vI+1 );
        vBit->setMaximumSize(14,40);
        vBit->setMinimumSize(14,40);
        mB.push_back(vBit);

        fB->layout()->addWidget(vBit);

    }
    for( int vI = 0; vI < mTrivium.mC.size(); ++vI ){
        vBit = new Bit( mTrivium.mC[vI], vI+1 );
        vBit->setMaximumSize(14,40);
        vBit->setMinimumSize(14,40);
        mC.push_back(vBit);

        fC->layout()->addWidget(vBit);

    }

};


void MainWindow::updateHexText(const QString& aText){

    mKey = std::bitset<80>(lEKeyBin->text().toStdString());
    mIV = std::bitset<80>(lEIVBin->text().toStdString());

    std::vector<unsigned char> vBytes;
    std::stringstream vStream;

    vStream.str("");
    vStream<<std::hex;

    vBytes = trivium::bitsetToByteArray(lEKeyBin->text().toStdString());
    std::reverse(vBytes.begin(), vBytes.end());
    for( unsigned char vByte : vBytes ){
        if(vByte < 16){
            vStream << '0';
        }
        vStream << static_cast<int>(vByte);
    }
    lEKeyHex->setText(QString::fromStdString(vStream.str()).toUpper());

    vStream.str("");
    vStream<<std::hex;

    vBytes = trivium::bitsetToByteArray(lEIVBin->text().toStdString());
    std::reverse(vBytes.begin(), vBytes.end());
    for( unsigned char vByte : vBytes ){
        if(vByte < 16){
            vStream << '0';
        }
        vStream << static_cast<int>(vByte);
    }
    lEIVHex->setText(QString::fromStdString(vStream.str()).toUpper());

};

void MainWindow::updateBinText(const QString& aText){
    lEKeyBin->setText(QString::fromStdString(trivium::hexstringToBitstring(lEKeyHex->text().toStdString())));
    lEIVBin->setText(QString::fromStdString(trivium::hexstringToBitstring(lEIVHex->text().toStdString())));

    mKey = std::bitset<80>(lEKeyBin->text().toStdString());
    mIV = std::bitset<80>(lEIVBin->text().toStdString());
};
void MainWindow::initalizeTrivium(bool){
    mTrivium.initalize(mKey, mIV);
    tEKeyStreamBin->setPlainText("");
    bWarmUp->setStyleSheet("color: rgb(255, 0, 0);");

    updateRegister();
};
void MainWindow::warmupTrivium(bool){
    mTrivium.warmUp();
    bWarmUp->setStyleSheet("color: rgb(0, 255, 0);");

    updateRegister();
};
void MainWindow::stepTrivium(bool){
    tEKeyStreamBin->setPlainText( QString::number(mTrivium.step()).append(tEKeyStreamBin->toPlainText()) );

    std::vector<unsigned char> vBytes;
    std::stringstream vStream;

    vStream.str("");
    vStream<<std::hex;

    vBytes = trivium::bitsetToByteArray(tEKeyStreamBin->toPlainText().toStdString());
    std::reverse(vBytes.begin(), vBytes.end());
    for( unsigned char vByte : vBytes ){
        if(vByte < 16){
            vStream << '0';
        }
        vStream << static_cast<int>(vByte);
    }
    tEKeyStreamHex->setPlainText(QString::fromStdString(vStream.str()).toUpper());

    updateRegister();
};
void MainWindow::multistepTrivium(bool){
    for(int vI = 0; vI < lESteps->text().toInt(); ++vI ){
        stepTrivium();
    }
};
void MainWindow::updateRegister(){

    for( int vI = 0; vI < mTrivium.mA.size(); ++vI ){
        mA[vI]->setBit(mTrivium.mA[vI]);
    }
    for( int vI = 0; vI < mTrivium.mB.size(); ++vI ){
        mB[vI]->setBit(mTrivium.mB[vI]);
    }
    for( int vI = 0; vI < mTrivium.mC.size(); ++vI ){
        mC[vI]->setBit(mTrivium.mC[vI]);
    }

};
}
