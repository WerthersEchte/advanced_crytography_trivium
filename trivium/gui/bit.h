#ifndef _Bit_
#define _Bit_

#include "ui_bit.h"

#include <QWidget>

namespace trivium{

class Bit : public QWidget, private Ui::Bit
{
    Q_OBJECT

public:
    Bit(bool aBit, int aNumber, QWidget *parent = 0);

public slots:
    void setBit( bool aBit );
    void setNumberOfBit( int aNumber );

};

}

#endif
