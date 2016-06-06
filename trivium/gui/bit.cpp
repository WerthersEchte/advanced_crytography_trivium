#include "bit.h"

namespace trivium{


Bit::Bit( bool aBit, int aNumber, QWidget *parent )
    : QWidget(parent){
    setupUi(this);

    setBit( aBit );
    setNumberOfBit( aNumber );
};

void Bit::setBit( bool aBit ){
    lbBit->setText(QString::number(aBit?1:0));
};
void Bit::setNumberOfBit( int aNumber ){
    lbNumber->setText(QString::number(aNumber));
};

}
