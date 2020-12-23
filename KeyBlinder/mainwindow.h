#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
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
#include <QTime>
#include <QTimer>
#include <QList>
#include <cstdlib>
#include <stdlib.h>
#include <QLabel>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
     ~MainWindow();

    void init();
    void go();
    void update_ceils();
    void make();
    void gen();
    void ChangeScore(int x);
    const char* get(int x);
    bool f;
    void change(int x);
    void keyPressEvent(QKeyEvent *event);
    QString keyv;
    QChar k;
    QChar k1;
    QString keyv1;
    QString keyv2;
    QString startstring;
    QString startstring1;
    QString style1;
    QString style2;
    QString style3;
    void testovoy();
    QList<QString> level1;
    QList<QString> level2;
    QList<QString> level3;
    QList<QString> level4;
    QList<QString> level5;

    int level;
    int rn;
    int count;
    int count1;
    int mistakes;
    int tru;
    float accuracy;
    QLabel  name;
    int mistake;
    int mark;
    int x1;
    int x2;
    QTime ttt = QTime::currentTime();

private slots:
    void on_label_42_linkActivated(const QString &link);

    void on_label_42_linkHovered(const QString &link);

    void on_label_42_windowIconTextChanged(const QString &iconText);

    void on_label_42_objectNameChanged(const QString &objectName);

    void on_pushButton_clicked();

    void on_l1_clicked();

    void on_l2_clicked();

    void on_l3_clicked();

    void on_l4_clicked();

    void on_l1_5_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
