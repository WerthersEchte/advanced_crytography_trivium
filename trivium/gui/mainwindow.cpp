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
            if(mTrivium.mA[vI]){
                vBit->setStyleSheet("QWidget#lbBit { border-style: solid; border-width: 2; border-color: rgb(0, 255, 0); }");
            } else {
                vBit->setStyleSheet("QWidget#lbBit { border-style: solid; border-width: 2; border-color: rgb(255, 0, 0); }");
            }
        }

        fA->layout()->addWidget(vBit);
    }
    for( int vI = 0; vI < mTrivium.mB.size(); ++vI ){
        vBit = new Bit( mTrivium.mB[vI], vI+1 );
        vBit->setMaximumSize(14,40);
        vBit->setMinimumSize(14,40);
        mB.push_back(vBit);

        if( vI == 68 || vI == 77 || vI == 81 || vI == 82 || vI == 83 ){
            if(mTrivium.mB[vI]){
                vBit->setStyleSheet("QWidget#lbBit { border-style: solid; border-width: 2; border-color: rgb(0, 255, 0); }");
            } else {
                vBit->setStyleSheet("QWidget#lbBit { border-style: solid; border-width: 2; border-color: rgb(255, 0, 0); }");
            }
        }

        fB->layout()->addWidget(vBit);
    }
    for( int vI = 0; vI < mTrivium.mC.size(); ++vI ){
        vBit = new Bit( mTrivium.mC[vI], vI+1 );
        vBit->setMaximumSize(14,40);
        vBit->setMinimumSize(14,40);
        mC.push_back(vBit);

        if( vI == 65 || vI == 86 || vI == 108 || vI == 109 || vI == 110 ){
            if(mTrivium.mC[vI]){
                vBit->setStyleSheet("QWidget#lbBit { border-style: solid; border-width: 2; border-color: rgb(0, 255, 0); }");
            } else {
                vBit->setStyleSheet("QWidget#lbBit { border-style: solid; border-width: 2; border-color: rgb(255, 0, 0); }");
            }
        }

        fC->layout()->addWidget(vBit);
    }

    QPixmap *pixmap = new QPixmap(1317,40);
    pixmap->fill(Qt::transparent);
    lAMTop->setPixmap(*pixmap);
    pixmap = new QPixmap(70,142);
    pixmap->fill(Qt::transparent);
    lAFront->setPixmap(*pixmap);
    pixmap = new QPixmap(1317,60);
    pixmap->fill(Qt::transparent);
    lAMBottom->setPixmap(*pixmap);
    pixmap = new QPixmap(308,142);
    pixmap->fill(Qt::transparent);
    lABack->setPixmap(*pixmap);

    pixmap = new QPixmap(1191,40);
    pixmap->fill(Qt::transparent);
    lBMTop->setPixmap(*pixmap);
    pixmap = new QPixmap(70,142);
    pixmap->fill(Qt::transparent);
    lBFront->setPixmap(*pixmap);
    pixmap = new QPixmap(1191,60);
    pixmap->fill(Qt::transparent);
    lBMBottom->setPixmap(*pixmap);
    pixmap = new QPixmap(434,142);
    pixmap->fill(Qt::transparent);
    lBBack->setPixmap(*pixmap);

    pixmap = new QPixmap(1555,40);
    pixmap->fill(Qt::transparent);
    lCMTop->setPixmap(*pixmap);
    pixmap = new QPixmap(70,142);
    pixmap->fill(Qt::transparent);
    lCFront->setPixmap(*pixmap);
    pixmap = new QPixmap(1555,60);
    pixmap->fill(Qt::transparent);
    lCMBottom->setPixmap(*pixmap);
    pixmap = new QPixmap(70,142);
    pixmap->fill(Qt::transparent);
    lCBack->setPixmap(*pixmap);

    pixmap = new QPixmap(70,430);
    pixmap->fill(Qt::transparent);
    lAllBack->setPixmap(*pixmap);

    paintA();
    paintB();
    paintC();
    paintEnd();
};

