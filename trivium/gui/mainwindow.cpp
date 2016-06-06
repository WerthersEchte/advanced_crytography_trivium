#include "mainwindow.h"

#include <QRegExp>
#include <QRegExpValidator>
#include <QVBoxLayout>
#include <QPixmap>
#include <QPainter>

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

        if( vI == 68 ){
            lABit69->setText(mTrivium.mA[vI]?"1":"0");
            vBit->setStyleSheet("QWidget#lbBit { border-style: solid; border-width: 2; border-color: rgb(255, 0, 0); }");
        }
        if( vI == 65 ){
            vBit->setStyleSheet("QWidget#lbBit { border-style: solid; border-width: 2; border-color: rgb(0, 255, 0); }");
        }

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

    lCBit66_111_110_109->setText((mTrivium.mC[65] != mTrivium.mC[110]) != (mTrivium.mC[109]&&mTrivium.mC[108])?"1":"0");

    QPixmap *pixmap = new QPixmap(1316,40);
    pixmap->fill(Qt::transparent);
    QPainter p(pixmap);
    p.setPen(QPen(QBrush(QColor(Qt::red)),3));
    p.drawLine(973,40,973,25);
    p.drawLine(0,25,973,25);
    p.setPen(QPen(QBrush(QColor(Qt::green)),3));
    p.drawLine(931,40,931,15);
    p.drawLine(931,15,1330,15);
    p.end();
    lAMTop->setPixmap(*pixmap);

    pixmap = new QPixmap(70,140);
    pixmap->fill(Qt::transparent);
    p.begin(pixmap);
    p.setPen(QPen(QBrush(QColor(Qt::red)),3));
    p.drawLine(44,24,70,24);
    p.drawLine(37,35,37,47);
    p.setPen(QPen(QBrush(QColor(Qt::red)),1));
    p.drawLine(34,40,38,50);
    p.drawLine(42,40,38,50);
    p.drawLine(35,40,38,50);
    p.drawLine(41,40,38,50);
    p.drawLine(36,40,38,50);
    p.drawLine(40,40,38,50);

    p.setPen(QPen(QBrush(QColor(0,0,255)),3));
    p.drawEllipse(28,51,21,21);
    p.setPen(QPen(QBrush(QColor(0,0,255)),1));
    p.drawLine(37,51,37,70);
    p.drawLine(38,51,38,70);
    p.drawLine(39,51,39,70);
    p.drawLine(28,60,65,60);
    p.drawLine(28,61,67,61);
    p.drawLine(28,62,65,62);

    p.drawLine(57,57,67,61);
    p.drawLine(57,58,67,61);
    p.drawLine(57,59,67,61);
    p.drawLine(57,63,67,61);
    p.drawLine(57,64,67,61);
    p.drawLine(57,65,67,61);
    p.end();
    lAFront->setPixmap(*pixmap);

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
        if( vI == 68 ){
            lABit69->setText(mTrivium.mA[vI]?"1":"0");
        }
    }
    for( int vI = 0; vI < mTrivium.mB.size(); ++vI ){
        mB[vI]->setBit(mTrivium.mB[vI]);
    }
    for( int vI = 0; vI < mTrivium.mC.size(); ++vI ){
        mC[vI]->setBit(mTrivium.mC[vI]);
    }

    lCBit66_111_110_109->setText((mTrivium.mC[65] != mTrivium.mC[110]) != (mTrivium.mC[109]&&mTrivium.mC[108])?"1":"0");

};
}
