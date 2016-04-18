#include "core/trivium.h"
#include "gui/mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    trivium::MainWindow vMainWindow;
    vMainWindow.show();
    return app.exec();
}
