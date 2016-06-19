#ifndef _triviumwidget_
#define _triviumwidget_

#include "ui_trivium.h"

#include <QWidget>
#include <QString>
#include <QColor>

#include <bitset>
#include <vector>

#include "core/trivium.h"
#include "gui/bit.h"

class QPainter;

namespace trivium{

class TriviumWidget : public QWidget, private Ui::TriviumWidget
{
    Q_OBJECT

    trivium::Trivium* mTrivium;

    std::vector<trivium::Bit*> mA, mB, mC;

public:
    TriviumWidget( trivium::Trivium* aTrivium, QWidget *parent = 0);

    void paintEvent(QPaintEvent *mEvent);

    void updateRegister();

private:
    void paintXOR( int aX, int aY, const QColor& aColor, QPainter* aPainter);
    void paintAND( int aX, int aY, const QColor& aColor, QPainter* aPainter);
    void paintXorFront( int aX, int aY, const QColor& aColorA, const QColor& aColorB, QPainter* aPainter);
    void paintXorBack( int aX, int aY, const QColor& aColorA, const QColor& aColorB, QPainter* aPainter);
    void paintAndXor( int aX, int aY, const QColor& aColorA, const QColor& aColorB, const QColor& aColorD, QPainter* aPainter);

};

}

#endif
