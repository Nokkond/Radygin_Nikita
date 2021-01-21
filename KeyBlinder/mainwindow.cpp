#include "infow.h"
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
#include <QRandomGenerator>




using namespace std;







int rnd(int x){

    int h = QRandomGenerator::global()->bounded(x);
    return h;
}



QString stroka(int level, QString startstring, QList<QStringList> levellang ){

    if (level==1){
        for(int i = 0; i<11; i++ ){

            startstring+=levellang[0][rnd(levellang[0].size())]+' ';
        }
    }
    else if(level==2){
        for(int i = 0; i<10; i++ ){

            startstring+=levellang[1][rnd(levellang[1].size())]+' ';
        }
    }
    else if(level==3){
        for(int i = 0; i<10; i++ ){

            startstring+=levellang[2][rnd(levellang[2].size())]+' ';
        }
    }
    else if(level==4){
        for(int i = 0; i<9; i++ ){

            startstring+=levellang[3][rnd(levellang[3].size())]+' ';
        }
    }
    else if(level==5){
        for(int i = 0; i<8; i++ ){

            startstring+=levellang[4][rnd(levellang[4].size())]+' ';
        }
    }
    return startstring;
}






long double tme(){
    long double x = 1.0 * clock() / CLOCKS_PER_SEC;
    return x;
}




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{




    ui->setupUi(this);
    ttt.start();
    this->setFixedSize(730,470);






    language = "eng";
    engkeys = { "a", "b", "c","d","e","f","g","h","i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z","%","%","%","%","%","%"};
    ruskeys = { "ф", "и", "с","в","у","а","п","р","ш", "о", "л", "д", "ь", "т", "щ", "з", "й", "к", "ы", "е", "г", "м", "ц", "ч", "н","я", "x","ъ","ж","э","б","ю"};
    langkeys=engkeys;
    level = 1;
    leveleng={{ "burg", "bur", "bunny","burn","fug","bug","grunt","gun","gym", "hum", "jugum", "hurt", "mummy", "mugg", "thug"},
              { "begem", "bein", "big","big","chicken","chief","deer","big","energy", "hurt", "hurt", "hurt", "big", "given", "given"},
             { "wols", "woker", "google","golo","xotur","fox","grunt","sold","sell", "eu", "www", "suter", "set", "hoff", "gun"},
             { "walter", "wing", "devolvation","very","quest","zone","midle","power","left", "right", "again", "nice", "face", "quant", "place"},
             { "expansion", "verification", "adaptation","innaguration","semestr","situation","stagnation","passion","reflection", "bagration", "stadium", "bariumity", "warzone", "worldwide", "pharmacy"}};
    levelrus={{ "ром", "рим", "мир","норка","река","кира","пин","ним","мен", "гон", "нога", "кино", "енот", "нить", "рак"},
             { "упор", "правда", "сова","вонь","вино","вила","ноль","шов","ваш", "век", "бивень", "бад", "боль", "небо", "бан"},
             { "набок", "бедро", "цирк","церковь","цент","тонна","тень","час","счет", "тальк", "темп", "предмет", "метр", "вектор", "век"},
             { "рост", "река", "фольклор","хор","жизнь","жилка","жандарм","жена","я", "апатия", "ад", "овация", "вакцина", "эму", "йорк"},
             { "россия", "любовь", "водка","вода","пиво","яблоко","ягода","як","ява", "алмаз", "вирус", "ватрушка", "весна", "школа", "забота"}};


    levellang = leveleng;






        for(int i = 0; i<12; i++ ){

            startstring+=levellang[0][rnd(levellang[0].size())]+' ';
        }






    count = -1;
    count1 = 0;



    style1 = "color: rgb(235, 240, 240); font: 19px San Francisco; background-color: rgba(120, 123, 123, 150); text-align: center; border-radius: 6px; border-width:thick";
    style2 = "color: rgb(235, 240, 240); font: 19px San Francisco; background-color: rgba(134, 190, 255, 200); text-align: center; border-radius: 6px; border-width:thick";
    style3 = "color: rgb(235, 240, 240); font: 19px San Francisco; background-color: rgba(252, 85, 68,180); text-align: center; border-radius: 6px; border-width:thick";
    style4 = "color: rgb(235, 240, 240); font: 19px San Francisco; background-color: rgba(146, 148, 148, 200);; text-align: center; border-radius: 6px; border-width:thick";


    mistakes=0;
    accuracy=100;

    ui->label_34->setText(startstring);
    ui->label_39->setText("0");

    ui->label_41->setText("0");

    count=0;
}

