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
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("KeyBlinder");

    //w.setIcon(QIcon("icon.png"));
    w.show();




    return a.exec();






}


