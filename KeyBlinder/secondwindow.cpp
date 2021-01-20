#include "secondwindow.h"
#include "ui_secondwindow.h"
#include "secondwindow.h"
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
#include <QTimer>
#include <QList>
#include <cstdlib>
#include <stdlib.h>
#include <QLabel>
#include <QFile>
#include <QByteArray>
#include <QTextStream>
#include <QFile>
#include <QString>
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>

SecondWindow::SecondWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
}

SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::

on_pushButton_clicked()
{
    QFile file(file_name);

    if (!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"","Файл не существует или не был выбран");
    }
    QTextStream out(&file);
    QString text = ui->txed->toPlainText();
    out << text;
    file.flush();
    file.close();
}

void SecondWindow::on_pushButton_2_clicked()
{

    QFile file(file_name);

    if (!file.open(QFile::ReadOnly | QFile::Text)){
         QMessageBox::warning(this,"","Файл не существует или не был выбран");
    }

    QTextStream in(&file);
    QString text = in.readAll();
    ui->txed->setPlainText(text);
    file.close();
}

void SecondWindow::on_pushButton_3_clicked()
{
    file_name = QFileDialog::getOpenFileName(this,"Open a file","");


}