MainWindow::~MainWindow()
{
    delete ui;
}














void MainWindow::keyPressEvent(QKeyEvent *event){
    centralWidget()->setFocus();

    ui->label_39->setText(QString::number(x1));





    if (event->key() == Qt::Key_Space){
        k = " ";
    }
    if (event->key() == Qt::Key_A){
        k = langkeys[0];

    }
    if (event->key() == Qt::Key_B){
        k = langkeys[1];


    }
    if (event->key() == Qt::Key_C){
        k = langkeys[2];


    }
    if (event->key() == Qt::Key_D){
        k = langkeys[3];


    }
    if (event->key() == Qt::Key_E){
        k =langkeys[4];


    }
    if (event->key() == Qt::Key_F){
        k = langkeys[5];


    }
    if (event->key() == Qt::Key_G){
        k = langkeys[6];


    }
    if (event->key() == Qt::Key_H){
        k = langkeys[7];


    }
    if (event->key() == Qt::Key_I){
        k = langkeys[8];


    }
    if (event->key() == Qt::Key_J){
        k = langkeys[9];


    }
    if (event->key() == Qt::Key_K){
        k = langkeys[10];
    }
    if (event->key() == Qt::Key_L){
        k = langkeys[11];


    }
    if (event->key() == Qt::Key_M){
        k =langkeys[12];


    }
    if (event->key() == Qt::Key_N){
        k =langkeys[13];


    }
    if (event->key() == Qt::Key_O){
        k = langkeys[14];


    }
    if (event->key() == Qt::Key_P){
        k = langkeys[15];


    }
    if (event->key() == Qt::Key_Q){
        k =langkeys[16];


    }
    if (event->key() == Qt::Key_R){
        k = langkeys[17];


    }
    if (event->key() == Qt::Key_S){
        k =langkeys[18];


    }
    if (event->key() == Qt::Key_T){
        k = langkeys[19];


    }
    if (event->key() == Qt::Key_U){
        k = langkeys[20];


    }
    if (event->key() == Qt::Key_V){
        k = langkeys[21];


    }
    if (event->key() == Qt::Key_W){
        k = langkeys[22];


    }
    if (event->key() == Qt::Key_X){
        k = langkeys[23];


    }
    if (event->key() == Qt::Key_Y){
        k = langkeys[24];


    }
    if (event->key() == Qt::Key_Z){

        k = langkeys[25];
    }
    if (event->key() == Qt::Key_BracketLeft){

        k = langkeys[26];
    }
    if (event->key() == Qt::Key_BracketRight){

        k = langkeys[27];
    }
    if (event->key() == Qt::Key_Semicolon){

        k = langkeys[28];
    }
    if (event->key() == Qt::Key_Apostrophe){

        k = langkeys[29];
    }
    if (event->key() == Qt::Key_Comma){

        k = langkeys[30];
    }
    if (event->key() == Qt::Key_Period){

        k = langkeys[31];
    }



    ui->enter->setStyleSheet(style1);
    ui->q->setStyleSheet(style4);
     ui->w->setStyleSheet(style1);
      ui->e->setStyleSheet(style4);
       ui->r->setStyleSheet(style1);
       ui->t->setStyleSheet(style1);
       ui->y->setStyleSheet(style4);
       ui->u->setStyleSheet(style4);
       ui->i->setStyleSheet(style1);
       ui->o->setStyleSheet(style4);
       ui->p->setStyleSheet(style1);
       ui->a->setStyleSheet(style4);
       ui->s->setStyleSheet(style1);
       ui->d->setStyleSheet(style4);
       ui->f->setStyleSheet(style1);
       ui->g->setStyleSheet(style1);
       ui->h->setStyleSheet(style4);
       ui->j->setStyleSheet(style4);
       ui->k->setStyleSheet(style1);
       ui->l->setStyleSheet(style4);
       ui->z->setStyleSheet(style4);
       ui->x->setStyleSheet(style1);
       ui->c->setStyleSheet(style4);
       ui->v->setStyleSheet(style1);
       ui->b->setStyleSheet(style1);
       ui->n->setStyleSheet(style4);
       ui->m->setStyleSheet(style4);
       ui->space->setStyleSheet(style1);

       ui->ha->setStyleSheet(style1);
       ui->tvznak->setStyleSheet(style1);
       ui->je->setStyleSheet(style1);
       ui->aa->setStyleSheet(style1);
       ui->ba->setStyleSheet(style1);
       ui->uu->setStyleSheet(style4);



    cutter = startstring.mid(count+1,1);
    cutter2 = startstring.mid(count,1);



    if (startstring.length()==(count+1)){
        ui->enter->setStyleSheet(style2);
    }
    else
    {
        ui->enter->setStyleSheet(style1);
    }

    if (cutter==" "){
        ui->space->setStyleSheet(style2);
    }
    else if ( k==" " && cutter2!=" ")
     {
         ui->space->setStyleSheet(style3);

     }
    if (cutter==langkeys[0]){
        ui->a->setStyleSheet(style2);
    }
    else if ( k==langkeys[0] && cutter2!=langkeys[0])
     {
         ui->a->setStyleSheet(style3);

     }
    if (cutter==langkeys[1]){
        ui->b->setStyleSheet(style2);
    }
    else if ( k==langkeys[1] && cutter2!=langkeys[1])
     {
         ui->b->setStyleSheet(style3);

     }
    if (cutter==langkeys[2]){
        ui->c->setStyleSheet(style2);
    }
    else if ( k==langkeys[2] && cutter2!=langkeys[2])
     {
         ui->c->setStyleSheet(style3);

     }
    if (cutter==langkeys[3]){
        ui->d->setStyleSheet(style2);
    }
    else if ( k==langkeys[3] && cutter2!=langkeys[3])
     {
         ui->d->setStyleSheet(style3);

     }
    if (cutter==langkeys[4]){
        ui->e->setStyleSheet(style2);
    }
    else if ( k==langkeys[4] && cutter2!=langkeys[4])
     {
         ui->e->setStyleSheet(style3);

     }

    if (cutter==langkeys[5]){
        ui->f->setStyleSheet(style2);
    }
    else if ( k==langkeys[5] && cutter2!=langkeys[5])
     {
         ui->f->setStyleSheet(style3);

     }
    if (cutter==langkeys[6]){
        ui->g->setStyleSheet(style2);
    }
    else if ( k==langkeys[6] && cutter2!=langkeys[6])
     {
         ui->g->setStyleSheet(style3);

     }

    if (cutter==langkeys[7]){
        ui->h->setStyleSheet(style2);
    }
    else if ( k==langkeys[7] && cutter2!=langkeys[7])
     {
         ui->h->setStyleSheet(style3);

     }
    if (cutter==langkeys[8]){
        ui->i->setStyleSheet(style2);
    }
    else if ( k==langkeys[8] && cutter2!=langkeys[8])
     {
         ui->i->setStyleSheet(style3);

     }
    if (cutter==langkeys[9]){
        ui->j->setStyleSheet(style2);
    }
    else if ( k==langkeys[9] && cutter2!=langkeys[9])
     {
         ui->j->setStyleSheet(style3);

     }
    if (cutter==langkeys[10]){
        ui->k->setStyleSheet(style2);
    }
    else if ( k==langkeys[10] && cutter2!=langkeys[10])
     {
         ui->k->setStyleSheet(style3);

     }
    if (cutter==langkeys[11]){
        ui->l->setStyleSheet(style2);
    }
    else if ( k==langkeys[11] && cutter2!=langkeys[11])
     {
         ui->l->setStyleSheet(style3);

     }
    if (cutter==langkeys[12]){
        ui->m->setStyleSheet(style2);
    }
    else if ( k==langkeys[12] && cutter2!=langkeys[12])
     {
         ui->m->setStyleSheet(style3);

     }




    if (cutter==langkeys[13]){
        ui->n->setStyleSheet(style2);
    }
    else if ( k==langkeys[13] && cutter2!=langkeys[13])
     {
         ui->n->setStyleSheet(style3);

     }


    if (cutter==langkeys[14]){
        ui->o->setStyleSheet(style2);
    }
    else if ( k==langkeys[14] && cutter2!=langkeys[14])
     {
         ui->o->setStyleSheet(style3);

     }
    if (cutter==langkeys[15]){
        ui->p->setStyleSheet(style2);
    }
    else if ( k==langkeys[15] && cutter2!=langkeys[15])
     {
         ui->p->setStyleSheet(style3);

     }


    if (cutter==langkeys[16]){
        ui->q->setStyleSheet(style2);
    }
    else if ( k==langkeys[16] && cutter2!=langkeys[16])
     {
         ui->q->setStyleSheet(style3);

     }
    if (cutter==langkeys[17]){
        ui->r->setStyleSheet(style2);
    }
    else if ( k==langkeys[17] && cutter2!=langkeys[17])
     {
         ui->r->setStyleSheet(style3);

     }
    if (cutter==langkeys[18]){
        ui->s->setStyleSheet(style2);
    }
    else if ( k==langkeys[18] && cutter2!=langkeys[18])
     {
         ui->s->setStyleSheet(style3);

     }
    if (cutter==langkeys[19]){
        ui->t->setStyleSheet(style2);
    }
    else if ( k==langkeys[19] && cutter2!=langkeys[19])
     {
         ui->t->setStyleSheet(style3);

     }
    if (cutter==langkeys[20]){
        ui->u->setStyleSheet(style2);
    }
    else if ( k==langkeys[20] && cutter2!=langkeys[20])
     {
         ui->u->setStyleSheet(style3);

     }
    if (cutter==langkeys[21]){
        ui->v->setStyleSheet(style2);
    }
    else if ( k==langkeys[21] && cutter2!=langkeys[21])
     {
         ui->v->setStyleSheet(style3);

     }
    if (cutter==langkeys[22]){
        ui->w->setStyleSheet(style2);

    }
    else if ( k==langkeys[22] && cutter2!=langkeys[22])
     {
         ui->w->setStyleSheet(style3);

     }


    if (cutter==langkeys[23]){
        ui->x->setStyleSheet(style2);
    }
    else if ( k==langkeys[23] && cutter2!=langkeys[23])
     {
         ui->x->setStyleSheet(style3);

     }
    if (cutter==langkeys[24]){
        ui->y->setStyleSheet(style2);
    }
    else if ( k==langkeys[24] && cutter2!=langkeys[24])
     {
         ui->y->setStyleSheet(style3);

     }

    if (cutter==langkeys[25]){
        ui->z->setStyleSheet(style2);
    }
    else if ( k==langkeys[25] && cutter2!=langkeys[25])
     {
         ui->z->setStyleSheet(style3);

     }
    if (cutter==langkeys[26]){
        ui->ha->setStyleSheet(style2);
    }

    else if ( k==langkeys[26] && cutter2!=langkeys[26])
     {
         ui->ha->setStyleSheet(style3);

     }
    if (cutter==langkeys[27]){
        ui->tvznak->setStyleSheet(style2);
    }

    else if ( k==langkeys[27] && cutter2!=langkeys[27])
     {
         ui->tvznak->setStyleSheet(style3);

     }
    if (cutter==langkeys[28]){
        ui->je->setStyleSheet(style2);
    }

    else if ( k==langkeys[28] && cutter2!=langkeys[28])
     {
         ui->je->setStyleSheet(style3);

     }
    if (cutter==langkeys[29]){
        ui->aa->setStyleSheet(style2);
    }

    else if ( k==langkeys[29] && cutter2!=langkeys[29])
     {
         ui->aa->setStyleSheet(style3);

     }
    if (cutter==langkeys[30]){
        ui->ba->setStyleSheet(style2);
    }

    else if ( k==langkeys[30] && cutter2!=langkeys[30])
     {
         ui->ba->setStyleSheet(style3);
     }
    if (cutter==langkeys[31]){
        ui->uu->setStyleSheet(style2);
    }

    else if ( k==langkeys[31] && cutter2!=langkeys[31])
     {
         ui->uu->setStyleSheet(style3);
     }










    keyv1=keyv;
    keyv += startstring[count];
    keyv2 += k;
    cutter3 = keyv2.mid(count,1);
    if ( cutter2!=cutter3)
    {
    mistakes+=1;
    }
    ui->label_42->setText(keyv);
    count+=1;
    count1+=1;

    if(count1>0){accuracy = 100*(count1-mistakes)/(count1);};
    ui->label_41->setText( QString::number(mistakes));
    ui->label_40->setText( QString::number(accuracy)+'%');

    x2=static_cast<int>(tme()*1000);
    x1=ttt.elapsed();
    int hh = round(x1 / 1000);

    ui->label_39->setText(QString::number((count+1)*60/(hh+1)));
    if ((event->key() == Qt::Key_Return) || (event->key() == Qt::Key_Enter)|| startstring.length()==(count-1)){
    keyv = "";


    ui->label_42->setText(keyv);
    mistakes = 0;
    count = 0;
    count1 = 0;
    startstring = "";
    startstring = stroka(level, startstring, levellang);

    ui->enter->setStyleSheet(style1);
    ui->q->setStyleSheet(style4);
     ui->w->setStyleSheet(style1);
      ui->e->setStyleSheet(style4);
       ui->r->setStyleSheet(style1);
       ui->t->setStyleSheet(style1);
       ui->y->setStyleSheet(style4);
       ui->u->setStyleSheet(style4);
       ui->i->setStyleSheet(style1);
       ui->o->setStyleSheet(style4);
       ui->p->setStyleSheet(style1);
       ui->a->setStyleSheet(style4);
       ui->s->setStyleSheet(style1);
       ui->d->setStyleSheet(style4);
       ui->f->setStyleSheet(style1);
       ui->g->setStyleSheet(style1);
       ui->h->setStyleSheet(style4);
       ui->j->setStyleSheet(style4);
       ui->k->setStyleSheet(style1);
       ui->l->setStyleSheet(style4);
       ui->z->setStyleSheet(style4);
       ui->x->setStyleSheet(style1);
       ui->c->setStyleSheet(style4);
       ui->v->setStyleSheet(style1);
       ui->b->setStyleSheet(style1);
       ui->n->setStyleSheet(style4);
       ui->m->setStyleSheet(style4);
       ui->space->setStyleSheet(style1);

       ui->ha->setStyleSheet(style1);
       ui->tvznak->setStyleSheet(style1);
       ui->je->setStyleSheet(style1);
       ui->aa->setStyleSheet(style1);
       ui->ba->setStyleSheet(style1);
       ui->uu->setStyleSheet(style4);

    ui->space->setStyleSheet(style1);
    ui->label_34->setText(startstring);
    accuracy=100;
    mistakes=0;
    keyv2 = "";
    ui->label_41->setText( QString::number(mistakes));
    ui->label_40->setText( QString::number(accuracy)+'%');

    ui->label_39->setText(QString::number(0));
    ttt.start();

    }


}





















