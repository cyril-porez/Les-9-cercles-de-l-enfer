#include "../headers/mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Les 9 cercles");
    w.show();
    return a.exec();
}
