#include "mainwindow.h"

#include <sstream>

namespace trivium{

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi(this);

    std::stringstream vStream;
    vStream << mKey;

    lEKeyBin->setText(QString::fromStdString(vStream.str()));
};

}