void MainWindow::on_l1_clicked()
{
    level=1;


}

void MainWindow::on_l2_clicked()
{
    level=2;
}

void MainWindow::on_l3_clicked()
{
    level=3;
}

void MainWindow::on_l4_clicked()
{
    level=4;
}



void MainWindow::on_l5_clicked()
{

    file_name = QFileDialog::getOpenFileName(this,"Open a file","");
    QFile file(file_name);

    if (!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"","Файл не существует или не был выбран");
    }
    else
    {
        QTextStream in(&file);
        QString text = in.readAll();
        QStringList query = text.split(" ");

            level=5;

        levellang[4] = query;
    }




}



void MainWindow::on_eng_clicked()
{
    language = "eng";
    langkeys = engkeys;
    levellang=leveleng;
    ui->a->setText(langkeys[0]);
     ui->b->setText(langkeys[1]);
      ui->c->setText(langkeys[2]);
       ui->d->setText(langkeys[3]);
       ui->e->setText(langkeys[4]);
       ui->f->setText(langkeys[5]);
       ui->g->setText(langkeys[6]);
       ui->h->setText(langkeys[7]);
       ui->i->setText(langkeys[8]);
       ui->j->setText(langkeys[9]);
       ui->k->setText(langkeys[10]);
       ui->l->setText(langkeys[11]);
       ui->m->setText(langkeys[12]);
       ui->n->setText(langkeys[13]);
       ui->o->setText(langkeys[14]);
       ui->p->setText(langkeys[15]);
       ui->q->setText(langkeys[16]);
       ui->r->setText(langkeys[17]);
       ui->s->setText(langkeys[18]);
       ui->t->setText(langkeys[19]);
       ui->u->setText(langkeys[20]);
       ui->v->setText(langkeys[21]);
       ui->w->setText(langkeys[22]);
       ui->x->setText(langkeys[23]);
       ui->y->setText(langkeys[24]);
       ui->z->setText(langkeys[25]);

       ui->ha->setText(" ");
       ui->tvznak->setText(" ");
       ui->je->setText(" ");
       ui->aa->setText(" ");
       ui->ba->setText(" ");
       ui->uu->setText(" ");

       keyv = "";
       ui->label_42->setText(keyv);
       mistakes = 0;
       count = 0;
       count1 = 0;
       startstring = "";
       startstring = stroka(level, startstring, levellang);
       ui->space->setStyleSheet(style1);
       ui->label_34->setText(startstring);
       accuracy=100;
       mistakes=0;
       keyv2 = "";
       ui->label_41->setText( QString::number(mistakes));
       ui->label_40->setText( QString::number(accuracy)+'%');

       ui->label_39->setText(QString::number(0));
       ttt.start();
}

