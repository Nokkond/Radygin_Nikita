#ifndef MAINWINDOW_H
#define MAINWINDOW_H



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
#include <QLocale>
#include <QPushButton>
#include <QIcon>
#include <QFileDialog>
#include <QStringList>


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

    ///
    /// \brief process_line
    /// \param line
    ///



    void change(int x);
    ///
    /// \brief keyPressEvent функция определения события нажатия клавиши клавиатуры
    /// \param event нажатая клавиша
    ///
    void keyPressEvent(QKeyEvent *event);
    ///
    /// \brief keyv переменная для работы со строкой
    ///
    QString keyv;
    ///
    /// \brief k переменная для работы со строкой
    ///
    QString k;
    ///
    /// \brief k1 переменная для работы со строкой
    ///
    QString k1;
    ///
    /// \brief keyv1 переменная для работы со строкой
    ///
    QString keyv1;
    ///
    /// \brief keyv2 переменная для работы со строкой
    ///
    QString keyv2;
    ///
    /// \brief startstring
    /// Переменная строки
    ///
    QString startstring;
    ///
    /// \brief startstring1 функция полной строки
    ///
    QString startstring1;
    ///
    /// \brief style1 переменная базового стиля клавиш
    ///
    QString style1;
    ///
    /// \brief style2 стиль подстветки неправильных клавиш
    ///
    QString style2;
    ///
    /// \brief style3 стиль подсветки правильных клавиш
    ///
    QString style3;
    ///
    /// \brief style4 переменная базового стиля более темных клавиш
    ///
    QString style4;
    ///
    /// \brief cutter переменная, помогающая сравнивать символы
    ///
    QString cutter;
    ///
    /// \brief cutter2 переменная, помогающая сравнивать символы
    ///
    QString cutter2;
    ///
    /// \brief cutter3 переменная, помогающая сравнивать символы
    ///
    QString cutter3;


    ///
    /// \brief levelrus словарь для русского режима
    ///
    QList<QStringList>levelrus;
    ///
    /// \brief leveleng словарь для английского режима
    ///
    QList<QStringList>leveleng;
    ///
    /// \brief levellang переменная языкового режима
    ///
    QList<QStringList>levellang;
    ///
    /// \brief langkeys словарь выбранного языка клавиш
    ///
    QList<QString> langkeys;
    ///
    /// \brief engkeys словарь английских клавиш
    ///
    QList<QString> engkeys;
    ///
    /// \brief ruskeys словарь русских клавиш
    ///
    QList<QString> ruskeys;


    ///
    /// \brief level переменная уровня
    ///
    int level;
    ///
    /// \brief count счетчик
    ///
    int count;
    ///
    /// \brief count1 счетчик
    ///
    int count1;
    ///
    /// \brief mistakes переменная количества ошибок
    ///
    int mistakes;
    ///
    /// \brief accuracy переменная точности правописания
    ///
    float accuracy;


    ///
    /// \brief mistake дополнительный счетчик для ошибкок
    ///
    int mistake;
    ///
    /// \brief x1  переменная для хранения времени
    ///
    int x1;
    ///
    /// \brief x2 переменная для обработки актуального времени
    ///
    int x2;
    ///
    /// \brief language переменная выбранного языка
    ///
    QString language;
    ///
    /// \brief ttt переменная времени
    ///
    QTime ttt = QTime::currentTime();
    ///
    /// \brief file_name имя используемого файло
    ///
    QString file_name;


private slots:



    ///
    /// \brief on_l1_clicked функия проверки нажатия кнопки первого уровня сложности
    ///
    void on_l1_clicked();
    ///
    /// \brief on_l2_clicked функия проверки нажатия кнопки вторго уровня сложности
    ///
    void on_l2_clicked();
    ///
    /// \brief on_l3_clicked функия проверки нажатия кнопки третьего уровня сложности
    ///
    void on_l3_clicked();
    ///
    /// \brief on_l4_clicked функия проверки нажатия кнопки четвертого уровня сложности
    ///
    void on_l4_clicked();


    ///
    /// \brief on_l5_clicked функция выбора файла словаря для пятого уровня сложности
    ///
    void on_l5_clicked();




    ///
    /// \brief on_eng_clicked функция выбора английского языка
    ///
    void on_eng_clicked();

    ///
    /// \brief on_rus_clicked функция выбора русского языка
    ///
    void on_rus_clicked();
    ///
    /// \brief on_editor_clicked функция открытия редактора
    ///
    void on_editor_clicked();
    ///
    /// \brief on_info_clicked функция открытия окна информации
    ///
    void on_info_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
