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

TriviumWidget::TriviumWidget( trivium::Trivium* aTrivium, QWidget *parent )
    : QWidget(parent),
    mTrivium(aTrivium),
    mA(),
    mB(),
    mC()
{
    setupUi(this);

    trivium::Bit* vBit;

    for( int vI = 0; vI < mTrivium->mA.size(); ++vI ){
        vBit = new Bit( mTrivium->mA[vI], vI+1 );
        vBit->setMaximumSize(14,40);
        vBit->setMinimumSize(14,40);
        mA.push_back(vBit);

        if( vI == 68 || vI == 65 || vI == 90 || vI == 91 || vI == 92 ){
            if(mTrivium->mA[vI]){
                vBit->setStyleSheet("QWidget#lbBit { border-style: solid; border-width: 2; border-color: rgb(0, 255, 0); }");
            } else {
                vBit->setStyleSheet("QWidget#lbBit { border-style: solid; border-width: 2; border-color: rgb(255, 0, 0); }");
            }
        }

        fA->layout()->addWidget(vBit);
    }
    for( int vI = 0; vI < mTrivium->mB.size(); ++vI ){
        vBit = new Bit( mTrivium->mB[vI], vI+1 );
        vBit->setMaximumSize(14,40);
        vBit->setMinimumSize(14,40);
        mB.push_back(vBit);

        if( vI == 68 || vI == 77 || vI == 81 || vI == 82 || vI == 83 ){
            if(mTrivium->mB[vI]){
                vBit->setStyleSheet("QWidget#lbBit { border-style: solid; border-width: 2; border-color: rgb(0, 255, 0); }");
            } else {
                vBit->setStyleSheet("QWidget#lbBit { border-style: solid; border-width: 2; border-color: rgb(255, 0, 0); }");
            }
        }

        fB->layout()->addWidget(vBit);
    }
    for( int vI = 0; vI < mTrivium->mC.size(); ++vI ){
        vBit = new Bit( mTrivium->mC[vI], vI+1 );
        vBit->setMaximumSize(14,40);
        vBit->setMinimumSize(14,40);
        mC.push_back(vBit);

        if( vI == 65 || vI == 86 || vI == 108 || vI == 109 || vI == 110 ){
            if(mTrivium->mC[vI]){
                vBit->setStyleSheet("QWidget#lbBit { border-style: solid; border-width: 2; border-color: rgb(0, 255, 0); }");
            } else {
                vBit->setStyleSheet("QWidget#lbBit { border-style: solid; border-width: 2; border-color: rgb(255, 0, 0); }");
            }
        }

        fC->layout()->addWidget(vBit);
    }

};

