#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QTextEdit>
#include <time.h>
#include <random>
#include <QDebug>
#include <QThread>
#include <QTimer>
#include <QWidget>
#include <QKeyEvent>
#include <Qstring>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();






}