void MainWindow::paintEnd(){

    QPainter p(const_cast<QPixmap*>(lAllBack->pixmap()));
    p.setPen(QPen(QBrush(mTrivium.mA[65] != mTrivium.mA[92]?Qt::green:Qt::red),3));
    p.drawLine(0,63,28,63);
    p.drawLine(28,63,28,190);
    p.setPen(QPen(QBrush(mTrivium.mA[65] != mTrivium.mA[92]?Qt::green:Qt::red),1));
    p.drawLine(24,184,28,194);
    p.drawLine(32,184,28,194);
    p.drawLine(25,184,28,194);
    p.drawLine(31,184,28,194);
    p.drawLine(26,184,28,194);
    p.drawLine(30,184,28,194);

    p.setPen(QPen(QBrush(mTrivium.mB[68] != mTrivium.mB[83]?Qt::green:Qt::red),1));
    p.drawLine(0,204,16,204);
    p.drawLine(0,205,17,205);
    p.drawLine(0,206,16,206);
    p.drawLine(7,201,17,205);
    p.drawLine(7,202,17,205);
    p.drawLine(7,203,17,205);
    p.drawLine(7,207,17,205);
    p.drawLine(7,208,17,205);
    p.drawLine(7,209,17,205);

    p.setPen(QPen(QBrush(mTrivium.mC[65] != mTrivium.mC[110]?Qt::green:Qt::red),3));
    p.drawLine(0,347,28,347);
    p.drawLine(28,347,28,220);
    p.setPen(QPen(QBrush(mTrivium.mC[65] != mTrivium.mC[110]?Qt::green:Qt::red),1));
    p.drawLine(24,227,28,217);
    p.drawLine(32,227,28,217);
    p.drawLine(25,227,28,217);
    p.drawLine(31,227,28,217);
    p.drawLine(26,227,28,217);
    p.drawLine(30,227,28,217);

    paintXOR( 18,195, (mTrivium.mA[65] != mTrivium.mA[92] != mTrivium.mB[68] != mTrivium.mB[83] != mTrivium.mC[65] != mTrivium.mC[110]?Qt::green:Qt::red), &p );
    p.setPen(QPen(QBrush(mTrivium.mA[65] != mTrivium.mA[92] != mTrivium.mB[68] != mTrivium.mB[83] != mTrivium.mC[65] != mTrivium.mC[110]?Qt::green:Qt::red),1));
    p.drawLine(39,204,55,204);
    p.drawLine(39,205,56,205);
    p.drawLine(39,206,55,206);
    p.drawLine(46,201,56,205);
    p.drawLine(46,202,56,205);
    p.drawLine(46,203,56,205);
    p.drawLine(46,207,56,205);
    p.drawLine(46,208,56,205);
    p.drawLine(46,209,56,205);

    p.end();
    lAllBack->update();

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
    p.drawLine(37,25,70,25);
    p.drawLine(37,25,37,47);
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
    p.drawLine(1,61,1,142);
    p.setPen(QPen(QBrush(mTrivium.mC[65] != mTrivium.mC[110] != (mTrivium.mC[109]&&mTrivium.mC[108])?Qt::green:Qt::red),1));
    p.drawLine(1,60,27,60);
    p.drawLine(1,61,28,61);
    p.drawLine(1,62,27,62);
    p.drawLine(17,57,27,61);
    p.drawLine(17,58,27,61);
    p.drawLine(17,59,27,61);
    p.drawLine(17,63,27,61);
    p.drawLine(17,64,27,61);
    p.drawLine(17,65,27,61);

    p.setPen(QPen(QBrush(mTrivium.mA[65] != mTrivium.mA[92] != (mTrivium.mA[90] && mTrivium.mA[91])?Qt::green:Qt::red),3));
    p.drawLine(10,123,10,142);
    p.drawLine(10,123,70,123);

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

    p.drawLine(39,61,308,61);

    p.end();
    lABack->update();

}