void MainWindow::on_rus_clicked()
{
    language = "rus";
    langkeys = ruskeys;
    levellang=levelrus;
    ui->a->setText(langkeys[0]);
     ui->b->setText(langkeys[1]);
      ui->c->setText(langkeys[2]);
       ui->d->setText(langkeys[3]);
       ui->e->setText(langkeys[4]);
       ui->f->setText(langkeys[5]);
       ui->g->setText(langkeys[6]);
       ui->h->setText(langkeys[7]);
       ui->i->setText(langkeys[8]);
       ui->j->setText(langkeys[9]);
       ui->k->setText(langkeys[10]);
       ui->l->setText(langkeys[11]);
       ui->m->setText(langkeys[12]);
       ui->n->setText(langkeys[13]);
       ui->o->setText(langkeys[14]);
       ui->p->setText(langkeys[15]);
       ui->q->setText(langkeys[16]);
       ui->r->setText(langkeys[17]);
       ui->s->setText(langkeys[18]);
       ui->t->setText(langkeys[19]);
       ui->u->setText(langkeys[20]);
       ui->v->setText(langkeys[21]);
       ui->w->setText(langkeys[22]);
       ui->x->setText(langkeys[23]);
       ui->y->setText(langkeys[24]);
       ui->z->setText(langkeys[25]);

       ui->ha->setText(langkeys[26]);
       ui->tvznak->setText(langkeys[27]);
       ui->je->setText(langkeys[28]);
       ui->aa->setText(langkeys[29]);
       ui->ba->setText(langkeys[30]);
       ui->uu->setText(langkeys[31]);

       keyv = "";
       ui->label_42->setText(keyv);
       mistakes = 0;
       count = 0;
       count1 = 0;
       startstring = "";
       startstring = stroka(level, startstring, levellang);
       ui->space->setStyleSheet(style1);
       ui->label_34->setText(startstring);
       accuracy=100;
       mistakes=0;
       keyv2 = "";
       ui->label_41->setText( QString::number(mistakes));
       ui->label_40->setText( QString::number(accuracy)+'%');

       ui->label_39->setText(QString::number(0));
       ttt.start();
}



void MainWindow::on_editor_clicked()
{
    SecondWindow window;
    window.setWindowTitle("Редактор словарей");
    window.setModal(true);
    window.exec();
}

void MainWindow::on_info_clicked()
{
    infow window;
    window.setWindowTitle("Информация");
    window.setModal(true);
    window.exec();
}
