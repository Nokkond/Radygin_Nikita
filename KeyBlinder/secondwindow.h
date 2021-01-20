#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>


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
#include <QTime>
#include <QTimer>
#include <QList>
#include <cstdlib>
#include <stdlib.h>
#include <QLabel>
#include <QFile>
#include <QByteArray>
#include <QTextStream>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();
    QString file_name;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();


private:
    Ui::SecondWindow *ui;
};

#endif // SECONDWINDOW_H
