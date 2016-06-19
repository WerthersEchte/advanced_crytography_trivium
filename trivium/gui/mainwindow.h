#ifndef _mainwindow_
#define _mainwindow_

#include "ui_mainwindow.h"

#include <QWidget>
#include <QString>
#include <QColor>

#include <bitset>
#include <vector>

#include "core/trivium.h"
#include "gui/bit.h"
#include "gui/triviumwidget.h"

class QPainter;

namespace trivium{

class MainWindow : public QWidget, private Ui::MainWindow
{
    Q_OBJECT

    std::bitset<80> mKey;
    std::bitset<80> mIV;

    trivium::Trivium mTrivium;
    trivium::TriviumWidget* mTriviumWidget;

public:
    MainWindow(QWidget *parent = 0);

public slots:
    void updateHexText(const QString& aText);
    void updateBinText(const QString& aText);

    void initalizeTrivium(bool=false);
    void warmupTrivium(bool=false);
    void stepTrivium(bool=false);
    void multistepTrivium(bool=false);

};

}

#endif
