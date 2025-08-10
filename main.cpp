#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QApplication::setApplicationName("TeleTools");
    QApplication::setOrganizationName("Zivix");

    MainWindow w;
    w.resize(980, 680);
    w.show();
    return app.exec();
}
