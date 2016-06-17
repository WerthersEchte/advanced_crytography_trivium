#ifndef _mainwindow_
#define _mainwindow_

#include "ui_mainwindow.h"

#include <QWidget>
#include <QMainWindow>
#include <QString>
#include <QColor>

#include <bitset>
#include <vector>

#include "core/trivium.h"
#include "gui/bit.h"

class QPainter;

namespace trivium{

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT

    std::bitset<80> mKey;
    std::bitset<80> mIV;

    trivium::Trivium mTrivium;

    std::vector<trivium::Bit*> mA, mB, mC;

public:
    MainWindow(QWidget *parent = 0);

public slots:
    void updateHexText(const QString& aText);
    void updateBinText(const QString& aText);

    void initalizeTrivium(bool=false);
    void warmupTrivium(bool=false);
    void stepTrivium(bool=false);
    void multistepTrivium(bool=false);

private:
    void updateRegister();

    void paintXOR( int aX, int aY, const QColor& aColor, QPainter* aPainter);
    void paintAND( int aX, int aY, const QColor& aColor, QPainter* aPainter);

    void paintA();
    void paintB();
    void paintC();
    void paintEnd();

};

}

#endif