void TriviumWidget::paintEvent(QPaintEvent *mEvent){

    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing, true);
    //A[69]
    p.setPen(QPen(QBrush(mTrivium->mA[68]?Qt::green:Qt::red),3));
    p.drawLine( (wAllFront->x() + wAllA->x() + wAMiddle->x() + wA->x()),(wAllFront->y() + wAllA->y() + wAMiddle->y() + wA->y() + wA->size().height()/2 - 37), (wAllFront->x() + wAllA->x() + wAMiddle->x() + wA->x() + fA->x() + mA[68]->x() + mA[68]->size().width()/2), (wAllFront->y() + wAllA->y() + wAMiddle->y() + wA->y() + wA->size().height()/2 - 37));
    p.drawLine( (wAllFront->x() + wAllA->x() + wAMiddle->x() + wA->x() + fA->x() + mA[68]->x() + mA[68]->size().width()/2), (wAllFront->y() + wAllA->y() + wAMiddle->y() + wA->y() + wA->size().height()/2 - 37), (wAllFront->x() + wAllA->x() + wAMiddle->x() + wA->x() + fA->x() + mA[68]->x() + mA[68]->size().width()/2), (wAllFront->y() + wAllA->y() + wAMiddle->y() + wA->y() ) );

    //intoA
    paintXorFront( (wAllFront->x() + wAllA->x() + wAMiddle->x() + wA->x() - 57), (wAllFront->y() + wAllA->y() + wAMiddle->y() + wA->y() + wA->size().height()/2 - 37), (mTrivium->mA[68]?Qt::green:Qt::red), (mTrivium->mC[65] != mTrivium->mC[110] != (mTrivium->mC[109]&&mTrivium->mC[108])?Qt::green:Qt::red), &p );

    //A[66]
    p.setPen(QPen(QBrush(mTrivium->mA[65]?Qt::green:Qt::red),3));
    p.drawLine( (wAllFront->x() + wAllA->x() + wAMiddle->x() + wA->x() + wA->size().width()), (wAllFront->y() + wAllA->y() + wAMiddle->y() + wA->y() + wA->size().height()/2 - 47), (wAllFront->x() + wAllA->x() + wAMiddle->x() + wA->x() + fA->x() + mA[65]->x() + mA[65]->size().width()/2), (wAllFront->y() + wAllA->y() + wAMiddle->y() + wA->y() + wA->size().height()/2 - 47));
    p.drawLine( (wAllFront->x() + wAllA->x() + wAMiddle->x() + wA->x() + fA->x() + mA[65]->x() + mA[65]->size().width()/2), (wAllFront->y() + wAllA->y() + wAMiddle->y() + wA->y() + wA->size().height()/2 - 47), (wAllFront->x() + wAllA->x() + wAMiddle->x() + wA->x() + fA->x() + mA[65]->x() + mA[65]->size().width()/2), (wAllFront->y() + wAllA->y() + wAMiddle->y() + wA->y() ) );

    //outofA
    paintXorBack( (wAllFront->x() + wAllA->x() + wAMiddle->x() + wAMiddle->size().width()), (wAllFront->y() + wAllA->y() + wAMiddle->y() + wA->y() + wA->size().height()/2 - 47), (mTrivium->mA[65]?Qt::green:Qt::red), (mTrivium->mA[92]?Qt::green:Qt::red), &p );

    //fromAtoB
    paintAndXor( (wAllFront->x() + wAllA->x() + wAMiddle->x() + wA->x() + fA->x() + mA[90]->x() + mA[90]->size().width()/2), (wAllFront->y() + wAllA->y() + wAMiddle->y() + wA->y() + wA->size().height()), (mTrivium->mA[90]?Qt::green:Qt::red), (mTrivium->mA[91]?Qt::green:Qt::red), (mTrivium->mA[65] != mTrivium->mA[92] != (mTrivium->mA[90] && mTrivium->mA[91])?Qt::green:Qt::red),&p);
    p.setPen(QPen(QBrush(mTrivium->mA[65] != mTrivium->mA[92] != (mTrivium->mA[90] && mTrivium->mA[91])?Qt::green:Qt::red),3));
    p.drawLine(     (wAllFront->x() + wAllA->x() + wAMiddle->x() + wA->x() + fA->x() + mA[90]->x() + mA[90]->size().width()/2),
                    (wAllFront->y() + wAllA->y() + wAMiddle->y() + wA->y() + wA->size().height() + 41),
                    (wAllFront->x() + wAllA->x() + wAMiddle->x() + wA->x() - 57),
                    (wAllFront->y() + wAllA->y() + wAMiddle->y() + wA->y() + wA->size().height() + 41) );
    p.drawLine(     (wAllFront->x() + wAllA->x() + wAMiddle->x() + wA->x() - 57),
                    (wAllFront->y() + wAllA->y() + wAMiddle->y() + wA->y() + wA->size().height() + 41),
                    (wAllFront->x() + wAllA->x() + wAMiddle->x() + wA->x() - 57),
                    (wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 - 1) );
    //B[78]
    p.setPen(QPen(QBrush(mTrivium->mB[77]?Qt::green:Qt::red),3));
    p.drawLine( (wAllFront->x() + wAllB->x() + wBMiddle->x() + wB->x()),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 - 37), (wAllFront->x() + wAllB->x() + wBMiddle->x() + wB->x() + fB->x() + mB[77]->x() + mB[77]->size().width()/2), (wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 - 37));
    p.drawLine( (wAllFront->x() + wAllB->x() + wBMiddle->x() + wB->x() + fB->x() + mB[77]->x() + mA[77]->size().width()/2), (wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 - 37), (wAllFront->x() + wAllB->x() + wBMiddle->x() + wB->x() + fB->x() + mB[77]->x() + mB[77]->size().width()/2), (wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() ) );

    //intoB
    paintXorFront( (wAllFront->x() + wAllB->x() + wBMiddle->x() + wB->x() - 57), (wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 - 37), (mTrivium->mB[77]?Qt::green:Qt::red), (mTrivium->mA[65] != mTrivium->mA[92] != (mTrivium->mA[90]&&mTrivium->mA[91])?Qt::green:Qt::red), &p );

    //B[69]
    p.setPen(QPen(QBrush(mTrivium->mB[68]?Qt::green:Qt::red),3));
    p.drawLine( (wAllFront->x() + wAllB->x() + wBMiddle->x() + wB->x() + wB->size().width()), (wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 - 47), (wAllFront->x() + wAllB->x() + wBMiddle->x() + wB->x() + fB->x() + mB[68]->x() + mB[68]->size().width()/2), (wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 - 47));
    p.drawLine( (wAllFront->x() + wAllB->x() + wBMiddle->x() + wB->x() + fB->x() + mB[68]->x() + mA[68]->size().width()/2), (wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 - 47), (wAllFront->x() + wAllB->x() + wBMiddle->x() + wB->x() + fB->x() + mB[68]->x() + mB[68]->size().width()/2), (wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() ) );

    //outofB
    paintXorBack( (wAllFront->x() + wAllB->x() + wBMiddle->x() + wBMiddle->size().width()), (wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 - 47), (mTrivium->mB[68]?Qt::green:Qt::red), (mTrivium->mB[83]?Qt::green:Qt::red), &p );

    //fromBtoC
    paintAndXor( (wAllFront->x() + wAllB->x() + wBMiddle->x() + wB->x() + fB->x() + mB[81]->x() + mB[81]->size().width()/2), (wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()), (mTrivium->mB[81]?Qt::green:Qt::red), (mTrivium->mB[82]?Qt::green:Qt::red), (mTrivium->mB[68] != mTrivium->mB[83] != (mTrivium->mB[81] && mTrivium->mB[82])?Qt::green:Qt::red),&p);
    p.setPen(QPen(QBrush(mTrivium->mB[68] != mTrivium->mB[83] != (mTrivium->mB[81] && mTrivium->mB[82])?Qt::green:Qt::red),3));
    p.drawLine(     (wAllFront->x() + wAllB->x() + wBMiddle->x() + wB->x() + fB->x() + mB[81]->x() + mB[81]->size().width()/2),
                    (wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height() + 41),
                    (wAllFront->x() + wAllB->x() + wBMiddle->x() + wB->x() - 57),
                    (wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height() + 41) );
    p.drawLine(     (wAllFront->x() + wAllB->x() + wBMiddle->x() + wB->x() - 57),
                    (wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height() + 41),
                    (wAllFront->x() + wAllB->x() + wBMiddle->x() + wB->x() - 57),
                    (wAllFront->y() + wAllC->y() + wCMiddle->y() + wC->y() + wC->size().height()/2 - 1) );

    //C[87]
    p.setPen(QPen(QBrush(mTrivium->mC[86]?Qt::green:Qt::red),3));
    p.drawLine( (wAllFront->x() + wAllC->x() + wCMiddle->x() + wC->x()),(wAllFront->y() + wAllC->y() + wCMiddle->y() + wC->y() + wC->size().height()/2 - 37), (wAllFront->x() + wAllC->x() + wCMiddle->x() + wC->x() + fC->x() + mC[86]->x() + mC[86]->size().width()/2), (wAllFront->y() + wAllC->y() + wCMiddle->y() + wC->y() + wC->size().height()/2 - 37));
    p.drawLine( (wAllFront->x() + wAllC->x() + wCMiddle->x() + wC->x() + fC->x() + mC[86]->x() + mC[86]->size().width()/2), (wAllFront->y() + wAllC->y() + wAMiddle->y() + wC->y() + wC->size().height()/2 - 37), (wAllFront->x() + wAllC->x() + wCMiddle->x() + wC->x() + fC->x() + mC[86]->x() + mC[86]->size().width()/2), (wAllFront->y() + wAllC->y() + wCMiddle->y() + wC->y() ) );

    //intoC
    paintXorFront( (wAllFront->x() + wAllC->x() + wCMiddle->x() + wC->x() - 57), (wAllFront->y() + wAllC->y() + wCMiddle->y() + wC->y() + wC->size().height()/2 - 37), (mTrivium->mC[86]?Qt::green:Qt::red), (mTrivium->mB[68] != mTrivium->mB[83] != (mTrivium->mB[81]&&mTrivium->mB[82])?Qt::green:Qt::red), &p );

    //C[66]
    p.setPen(QPen(QBrush(mTrivium->mC[65]?Qt::green:Qt::red),3));
    p.drawLine( (wAllFront->x() + wAllC->x() + wCMiddle->x() + wC->x() + wC->size().width()),(wAllFront->y() + wAllC->y() + wCMiddle->y() + wC->y() + wC->size().height()/2 - 47), (wAllFront->x() + wAllC->x() + wCMiddle->x() + wC->x() + fC->x() + mC[65]->x() + mC[65]->size().width()/2), (wAllFront->y() + wAllC->y() + wCMiddle->y() + wC->y() + wC->size().height()/2 - 47));
    p.drawLine( (wAllFront->x() + wAllC->x() + wCMiddle->x() + wC->x() + fC->x() + mC[65]->x() + mC[65]->size().width()/2), (wAllFront->y() + wAllC->y() + wAMiddle->y() + wC->y() + wC->size().height()/2 - 47), (wAllFront->x() + wAllC->x() + wCMiddle->x() + wC->x() + fC->x() + mC[65]->x() + mC[65]->size().width()/2), (wAllFront->y() + wAllC->y() + wCMiddle->y() + wC->y() ) );

    //outofC
    paintXorBack( (wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width()), (wAllFront->y() + wAllC->y() + wCMiddle->y() + wC->y() + wC->size().height()/2 - 47), (mTrivium->mC[65]?Qt::green:Qt::red), (mTrivium->mC[110]?Qt::green:Qt::red), &p );

    //fromCtoA
    paintAndXor( (wAllFront->x() + wAllC->x() + wCMiddle->x() + wC->x() + fC->x() + mC[108]->x() + mC[108]->size().width()/2), (wAllFront->y() + wAllC->y() + wCMiddle->y() + wC->y() + wC->size().height()), (mTrivium->mC[108]?Qt::green:Qt::red), (mTrivium->mC[109]?Qt::green:Qt::red), (mTrivium->mC[65] != mTrivium->mC[110] != (mTrivium->mC[108] && mTrivium->mC[109])?Qt::green:Qt::red),&p);
    p.setPen(QPen(QBrush(mTrivium->mC[65] != mTrivium->mC[110] != (mTrivium->mC[108] && mTrivium->mC[109])?Qt::green:Qt::red),3));
    p.drawLine( (wAllFront->x() + wAllC->x() + wCMiddle->x() + wC->x() + fC->x() + mC[108]->x() + mC[108]->size().width()/2), (wAllFront->y() + wAllC->y() + wCMiddle->y() + wC->y() + wC->size().height() + 41), (1), (wAllFront->y() + wAllC->y() + wCMiddle->y() + wC->y() + wC->size().height() + 41) );
    p.drawLine( (1), (wAllFront->y() + wAllC->y() + wCMiddle->y() + wC->y() + wC->size().height() + 41), (1), (wAllFront->y() + wAllA->y() + wAMiddle->y() + wA->y() + wA->size().height()/2 - 1) );
    p.drawLine( (1), (wAllFront->y() + wAllA->y() + wAMiddle->y() + wA->y() + wA->size().height()/2 - 1), (wAllFront->x() + wAllC->x() + wCMiddle->x() + wC->x() - 57), (wAllFront->y() + wAllA->y() + wAMiddle->y() + wA->y() + wA->size().height()/2 - 1) );

    //Output
    p.setPen(QPen(QBrush(mTrivium->mA[65] != mTrivium->mA[92]?Qt::green:Qt::red),3));
    p.drawLine((wAllFront->x() + wAllA->x() + wAMiddle->x() + wAMiddle->size().width() + 70 ),(wAllFront->y() + wAllA->y() + wAMiddle->y() + wA->y() + wA->size().height()/2 - 1),(wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 70 ),(wAllFront->y() + wAllA->y() + wAMiddle->y() + wA->y() + wA->size().height()/2 - 1));
    p.drawLine((wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 70 ),(wAllFront->y() + wAllA->y() + wAMiddle->y() + wA->y() + wA->size().height()/2 - 1),(wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 70 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 - 16));
    p.setPen(QPen(QBrush(mTrivium->mA[65] != mTrivium->mA[92]?Qt::green:Qt::red),1));
    p.drawLine((wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 66 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 - 21),(wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 71 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 - 11));
    p.drawLine((wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 75 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 - 21),(wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 71 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 - 11));
    p.drawLine((wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 67 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 - 21),(wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 71 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 - 11));
    p.drawLine((wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 74 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 - 21),(wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 71 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 - 11));
    p.drawLine((wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 68 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 - 21),(wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 71 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 - 11));
    p.drawLine((wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 73 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 - 21),(wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 71 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 - 11));

    p.setPen(QPen(QBrush(mTrivium->mB[68] != mTrivium->mB[83]?Qt::green:Qt::red),1));
    p.drawLine((wAllFront->x() + wAllB->x() + wBMiddle->x() + wBMiddle->size().width() + 70 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 - 2),(wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 55 ), (wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 - 2));
    p.drawLine((wAllFront->x() + wAllB->x() + wBMiddle->x() + wBMiddle->size().width() + 70 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 - 1),(wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 56 ), (wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 - 1));
    p.drawLine((wAllFront->x() + wAllB->x() + wBMiddle->x() + wBMiddle->size().width() + 70 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2),(wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 55 ), (wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2));
    p.drawLine((wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 50 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 - 5),(wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 60 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 - 1));
    p.drawLine((wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 50 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 - 4),(wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 60 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 - 1));
    p.drawLine((wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 50 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 - 3),(wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 60 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 - 1));
    p.drawLine((wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 50 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 + 1),(wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 60 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 - 1));
    p.drawLine((wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 50 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 + 2),(wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 60 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 - 1));
    p.drawLine((wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 50 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 + 3),(wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 60 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 - 1));


    p.setPen(QPen(QBrush(mTrivium->mC[65] != mTrivium->mC[110]?Qt::green:Qt::red),3));
    p.drawLine((wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 71 ),(wAllFront->y() + wAllC->y() + wCMiddle->y() + wC->y() + wC->size().height()/2 - 1),(wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 71 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 + 17));
    p.setPen(QPen(QBrush(mTrivium->mC[65] != mTrivium->mC[110]?Qt::green:Qt::red),1));
    p.drawLine((wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 73 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 + 22),(wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 71 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 + 12));
    p.drawLine((wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 74 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 + 22),(wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 71 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 + 12));
    p.drawLine((wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 75 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 + 22),(wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 71 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 + 12));
    p.drawLine((wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 69 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 + 22),(wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 71 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 + 12));
    p.drawLine((wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 68 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 + 22),(wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 71 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 + 12));
    p.drawLine((wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 67 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 + 22),(wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 71 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 + 12));

    paintXOR( (wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 61 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 -11), (mTrivium->mA[65] != mTrivium->mA[92] != mTrivium->mB[68] != mTrivium->mB[83] != mTrivium->mC[65] != mTrivium->mC[110]?Qt::green:Qt::red), &p );
    p.setPen(QPen(QBrush(mTrivium->mA[65] != mTrivium->mA[92] != mTrivium->mB[68] != mTrivium->mB[83] != mTrivium->mC[65] != mTrivium->mC[110]?Qt::green:Qt::red),1));
    p.drawLine((wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 82 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 - 2),(wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 99 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 - 2));
    p.drawLine((wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 82 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 - 1),(wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 100 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 - 1));
    p.drawLine((wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 82 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2),(wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 99 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2));
    p.drawLine((wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 90 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 - 5),(wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 100 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 - 1));
    p.drawLine((wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 90 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 - 4),(wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 100 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 - 1));
    p.drawLine((wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 90 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 - 3),(wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 100 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 - 1));
    p.drawLine((wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 90 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 + 1),(wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 100 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 - 1));
    p.drawLine((wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 90 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 + 2),(wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 100 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 - 1));
    p.drawLine((wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 90 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 + 3),(wAllFront->x() + wAllC->x() + wCMiddle->x() + wCMiddle->size().width() + 100 ),(wAllFront->y() + wAllB->y() + wBMiddle->y() + wB->y() + wB->size().height()/2 - 1));

    p.end();

};
/*
void TriviumWidget::paintEnd(){

    QPainter p(const_cast<QPixmap*>(lAllBack->pixmap()));
    p.setPen(QPen(QBrush(mTrivium->mA[65] != mTrivium->mA[92]?Qt::green:Qt::red),3));
    p.drawLine(0,63,28,63);
    p.drawLine(28,63,28,190);
    p.setPen(QPen(QBrush(mTrivium->mA[65] != mTrivium->mA[92]?Qt::green:Qt::red),1));
    p.drawLine(24,184,28,194);
    p.drawLine(32,184,28,194);
    p.drawLine(25,184,28,194);
    p.drawLine(31,184,28,194);
    p.drawLine(26,184,28,194);
    p.drawLine(30,184,28,194);

    p.setPen(QPen(QBrush(mTrivium->mB[68] != mTrivium->mB[83]?Qt::green:Qt::red),1));
    p.drawLine(0,204,16,204);
    p.drawLine(0,205,17,205);
    p.drawLine(0,206,16,206);
    p.drawLine(7,201,17,205);
    p.drawLine(7,202,17,205);
    p.drawLine(7,203,17,205);
    p.drawLine(7,207,17,205);
    p.drawLine(7,208,17,205);
    p.drawLine(7,209,17,205);

    p.setPen(QPen(QBrush(mTrivium->mC[65] != mTrivium->mC[110]?Qt::green:Qt::red),3));
    p.drawLine(0,347,28,347);
    p.drawLine(28,347,28,220);
    p.setPen(QPen(QBrush(mTrivium->mC[65] != mTrivium->mC[110]?Qt::green:Qt::red),1));
    p.drawLine(24,227,28,217);
    p.drawLine(32,227,28,217);
    p.drawLine(25,227,28,217);
    p.drawLine(31,227,28,217);
    p.drawLine(26,227,28,217);
    p.drawLine(30,227,28,217);

    paintXOR( 18,195, (mTrivium->mA[65] != mTrivium->mA[92] != mTrivium->mB[68] != mTrivium->mB[83] != mTrivium->mC[65] != mTrivium->mC[110]?Qt::green:Qt::red), &p );
    p.setPen(QPen(QBrush(mTrivium->mA[65] != mTrivium->mA[92] != mTrivium->mB[68] != mTrivium->mB[83] != mTrivium->mC[65] != mTrivium->mC[110]?Qt::green:Qt::red),1));
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

void TriviumWidget::paintA(){

    QPainter p(const_cast<QPixmap*>(lAMTop->pixmap()));
    p.setPen(QPen(QBrush(mTrivium->mA[68]?Qt::green:Qt::red),3));
    p.drawLine(973,40,973,25);
    p.drawLine(0,25,973,25);
    p.setPen(QPen(QBrush(mTrivium->mA[65]?Qt::green:Qt::red),3));
    p.drawLine(931,40,931,15);
    p.drawLine(931,15,1317,15);
    p.end();
    lAMTop->update();


    p.begin(const_cast<QPixmap*>(lAFront->pixmap()));
    p.setPen(QPen(QBrush(mTrivium->mA[68]?Qt::green:Qt::red),3));
    p.drawLine(37,25,70,25);
    p.drawLine(37,25,37,47);
    p.setPen(QPen(QBrush(mTrivium->mA[68]?Qt::green:Qt::red),1));
    p.drawLine(34,40,38,50);
    p.drawLine(42,40,38,50);
    p.drawLine(35,40,38,50);
    p.drawLine(41,40,38,50);
    p.drawLine(36,40,38,50);
    p.drawLine(40,40,38,50);

    paintXOR( 28,51, ((mTrivium->mC[65] != mTrivium->mC[110] != (mTrivium->mC[109]&&mTrivium->mC[108]) != mTrivium->mA[68])?Qt::green:Qt::red), &p );

    p.setPen(QPen(QBrush(mTrivium->mC[65] != mTrivium->mC[110] != (mTrivium->mC[109]&&mTrivium->mC[108]) != mTrivium->mA[68]?Qt::green:Qt::red),1));
    p.drawLine(49,60,65,60);
    p.drawLine(49,61,67,61);
    p.drawLine(49,62,65,62);
    p.drawLine(57,57,67,61);
    p.drawLine(57,58,67,61);
    p.drawLine(57,59,67,61);
    p.drawLine(57,63,67,61);
    p.drawLine(57,64,67,61);
    p.drawLine(57,65,67,61);

    p.setPen(QPen(QBrush(mTrivium->mC[65] != mTrivium->mC[110] != (mTrivium->mC[109]&&mTrivium->mC[108])?Qt::green:Qt::red),3));
    p.drawLine(1,61,1,142);
    p.setPen(QPen(QBrush(mTrivium->mC[65] != mTrivium->mC[110] != (mTrivium->mC[109]&&mTrivium->mC[108])?Qt::green:Qt::red),1));
    p.drawLine(1,60,27,60);
    p.drawLine(1,61,28,61);
    p.drawLine(1,62,27,62);
    p.drawLine(17,57,27,61);
    p.drawLine(17,58,27,61);
    p.drawLine(17,59,27,61);
    p.drawLine(17,63,27,61);
    p.drawLine(17,64,27,61);
    p.drawLine(17,65,27,61);

    p.setPen(QPen(QBrush(mTrivium->mA[65] != mTrivium->mA[92] != (mTrivium->mA[90] && mTrivium->mA[91])?Qt::green:Qt::red),3));
    p.drawLine(10,123,10,142);
    p.drawLine(10,123,70,123);

    p.end();
    lAFront->update();


    p.begin(const_cast<QPixmap*>(lAMBottom->pixmap()));
    p.setPen(QPen(QBrush(mTrivium->mA[90]?Qt::green:Qt::red),3));
    p.drawLine(1281,0,1281,5);
    p.setPen(QPen(QBrush(mTrivium->mA[91]?Qt::green:Qt::red),3));
    p.drawLine(1295,0,1295,5);
    paintAND( 1275,6, (mTrivium->mA[90] && mTrivium->mA[91]?Qt::green:Qt::red), &p );
    p.drawLine(1288,24,1288,30);
    paintXOR( 1278,31, (mTrivium->mA[65] != mTrivium->mA[92] != (mTrivium->mA[90] && mTrivium->mA[91])?Qt::green:Qt::red), &p );
    p.setPen(QPen(QBrush(mTrivium->mA[65] != mTrivium->mA[92] != (mTrivium->mA[90] && mTrivium->mA[91])?Qt::green:Qt::red),3));
    p.drawLine(0,41,1278,41);
    p.setPen(QPen(QBrush(mTrivium->mA[65] != mTrivium->mA[92]?Qt::green:Qt::red),1));
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
    p.setPen(QPen(QBrush(mTrivium->mA[65]?Qt::green:Qt::red),3));
    p.drawLine(0,15,28,15);
    p.drawLine(28,15,28,47);
    p.setPen(QPen(QBrush(mTrivium->mA[65]?Qt::green:Qt::red),1));
    p.drawLine(24,40,28,50);
    p.drawLine(32,40,28,50);
    p.drawLine(25,40,28,50);
    p.drawLine(31,40,28,50);
    p.drawLine(26,40,28,50);
    p.drawLine(30,40,28,50);

    p.setPen(QPen(QBrush(mTrivium->mA[92]?Qt::green:Qt::red),1));
    p.drawLine(0,60,16,60);
    p.drawLine(0,61,17,61);
    p.drawLine(0,62,16,62);
    p.drawLine(7,57,17,61);
    p.drawLine(7,58,17,61);
    p.drawLine(7,59,17,61);
    p.drawLine(7,63,17,61);
    p.drawLine(7,64,17,61);
    p.drawLine(7,65,17,61);

    paintXOR( 18,51, (mTrivium->mA[65] != mTrivium->mA[92]?Qt::green:Qt::red), &p );

    p.setPen(QPen(QBrush(mTrivium->mA[65] != mTrivium->mA[92]?Qt::green:Qt::red),3));
    p.drawLine(28,72,28,123);
    p.drawLine(0,123,28,123);

    p.drawLine(39,61,308,61);

    p.end();
    lABack->update();

}

void TriviumWidget::paintB(){

    QPainter p(const_cast<QPixmap*>(lBMTop->pixmap()));
    p.setPen(QPen(QBrush(mTrivium->mB[77]?Qt::green:Qt::red),3));
    p.drawLine(1099,40,1099,25);
    p.drawLine(0,25,1099,25);
    p.setPen(QPen(QBrush(mTrivium->mB[68]?Qt::green:Qt::red),3));
    p.drawLine(973,40,973,15);
    p.drawLine(973,15,1191,15);
    p.end();
    lBMTop->update();


    p.begin(const_cast<QPixmap*>(lBFront->pixmap()));
    p.setPen(QPen(QBrush(mTrivium->mB[77]?Qt::green:Qt::red),3));
    p.drawLine(37,25,70,25);
    p.drawLine(37,25,37,47);
    p.setPen(QPen(QBrush(mTrivium->mB[77]?Qt::green:Qt::red),1));
    p.drawLine(34,40,38,50);
    p.drawLine(42,40,38,50);
    p.drawLine(35,40,38,50);
    p.drawLine(41,40,38,50);
    p.drawLine(36,40,38,50);
    p.drawLine(40,40,38,50);

    paintXOR( 28,51, (mTrivium->mA[65] != mTrivium->mA[92] != (mTrivium->mA[90]&&mTrivium->mA[91]) != mTrivium->mB[77]?Qt::green:Qt::red), &p );

    p.setPen(QPen(QBrush(mTrivium->mA[65] != mTrivium->mA[92] != (mTrivium->mA[90]&&mTrivium->mA[91]) != mTrivium->mB[77]?Qt::green:Qt::red),1));
    p.drawLine(49,60,65,60);
    p.drawLine(49,61,67,61);
    p.drawLine(49,62,65,62);
    p.drawLine(57,57,67,61);
    p.drawLine(57,58,67,61);
    p.drawLine(57,59,67,61);
    p.drawLine(57,63,67,61);
    p.drawLine(57,64,67,61);
    p.drawLine(57,65,67,61);

    p.setPen(QPen(QBrush(mTrivium->mC[65] != mTrivium->mC[110] != (mTrivium->mC[109]&&mTrivium->mC[108])?Qt::green:Qt::red),3));
    p.drawLine(1,0,1,142);


    p.setPen(QPen(QBrush(mTrivium->mA[65] != mTrivium->mA[92] != (mTrivium->mA[90] && mTrivium->mA[91])?Qt::green:Qt::red),3));
    p.drawLine(10,0,10,60);
    p.setPen(QPen(QBrush(mTrivium->mA[65] != mTrivium->mA[92] != (mTrivium->mA[90] && mTrivium->mA[91])?Qt::green:Qt::red),1));
    p.drawLine(10,60,27,60);
    p.drawLine(10,61,28,61);
    p.drawLine(10,62,27,62);
    p.drawLine(17,57,27,61);
    p.drawLine(17,58,27,61);
    p.drawLine(17,59,27,61);
    p.drawLine(17,63,27,61);
    p.drawLine(17,64,27,61);
    p.drawLine(17,65,27,61);

    p.setPen(QPen(QBrush(mTrivium->mB[68] != mTrivium->mB[83] != (mTrivium->mB[82] && mTrivium->mB[81])?Qt::green:Qt::red),3));
    p.drawLine(10,123,10,142);
    p.drawLine(10,123,70,123);

    p.end();
    lBFront->update();


    p.begin(const_cast<QPixmap*>(lBMBottom->pixmap()));
    p.setPen(QPen(QBrush(mTrivium->mB[81]?Qt::green:Qt::red),3));
    p.drawLine(1155,0,1155,5);
    p.setPen(QPen(QBrush(mTrivium->mB[82]?Qt::green:Qt::red),3));
    p.drawLine(1169,0,1169,5);
    paintAND( 1149,6, (mTrivium->mB[81] && mTrivium->mB[82]?Qt::green:Qt::red), &p );
    p.drawLine(1162,24,1162,30);
    paintXOR( 1152,31, (mTrivium->mB[68] != mTrivium->mB[83] != (mTrivium->mB[81] && mTrivium->mB[82])?Qt::green:Qt::red), &p );
    p.setPen(QPen(QBrush(mTrivium->mB[68] != mTrivium->mB[83] != (mTrivium->mB[81] && mTrivium->mB[82])?Qt::green:Qt::red),3));
    p.drawLine(0,41,1152,41);
    p.setPen(QPen(QBrush(mTrivium->mB[68] != mTrivium->mB[83]?Qt::green:Qt::red),1));
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
    p.setPen(QPen(QBrush(mTrivium->mB[68]?Qt::green:Qt::red),3));
    p.drawLine(0,15,28,15);
    p.drawLine(28,15,28,47);
    p.setPen(QPen(QBrush(mTrivium->mB[68]?Qt::green:Qt::red),1));
    p.drawLine(24,40,28,50);
    p.drawLine(32,40,28,50);
    p.drawLine(25,40,28,50);
    p.drawLine(31,40,28,50);
    p.drawLine(26,40,28,50);
    p.drawLine(30,40,28,50);

    p.setPen(QPen(QBrush(mTrivium->mB[83]?Qt::green:Qt::red),1));
    p.drawLine(0,60,16,60);
    p.drawLine(0,61,17,61);
    p.drawLine(0,62,16,62);
    p.drawLine(7,57,17,61);
    p.drawLine(7,58,17,61);
    p.drawLine(7,59,17,61);
    p.drawLine(7,63,17,61);
    p.drawLine(7,64,17,61);
    p.drawLine(7,65,17,61);

    paintXOR( 18,51, (mTrivium->mB[68] != mTrivium->mB[83]?Qt::green:Qt::red), &p );

    p.setPen(QPen(QBrush(mTrivium->mB[68] != mTrivium->mB[83]?Qt::green:Qt::red),3));
    p.drawLine(28,72,28,123);
    p.drawLine(0,123,28,123);

    p.drawLine(39,61,434,61);

    p.end();
    lBBack->update();

}

void TriviumWidget::paintC(){

    QPainter p(const_cast<QPixmap*>(lCMTop->pixmap()));
    p.setPen(QPen(QBrush(mTrivium->mC[86]?Qt::green:Qt::red),3));
    p.drawLine(1214,40,1214,25);
    p.drawLine(0,25,1214,25);
    p.setPen(QPen(QBrush(mTrivium->mC[65]?Qt::green:Qt::red),3));
    p.drawLine(922,40,922,15);
    p.drawLine(922,15,1555,15);
    p.end();
    lCMTop->update();


    p.begin(const_cast<QPixmap*>(lCFront->pixmap()));
    p.setPen(QPen(QBrush(mTrivium->mC[86]?Qt::green:Qt::red),3));
    p.drawLine(37,25,70,25);
    p.drawLine(37,25,37,47);
    p.setPen(QPen(QBrush(mTrivium->mC[86]?Qt::green:Qt::red),1));
    p.drawLine(34,40,38,50);
    p.drawLine(42,40,38,50);
    p.drawLine(35,40,38,50);
    p.drawLine(41,40,38,50);
    p.drawLine(36,40,38,50);
    p.drawLine(40,40,38,50);

    paintXOR( 28,51, (mTrivium->mB[68] != mTrivium->mB[83] != (mTrivium->mB[81]&&mTrivium->mB[82]) != mTrivium->mC[86]?Qt::green:Qt::red), &p );

    p.setPen(QPen(QBrush(mTrivium->mB[68] != mTrivium->mB[83] != (mTrivium->mB[81]&&mTrivium->mB[82]) != mTrivium->mC[86]?Qt::green:Qt::red),1));
    p.drawLine(49,60,65,60);
    p.drawLine(49,61,67,61);
    p.drawLine(49,62,65,62);
    p.drawLine(57,57,67,61);
    p.drawLine(57,58,67,61);
    p.drawLine(57,59,67,61);
    p.drawLine(57,63,67,61);
    p.drawLine(57,64,67,61);
    p.drawLine(57,65,67,61);

    p.setPen(QPen(QBrush(mTrivium->mB[68] != mTrivium->mB[83] != (mTrivium->mB[81]&&mTrivium->mB[82])?Qt::green:Qt::red),3));
    p.drawLine(10,0,10,60);
    p.setPen(QPen(QBrush(mTrivium->mB[68] != mTrivium->mB[83] != (mTrivium->mB[81]&&mTrivium->mB[82])?Qt::green:Qt::red),1));
    p.drawLine(10,60,27,60);
    p.drawLine(10,61,28,61);
    p.drawLine(10,62,27,62);
    p.drawLine(17,57,27,61);
    p.drawLine(17,58,27,61);
    p.drawLine(17,59,27,61);
    p.drawLine(17,63,27,61);
    p.drawLine(17,64,27,61);
    p.drawLine(17,65,27,61);

    p.setPen(QPen(QBrush(mTrivium->mC[65] != mTrivium->mC[110] != (mTrivium->mC[109]&&mTrivium->mC[108])?Qt::green:Qt::red),3));
    p.drawLine(1,0,1,123);
    p.drawLine(1,123,70,123);

    p.end();
    lCFront->update();


    p.begin(const_cast<QPixmap*>(lCMBottom->pixmap()));
    p.setPen(QPen(QBrush(mTrivium->mC[108]?Qt::green:Qt::red),3));
    p.drawLine(1519,0,1519,5);
    p.setPen(QPen(QBrush(mTrivium->mC[109]?Qt::green:Qt::red),3));
    p.drawLine(1533,0,1533,5);
    paintAND( 1513,6, (mTrivium->mC[108] && mTrivium->mC[109]?Qt::green:Qt::red), &p );
    p.drawLine(1526,24,1526,30);
    paintXOR( 1516,31, (mTrivium->mC[65] != mTrivium->mC[110] != (mTrivium->mC[108] && mTrivium->mC[109])?Qt::green:Qt::red), &p );
    p.setPen(QPen(QBrush(mTrivium->mC[65] != mTrivium->mC[110] != (mTrivium->mC[108] && mTrivium->mC[109])?Qt::green:Qt::red),3));
    p.drawLine(0,41,1516,41);
    p.setPen(QPen(QBrush(mTrivium->mC[65] != mTrivium->mC[110]?Qt::green:Qt::red),1));
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
    p.setPen(QPen(QBrush(mTrivium->mC[65]?Qt::green:Qt::red),3));
    p.drawLine(0,15,28,15);
    p.drawLine(28,15,28,47);
    p.setPen(QPen(QBrush(mTrivium->mC[65]?Qt::green:Qt::red),1));
    p.drawLine(24,40,28,50);
    p.drawLine(32,40,28,50);
    p.drawLine(25,40,28,50);
    p.drawLine(31,40,28,50);
    p.drawLine(26,40,28,50);
    p.drawLine(30,40,28,50);

    p.setPen(QPen(QBrush(mTrivium->mC[110]?Qt::green:Qt::red),1));
    p.drawLine(0,60,16,60);
    p.drawLine(0,61,17,61);
    p.drawLine(0,62,16,62);
    p.drawLine(7,57,17,61);
    p.drawLine(7,58,17,61);
    p.drawLine(7,59,17,61);
    p.drawLine(7,63,17,61);
    p.drawLine(7,64,17,61);
    p.drawLine(7,65,17,61);

    paintXOR( 18,51, (mTrivium->mC[65] != mTrivium->mC[110]?Qt::green:Qt::red), &p );

    p.setPen(QPen(QBrush(mTrivium->mC[65] != mTrivium->mC[110]?Qt::green:Qt::red),3));
    p.drawLine(28,72,28,123);
    p.drawLine(0,123,28,123);

    p.drawLine(39,61,70,61);

    p.end();
    lCBack->update();

}
*/
void TriviumWidget::paintXOR( int aX, int aY, const QColor& aColor, QPainter* aPainter){

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
void TriviumWidget::paintAND( int aX, int aY, const QColor& aColor, QPainter* aPainter){

    aPainter->setPen(QPen(QBrush(aColor),3));
    aPainter->eraseRect( aX,aY,26,18 );
    aPainter->drawRect( aX,aY,26,18 );
    aPainter->drawText( aX,aY,26,18, Qt::AlignHCenter | Qt::AlignVCenter ,QString("&") );

};

void TriviumWidget::paintXorFront( int aX, int aY, const QColor& aColorA, const QColor& aColorB, QPainter* aPainter){

    aPainter->setPen(QPen(QBrush(aColorA),3));
    aPainter->drawLine(27+aX,aY,60+aX,aY);
    aPainter->drawLine(27+aX,aY,27+aX,22+aY);
    aPainter->setPen(QPen(QBrush(aColorA),1));
    aPainter->drawLine(24+aX,15+aY,28+aX,25+aY);
    aPainter->drawLine(32+aX,15+aY,28+aX,25+aY);
    aPainter->drawLine(25+aX,15+aY,28+aX,25+aY);
    aPainter->drawLine(31+aX,15+aY,28+aX,25+aY);
    aPainter->drawLine(26+aX,15+aY,28+aX,25+aY);
    aPainter->drawLine(30+aX,15+aY,28+aX,25+aY);

    paintXOR( 18+aX,26+aY, (aColorA != aColorB?Qt::green:Qt::red), aPainter );

    aPainter->setPen(QPen(QBrush(aColorA != aColorB?Qt::green:Qt::red),1));
    aPainter->drawLine(39+aX,35+aY,55+aX,35+aY);
    aPainter->drawLine(39+aX,36+aY,57+aX,36+aY);
    aPainter->drawLine(39+aX,37+aY,55+aX,37+aY);
    aPainter->drawLine(47+aX,32+aY,57+aX,36+aY);
    aPainter->drawLine(47+aX,33+aY,57+aX,36+aY);
    aPainter->drawLine(47+aX,34+aY,57+aX,36+aY);
    aPainter->drawLine(47+aX,38+aY,57+aX,36+aY);
    aPainter->drawLine(47+aX,39+aY,57+aX,36+aY);
    aPainter->drawLine(47+aX,40+aY,57+aX,36+aY);

    aPainter->setPen(QPen(QBrush(aColorB),1));
    aPainter->drawLine(aX,35+aY,17+aX,35+aY);
    aPainter->drawLine(aX,36+aY,18+aX,36+aY);
    aPainter->drawLine(aX,37+aY,17+aX,37+aY);
    aPainter->drawLine(7+aX,32+aY,17+aX,36+aY);
    aPainter->drawLine(7+aX,33+aY,17+aX,36+aY);
    aPainter->drawLine(7+aX,34+aY,17+aX,36+aY);
    aPainter->drawLine(7+aX,38+aY,17+aX,36+aY);
    aPainter->drawLine(7+aX,39+aY,17+aX,36+aY);
    aPainter->drawLine(7+aX,40+aY,17+aX,36+aY);

};

void TriviumWidget::paintXorBack( int aX, int aY, const QColor& aColorA, const QColor& aColorB, QPainter* aPainter){

    aPainter->setPen(QPen(QBrush(aColorA),3));
    aPainter->drawLine(0+aX,aY,28+aX,aY);
    aPainter->drawLine(28+aX,aY,28+aX,47-15+aY);
    aPainter->setPen(QPen(QBrush(aColorA),1));
    aPainter->drawLine(24+aX,40-15+aY,28+aX,50-15+aY);
    aPainter->drawLine(32+aX,40-15+aY,28+aX,50-15+aY);
    aPainter->drawLine(25+aX,40-15+aY,28+aX,50-15+aY);
    aPainter->drawLine(31+aX,40-15+aY,28+aX,50-15+aY);
    aPainter->drawLine(26+aX,40-15+aY,28+aX,50-15+aY);
    aPainter->drawLine(30+aX,40-15+aY,28+aX,50-15+aY);

    aPainter->setPen(QPen(QBrush(aColorB),1));
    aPainter->drawLine(0+aX,60-15+aY,16+aX,60-15+aY);
    aPainter->drawLine(0+aX,61-15+aY,17+aX,61-15+aY);
    aPainter->drawLine(0+aX,62-15+aY,16+aX,62-15+aY);
    aPainter->drawLine(7+aX,57-15+aY,17+aX,61-15+aY);
    aPainter->drawLine(7+aX,58-15+aY,17+aX,61-15+aY);
    aPainter->drawLine(7+aX,59-15+aY,17+aX,61-15+aY);
    aPainter->drawLine(7+aX,63-15+aY,17+aX,61-15+aY);
    aPainter->drawLine(7+aX,64-15+aY,17+aX,61-15+aY);
    aPainter->drawLine(7+aX,65-15+aY,17+aX,61-15+aY);

    paintXOR( 18+aX,36+aY, (aColorA != aColorB?Qt::green:Qt::red), aPainter );

    aPainter->setPen(QPen(QBrush(aColorA != aColorB?Qt::green:Qt::red),3));
    aPainter->drawLine(28+aX,72-15+aY,28+aX,123-15+aY);

    aPainter->drawLine(39+aX,61-15+aY,70+aX,61-15+aY);

    aPainter->setPen(QPen(QBrush(aColorA != aColorB?Qt::green:Qt::red),1));
    aPainter->drawLine(28+aX,123-15+aY,-16+aX,123-15+aY);
    aPainter->drawLine(28+aX,124-15+aY,-17+aX,124-15+aY);
    aPainter->drawLine(28+aX,125-15+aY,-16+aX,125-15+aY);
    aPainter->drawLine(-6+aX,120-15+aY,-17+aX,124-15+aY);
    aPainter->drawLine(-6+aX,121-15+aY,-17+aX,124-15+aY);
    aPainter->drawLine(-6+aX,122-15+aY,-17+aX,124-15+aY);
    aPainter->drawLine(-6+aX,126-15+aY,-17+aX,124-15+aY);
    aPainter->drawLine(-6+aX,127-15+aY,-17+aX,124-15+aY);
    aPainter->drawLine(-6+aX,128-15+aY,-17+aX,124-15+aY);

};

void TriviumWidget::paintAndXor( int aX, int aY, const QColor& aColorA, const QColor& aColorB, const QColor& aColorC, QPainter* aPainter){

    aPainter->setPen(QPen(QBrush(aColorA),3));
    aPainter->drawLine(1281-1281+aX,0+aY,1281-1281+aX,5+aY);
    aPainter->setPen(QPen(QBrush(aColorB),3));
    aPainter->drawLine(1295-1281+aX,0+aY,1295-1281+aX,5+aY);
    paintAND( 1275-1281+aX,6+aY, (aColorA == aColorB && aColorA != Qt::red?Qt::green:Qt::red), aPainter );
    aPainter->drawLine(1288-1281+aX,24+aY,1288-1281+aX,30+aY);
    paintXOR( 1278-1281+aX,31+aY, aColorC, aPainter );
    aPainter->setPen(QPen(QBrush(aColorC),3));
    aPainter->drawLine(1281-1281+aX,41+aY,1278-1281+aX,41+aY);

};

void TriviumWidget::updateRegister(){

    for( int vI = 0; vI < mTrivium->mA.size(); ++vI ){
        mA[vI]->setBit(mTrivium->mA[vI]);

        if( vI == 65 || vI == 68 || vI == 90 || vI == 91 || vI == 92 ){
            if(mTrivium->mA[vI]){
                mA[vI]->setStyleSheet("QWidget#lbBit { border-style: solid; border-width: 2; border-color: rgb(0, 255, 0); }");
            } else {
                mA[vI]->setStyleSheet("QWidget#lbBit { border-style: solid; border-width: 2; border-color: rgb(255, 0, 0); }");
            }
        }
    }
    for( int vI = 0; vI < mTrivium->mB.size(); ++vI ){
        mB[vI]->setBit(mTrivium->mB[vI]);

        if( vI == 68 || vI == 77 || vI == 81 || vI == 82 || vI == 83 ){
            if(mTrivium->mB[vI]){
                mB[vI]->setStyleSheet("QWidget#lbBit { border-style: solid; border-width: 2; border-color: rgb(0, 255, 0); }");
            } else {
                mB[vI]->setStyleSheet("QWidget#lbBit { border-style: solid; border-width: 2; border-color: rgb(255, 0, 0); }");
            }
        }
    }
    for( int vI = 0; vI < mTrivium->mC.size(); ++vI ){
        mC[vI]->setBit(mTrivium->mC[vI]);

        if( vI == 65 || vI == 86 || vI == 108 || vI == 109 || vI == 110 ){
            if(mTrivium->mC[vI]){
                mC[vI]->setStyleSheet("QWidget#lbBit { border-style: solid; border-width: 2; border-color: rgb(0, 255, 0); }");
            } else {
                mC[vI]->setStyleSheet("QWidget#lbBit { border-style: solid; border-width: 2; border-color: rgb(255, 0, 0); }");
            }
        }
    }

    update();
};

}