void MainWindow::paintB(){

    QPainter p(const_cast<QPixmap*>(lBMTop->pixmap()));
    p.setPen(QPen(QBrush(mTrivium.mB[77]?Qt::green:Qt::red),3));
    p.drawLine(1099,40,1099,25);
    p.drawLine(0,25,1099,25);
    p.setPen(QPen(QBrush(mTrivium.mB[68]?Qt::green:Qt::red),3));
    p.drawLine(973,40,973,15);
    p.drawLine(973,15,1191,15);
    p.end();
    lBMTop->update();


    p.begin(const_cast<QPixmap*>(lBFront->pixmap()));
    p.setPen(QPen(QBrush(mTrivium.mB[77]?Qt::green:Qt::red),3));
    p.drawLine(37,25,70,25);
    p.drawLine(37,25,37,47);
    p.setPen(QPen(QBrush(mTrivium.mB[77]?Qt::green:Qt::red),1));
    p.drawLine(34,40,38,50);
    p.drawLine(42,40,38,50);
    p.drawLine(35,40,38,50);
    p.drawLine(41,40,38,50);
    p.drawLine(36,40,38,50);
    p.drawLine(40,40,38,50);

    paintXOR( 28,51, (mTrivium.mA[65] != mTrivium.mA[92] != (mTrivium.mA[90]&&mTrivium.mA[91]) != mTrivium.mB[77]?Qt::green:Qt::red), &p );

    p.setPen(QPen(QBrush(mTrivium.mA[65] != mTrivium.mA[92] != (mTrivium.mA[90]&&mTrivium.mA[91]) != mTrivium.mB[77]?Qt::green:Qt::red),1));
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
    p.drawLine(1,0,1,142);


    p.setPen(QPen(QBrush(mTrivium.mA[65] != mTrivium.mA[92] != (mTrivium.mA[90] && mTrivium.mA[91])?Qt::green:Qt::red),3));
    p.drawLine(10,0,10,60);
    p.setPen(QPen(QBrush(mTrivium.mA[65] != mTrivium.mA[92] != (mTrivium.mA[90] && mTrivium.mA[91])?Qt::green:Qt::red),1));
    p.drawLine(10,60,27,60);
    p.drawLine(10,61,28,61);
    p.drawLine(10,62,27,62);
    p.drawLine(17,57,27,61);
    p.drawLine(17,58,27,61);
    p.drawLine(17,59,27,61);
    p.drawLine(17,63,27,61);
    p.drawLine(17,64,27,61);
    p.drawLine(17,65,27,61);

    p.setPen(QPen(QBrush(mTrivium.mB[68] != mTrivium.mB[83] != (mTrivium.mB[82] && mTrivium.mB[81])?Qt::green:Qt::red),3));
    p.drawLine(10,123,10,142);
    p.drawLine(10,123,70,123);

    p.end();
    lBFront->update();


    p.begin(const_cast<QPixmap*>(lBMBottom->pixmap()));
    p.setPen(QPen(QBrush(mTrivium.mB[81]?Qt::green:Qt::red),3));
    p.drawLine(1155,0,1155,5);
    p.setPen(QPen(QBrush(mTrivium.mB[82]?Qt::green:Qt::red),3));
    p.drawLine(1169,0,1169,5);
    paintAND( 1149,6, (mTrivium.mB[81] && mTrivium.mB[82]?Qt::green:Qt::red), &p );
    p.drawLine(1162,24,1162,30);
    paintXOR( 1152,31, (mTrivium.mB[68] != mTrivium.mB[83] != (mTrivium.mB[81] && mTrivium.mB[82])?Qt::green:Qt::red), &p );
    p.setPen(QPen(QBrush(mTrivium.mB[68] != mTrivium.mB[83] != (mTrivium.mB[81] && mTrivium.mB[82])?Qt::green:Qt::red),3));
    p.drawLine(0,41,1152,41);
    p.setPen(QPen(QBrush(mTrivium.mB[68] != mTrivium.mB[83]?Qt::green:Qt::red),1));
    p.drawLine(1191,40,1174,40);
    p.drawLine(1191,41,1173,41);
    p.drawLine(1191,42,1174,42);
    p.drawLine(1183,37,1173,41);
    p.drawLine(1183,38,1173,41);
    p.drawLine(1183,39,1173,41);
    p.drawLine(1183,43,1173,41);
    p.drawLine(1183,44,1173,41);
    p.drawLine(1183,45,1173,41);
    p.end();
    lBMBottom->update();

    p.begin(const_cast<QPixmap*>(lBBack->pixmap()));
    p.setPen(QPen(QBrush(mTrivium.mB[68]?Qt::green:Qt::red),3));
    p.drawLine(0,15,28,15);
    p.drawLine(28,15,28,47);
    p.setPen(QPen(QBrush(mTrivium.mB[68]?Qt::green:Qt::red),1));
    p.drawLine(24,40,28,50);
    p.drawLine(32,40,28,50);
    p.drawLine(25,40,28,50);
    p.drawLine(31,40,28,50);
    p.drawLine(26,40,28,50);
    p.drawLine(30,40,28,50);

    p.setPen(QPen(QBrush(mTrivium.mB[83]?Qt::green:Qt::red),1));
    p.drawLine(0,60,16,60);
    p.drawLine(0,61,17,61);
    p.drawLine(0,62,16,62);
    p.drawLine(7,57,17,61);
    p.drawLine(7,58,17,61);
    p.drawLine(7,59,17,61);
    p.drawLine(7,63,17,61);
    p.drawLine(7,64,17,61);
    p.drawLine(7,65,17,61);

    paintXOR( 18,51, (mTrivium.mB[68] != mTrivium.mB[83]?Qt::green:Qt::red), &p );

    p.setPen(QPen(QBrush(mTrivium.mB[68] != mTrivium.mB[83]?Qt::green:Qt::red),3));
    p.drawLine(28,72,28,123);
    p.drawLine(0,123,28,123);

    p.drawLine(39,61,434,61);

    p.end();
    lBBack->update();

}

