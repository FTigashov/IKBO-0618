#include "mainwindow.h"
#include <QApplication>
#include"input.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Input w;
    w.show();

    return a.exec();
}


