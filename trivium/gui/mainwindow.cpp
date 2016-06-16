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

        if( vI == 68 || vI == 65 || vI == 90 || vI == 91 || vI == 92 ){
            vBit->setStyleSheet("QWidget#lbBit { border-style: solid; border-width: 2; border-color: rgb(255, 0, 0); }");
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

    QPixmap *pixmap = new QPixmap(1317,40);
    pixmap->fill(Qt::transparent);
    lAMTop->setPixmap(*pixmap);
    pixmap = new QPixmap(70,140);
    pixmap->fill(Qt::transparent);
    lAFront->setPixmap(*pixmap);
    pixmap = new QPixmap(1317,60);
    pixmap->fill(Qt::transparent);
    lAMBottom->setPixmap(*pixmap);
    pixmap = new QPixmap(70,140);
    pixmap->fill(Qt::transparent);
    lABack->setPixmap(*pixmap);

    paintA();
};

void MainWindow::paintA(){

    QPainter p(const_cast<QPixmap*>(lAMTop->pixmap()));
    p.setPen(QPen(QBrush(mTrivium.mA[68]?Qt::green:Qt::red),3));
    p.drawLine(973,40,973,25);
    p.drawLine(0,25,973,25);
    p.setPen(QPen(QBrush(mTrivium.mA[65]?Qt::green:Qt::red),3));
    p.drawLine(931,40,931,15);
    p.drawLine(931,15,1317,15);
    p.end();
    lAMTop->update();


    p.begin(const_cast<QPixmap*>(lAFront->pixmap()));
    p.setPen(QPen(QBrush(mTrivium.mA[68]?Qt::green:Qt::red),3));
    p.drawLine(37,24,70,24);
    p.drawLine(37,24,37,47);
    p.setPen(QPen(QBrush(mTrivium.mA[68]?Qt::green:Qt::red),1));
    p.drawLine(34,40,38,50);
    p.drawLine(42,40,38,50);
    p.drawLine(35,40,38,50);
    p.drawLine(41,40,38,50);
    p.drawLine(36,40,38,50);
    p.drawLine(40,40,38,50);

    paintXOR( 28,51, ((mTrivium.mC[65] != mTrivium.mC[110] != (mTrivium.mC[109]&&mTrivium.mC[108]) != mTrivium.mA[68])?Qt::green:Qt::red), &p );

    p.setPen(QPen(QBrush(mTrivium.mC[65] != mTrivium.mC[110] != (mTrivium.mC[109]&&mTrivium.mC[108]) != mTrivium.mA[68]?Qt::green:Qt::red),1));
    p.drawLine(49,60,65,60);
    p.drawLine(49,61,67,61);
    p.drawLine(49,62,65,62);
    p.drawLine(57,57,67,61);
    p.drawLine(57,58,67,61);
    p.drawLine(57,59,67,61);
    p.drawLine(57,63,67,61);
    p.drawLine(57,64,67,61);
    p.drawLine(57,65,67,61);

    p.setPen(QPen(QBrush(mTrivium.mC[65] != mTrivium.mC[110] != (mTrivium.mC[109]&&mTrivium.mC[108])?Qt::green:Qt::red),3));
    p.drawLine(5,61,5,140);
    p.setPen(QPen(QBrush(mTrivium.mC[65] != mTrivium.mC[110] != (mTrivium.mC[109]&&mTrivium.mC[108])?Qt::green:Qt::red),1));
    p.drawLine(5,60,27,60);
    p.drawLine(5,61,28,61);
    p.drawLine(5,62,27,62);
    p.drawLine(17,57,27,61);
    p.drawLine(17,58,27,61);
    p.drawLine(17,59,27,61);
    p.drawLine(17,63,27,61);
    p.drawLine(17,64,27,61);
    p.drawLine(17,65,27,61);

    p.setPen(QPen(QBrush(mTrivium.mA[65] != mTrivium.mA[92] != (mTrivium.mA[90] && mTrivium.mA[91])?Qt::green:Qt::red),3));
    p.drawLine(37,122,70,122);
    p.drawLine(37,122,37,140);

    p.end();
    lAFront->update();


    p.begin(const_cast<QPixmap*>(lAMBottom->pixmap()));
    p.setPen(QPen(QBrush(mTrivium.mA[90]?Qt::green:Qt::red),3));
    p.drawLine(1281,0,1281,5);
    p.setPen(QPen(QBrush(mTrivium.mA[91]?Qt::green:Qt::red),3));
    p.drawLine(1295,0,1295,5);
    paintAND( 1275,6, (mTrivium.mA[90] && mTrivium.mA[91]?Qt::green:Qt::red), &p );
    p.drawLine(1288,24,1288,30);
    paintXOR( 1278,31, (mTrivium.mA[65] != mTrivium.mA[92] != (mTrivium.mA[90] && mTrivium.mA[91])?Qt::green:Qt::red), &p );
    p.setPen(QPen(QBrush(mTrivium.mA[65] != mTrivium.mA[92] != (mTrivium.mA[90] && mTrivium.mA[91])?Qt::green:Qt::red),3));
    p.drawLine(0,41,1278,41);
    p.setPen(QPen(QBrush(mTrivium.mA[65] != mTrivium.mA[92]?Qt::green:Qt::red),1));
    p.drawLine(1316,40,1300,40);
    p.drawLine(1316,41,1299,41);
    p.drawLine(1316,42,1300,42);
    p.drawLine(1309,37,1299,41);
    p.drawLine(1309,38,1299,41);
    p.drawLine(1309,39,1299,41);
    p.drawLine(1309,43,1299,41);
    p.drawLine(1309,44,1299,41);
    p.drawLine(1309,45,1299,41);
    p.end();
    lAMBottom->update();

    p.begin(const_cast<QPixmap*>(lABack->pixmap()));
    p.setPen(QPen(QBrush(mTrivium.mA[65]?Qt::green:Qt::red),3));
    p.drawLine(0,15,28,15);
    p.drawLine(28,15,28,47);
    p.setPen(QPen(QBrush(mTrivium.mA[65]?Qt::green:Qt::red),1));
    p.drawLine(24,40,28,50);
    p.drawLine(32,40,28,50);
    p.drawLine(25,40,28,50);
    p.drawLine(31,40,28,50);
    p.drawLine(26,40,28,50);
    p.drawLine(30,40,28,50);

    p.setPen(QPen(QBrush(mTrivium.mA[92]?Qt::green:Qt::red),1));
    p.drawLine(0,60,16,60);
    p.drawLine(0,61,17,61);
    p.drawLine(0,62,16,62);
    p.drawLine(7,57,17,61);
    p.drawLine(7,58,17,61);
    p.drawLine(7,59,17,61);
    p.drawLine(7,63,17,61);
    p.drawLine(7,64,17,61);
    p.drawLine(7,65,17,61);

    paintXOR( 18,51, (mTrivium.mA[65] != mTrivium.mA[92]?Qt::green:Qt::red), &p );

    p.setPen(QPen(QBrush(mTrivium.mA[65] != mTrivium.mA[92]?Qt::green:Qt::red),3));
    p.drawLine(28,72,28,123);
    p.drawLine(0,123,28,123);

    p.drawLine(39,61,70,61);

    p.end();
    lABack->update();

}