void MainWindow::paintC(){

    QPainter p(const_cast<QPixmap*>(lCMTop->pixmap()));
    p.setPen(QPen(QBrush(mTrivium.mC[86]?Qt::green:Qt::red),3));
    p.drawLine(1214,40,1214,25);
    p.drawLine(0,25,1214,25);
    p.setPen(QPen(QBrush(mTrivium.mC[65]?Qt::green:Qt::red),3));
    p.drawLine(922,40,922,15);
    p.drawLine(922,15,1555,15);
    p.end();
    lCMTop->update();


    p.begin(const_cast<QPixmap*>(lCFront->pixmap()));
    p.setPen(QPen(QBrush(mTrivium.mC[86]?Qt::green:Qt::red),3));
    p.drawLine(37,25,70,25);
    p.drawLine(37,25,37,47);
    p.setPen(QPen(QBrush(mTrivium.mC[86]?Qt::green:Qt::red),1));
    p.drawLine(34,40,38,50);
    p.drawLine(42,40,38,50);
    p.drawLine(35,40,38,50);
    p.drawLine(41,40,38,50);
    p.drawLine(36,40,38,50);
    p.drawLine(40,40,38,50);

    paintXOR( 28,51, (mTrivium.mB[68] != mTrivium.mB[83] != (mTrivium.mB[81]&&mTrivium.mB[82]) != mTrivium.mC[86]?Qt::green:Qt::red), &p );

    p.setPen(QPen(QBrush(mTrivium.mB[68] != mTrivium.mB[83] != (mTrivium.mB[81]&&mTrivium.mB[82]) != mTrivium.mC[86]?Qt::green:Qt::red),1));
    p.drawLine(49,60,65,60);
    p.drawLine(49,61,67,61);
    p.drawLine(49,62,65,62);
    p.drawLine(57,57,67,61);
    p.drawLine(57,58,67,61);
    p.drawLine(57,59,67,61);
    p.drawLine(57,63,67,61);
    p.drawLine(57,64,67,61);
    p.drawLine(57,65,67,61);

    p.setPen(QPen(QBrush(mTrivium.mB[68] != mTrivium.mB[83] != (mTrivium.mB[81]&&mTrivium.mB[82])?Qt::green:Qt::red),3));
    p.drawLine(10,0,10,60);
    p.setPen(QPen(QBrush(mTrivium.mB[68] != mTrivium.mB[83] != (mTrivium.mB[81]&&mTrivium.mB[82])?Qt::green:Qt::red),1));
    p.drawLine(10,60,27,60);
    p.drawLine(10,61,28,61);
    p.drawLine(10,62,27,62);
    p.drawLine(17,57,27,61);
    p.drawLine(17,58,27,61);
    p.drawLine(17,59,27,61);
    p.drawLine(17,63,27,61);
    p.drawLine(17,64,27,61);
    p.drawLine(17,65,27,61);

    p.setPen(QPen(QBrush(mTrivium.mC[65] != mTrivium.mC[110] != (mTrivium.mC[109]&&mTrivium.mC[108])?Qt::green:Qt::red),3));
    p.drawLine(1,0,1,123);
    p.drawLine(1,123,70,123);

    p.end();
    lCFront->update();


    p.begin(const_cast<QPixmap*>(lCMBottom->pixmap()));
    p.setPen(QPen(QBrush(mTrivium.mC[108]?Qt::green:Qt::red),3));
    p.drawLine(1519,0,1519,5);
    p.setPen(QPen(QBrush(mTrivium.mC[109]?Qt::green:Qt::red),3));
    p.drawLine(1533,0,1533,5);
    paintAND( 1513,6, (mTrivium.mC[108] && mTrivium.mC[109]?Qt::green:Qt::red), &p );
    p.drawLine(1526,24,1526,30);
    paintXOR( 1516,31, (mTrivium.mC[65] != mTrivium.mC[110] != (mTrivium.mC[108] && mTrivium.mC[109])?Qt::green:Qt::red), &p );
    p.setPen(QPen(QBrush(mTrivium.mC[65] != mTrivium.mC[110] != (mTrivium.mC[108] && mTrivium.mC[109])?Qt::green:Qt::red),3));
    p.drawLine(0,41,1516,41);
    p.setPen(QPen(QBrush(mTrivium.mC[65] != mTrivium.mC[110]?Qt::green:Qt::red),1));
    p.drawLine(1555,40,1538,40);
    p.drawLine(1555,41,1537,41);
    p.drawLine(1555,42,1538,42);
    p.drawLine(1547,37,1537,41);
    p.drawLine(1547,38,1537,41);
    p.drawLine(1547,39,1537,41);
    p.drawLine(1547,43,1537,41);
    p.drawLine(1547,44,1537,41);
    p.drawLine(1547,45,1537,41);
    p.end();
    lCMBottom->update();

    p.begin(const_cast<QPixmap*>(lCBack->pixmap()));
    p.setPen(QPen(QBrush(mTrivium.mC[65]?Qt::green:Qt::red),3));
    p.drawLine(0,15,28,15);
    p.drawLine(28,15,28,47);
    p.setPen(QPen(QBrush(mTrivium.mC[65]?Qt::green:Qt::red),1));
    p.drawLine(24,40,28,50);
    p.drawLine(32,40,28,50);
    p.drawLine(25,40,28,50);
    p.drawLine(31,40,28,50);
    p.drawLine(26,40,28,50);
    p.drawLine(30,40,28,50);

    p.setPen(QPen(QBrush(mTrivium.mC[110]?Qt::green:Qt::red),1));
    p.drawLine(0,60,16,60);
    p.drawLine(0,61,17,61);
    p.drawLine(0,62,16,62);
    p.drawLine(7,57,17,61);
    p.drawLine(7,58,17,61);
    p.drawLine(7,59,17,61);
    p.drawLine(7,63,17,61);
    p.drawLine(7,64,17,61);
    p.drawLine(7,65,17,61);

    paintXOR( 18,51, (mTrivium.mC[65] != mTrivium.mC[110]?Qt::green:Qt::red), &p );

    p.setPen(QPen(QBrush(mTrivium.mC[65] != mTrivium.mC[110]?Qt::green:Qt::red),3));
    p.drawLine(28,72,28,123);
    p.drawLine(0,123,28,123);

    p.drawLine(39,61,70,61);

    p.end();
    lCBack->update();

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
    tEKeyStreamHex->setPlainText("");
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

        if( vI == 68 || vI == 77 || vI == 81 || vI == 82 || vI == 83 ){
            if(mTrivium.mB[vI]){
                mB[vI]->setStyleSheet("QWidget#lbBit { border-style: solid; border-width: 2; border-color: rgb(0, 255, 0); }");
            } else {
                mB[vI]->setStyleSheet("QWidget#lbBit { border-style: solid; border-width: 2; border-color: rgb(255, 0, 0); }");
            }
        }
    }
    for( int vI = 0; vI < mTrivium.mC.size(); ++vI ){
        mC[vI]->setBit(mTrivium.mC[vI]);

        if( vI == 65 || vI == 86 || vI == 108 || vI == 109 || vI == 110 ){
            if(mTrivium.mC[vI]){
                mC[vI]->setStyleSheet("QWidget#lbBit { border-style: solid; border-width: 2; border-color: rgb(0, 255, 0); }");
            } else {
                mC[vI]->setStyleSheet("QWidget#lbBit { border-style: solid; border-width: 2; border-color: rgb(255, 0, 0); }");
            }
        }
    }

    paintA();
    paintB();
    paintC();

    paintEnd();

};
}
