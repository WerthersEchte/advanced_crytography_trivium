#ifndef _mainwindow_
#define _mainwindow_

#include "ui_mainwindow.h"

#include <QWidget>
#include <QMainWindow>
#include <QString>

#include <bitset>

namespace trivium{

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT

    std::bitset<80> mKey;
    std::bitset<80> mIV;

public:
    MainWindow(QWidget *parent = 0);

public slots:
    void updateHexText(const QString& aText);
    void updateBinText(const QString& aText);

};

}

#endif