void MainWindow::paintXOR( int aX, int aY, const QColor& aColor, QPainter* aPainter){

    aPainter->setPen(QPen(QBrush(aColor),3));
    aPainter->drawEllipse(aX,aY,21,21);
    aPainter->setPen(QPen(QBrush(aColor),1));
    aPainter->drawLine(aX+9,aY,aX+9,aY+19);
    aPainter->drawLine(aX+10,aY,aX+10,aY+19);
    aPainter->drawLine(aX+11,aY,aX+11,aY+19);
    aPainter->drawLine(aX,aY+9,aX+19,aY+9);
    aPainter->drawLine(aX,aY+10,aX+19,aY+10);
    aPainter->drawLine(aX,aY+11,aX+19,aY+11);

};
void MainWindow::paintAND( int aX, int aY, const QColor& aColor, QPainter* aPainter){

    aPainter->setPen(QPen(QBrush(aColor),3));
    aPainter->eraseRect( aX,aY,26,18 );
    aPainter->drawRect( aX,aY,26,18 );
    aPainter->drawText( aX,aY,26,18, Qt::AlignHCenter | Qt::AlignVCenter ,QString("&") );

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

        if( vI == 65 || vI == 68 || vI == 90 || vI == 91 || vI == 92 ){
            if(mTrivium.mA[vI]){
                mA[vI]->setStyleSheet("QWidget#lbBit { border-style: solid; border-width: 2; border-color: rgb(0, 255, 0); }");
            } else {
                mA[vI]->setStyleSheet("QWidget#lbBit { border-style: solid; border-width: 2; border-color: rgb(255, 0, 0); }");
            }
        }
    }
    for( int vI = 0; vI < mTrivium.mB.size(); ++vI ){
        mB[vI]->setBit(mTrivium.mB[vI]);
    }
    for( int vI = 0; vI < mTrivium.mC.size(); ++vI ){
        mC[vI]->setBit(mTrivium.mC[vI]);
    }

    paintA();

};
}
