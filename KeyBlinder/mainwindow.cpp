#include "mainwindow.h"
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
#include <QString>
#include <QTimer>
#include <QList>
#include <cstdlib>
#include <stdlib.h>
#include <QLabel>

using namespace std;

int rnd(int x){
    mt19937 get(chrono::high_resolution_clock::now().time_since_epoch().count());
    return get() % x;
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
    this->setFixedSize(740,470);
    level = 1;
    level1 = { "burg", "bur", "bunny","burn","fug","grub","grunt","gun","gym", "hum", "jugum", "hurt", "mummy", "mugg", "thug"};
    level2 = { "begem", "bein", "big","cetrimide","chicken","chief","deer","deemed","energy", "ferberite", "frightening", "hurt", "ginger", "given", "hedenbergite"};
    level3 = { "wols", "woker", "google","golo","xotur","fox","grunt","sold","sell", "eu", "www", "suter", "set", "hoff", "gun"};
    level4 = { "walter", "wing", "devolvation","very","quest","zone","midle","power","left", "right", "again", "nice", "face", "quant", "place"};
    level5 = { "expansion", "verification", "adaptation","innaguration","semestr","situation","stagnation","passion","reflection", "bagration", "stadium", "bariumity", "warzone", "worldwide", "pharmacy"};

    if (level==1){
        for(int i = 0; i<12; i++ ){

            startstring+=level1[rnd(15)]+' ';
        }
    }
    else if(level==2){
        for(int i = 0; i<8; i++ ){

            startstring+=level2[rnd(15)]+' ';
        }
    }
    else if(level==3){
        for(int i = 0; i<13; i++ ){

            startstring+=level3[rnd(15)]+' ';
        }
    }
    else if(level==4){
        for(int i = 0; i<11; i++ ){

            startstring+=level4[rnd(15)]+' ';
        }
    }
    else if(level==5){
        for(int i = 0; i<7; i++ ){

            startstring+=level5[rnd(15)]+' ';
        }
    }




    count = -1;
    count1 = 0;


    style1 = "color: rgb(235, 240, 240); background-color: rgba(120, 123, 123, 150); text-align: center; border-radius: 6px; border-width:thick";
    style2 = "color: rgb(235, 240, 240); background-color: rgba(134, 190, 255, 200); text-align: center; border-radius: 6px; border-width:thick";
    style3 = "color: rgb(235, 240, 240); background-color: rgba(252, 85, 68,180); text-align: center; border-radius: 6px; border-width:thick";

    mistakes=0;
    accuracy=100;

    ui->label_34->setText(startstring);
    ui->label_39->setText(QString::number(x1));
    ui->label_41->setText("0");
    //connect(ui->label_42,SIGNAL(clicked()),this,SLOT(testovoy()));
    count=0;
}

MainWindow::~MainWindow()
{
    delete ui;
}















void MainWindow::keyPressEvent(QKeyEvent *event){





    if (event->key() == Qt::Key_Space){
        k = ' ';
    }
    if (event->key() == Qt::Key_Q){
        k = 'q';

    }
    if (event->key() == Qt::Key_W){
        k = 'w';


    }
    if (event->key() == Qt::Key_E){
        k = 'e';


    }
    if (event->key() == Qt::Key_R){
        k = 'r';


    }
    if (event->key() == Qt::Key_T){
        k ='t';


    }
    if (event->key() == Qt::Key_Y){
        k = 'y';


    }
    if (event->key() == Qt::Key_U){
        k = 'u';


    }
    if (event->key() == Qt::Key_I){
        k = 'i';


    }
    if (event->key() == Qt::Key_O){
        k = 'o';


    }
    if (event->key() == Qt::Key_P){
        k = 'p';


    }
    if (event->key() == Qt::Key_A){   
        k = 'a';
    }
    if (event->key() == Qt::Key_S){
        k = 's';


    }
    if (event->key() == Qt::Key_D){
        k ='d';


    }
    if (event->key() == Qt::Key_F){
        k ='f';


    }
    if (event->key() == Qt::Key_G){
        k = 'g';


    }
    if (event->key() == Qt::Key_H){
        k = 'h';


    }
    if (event->key() == Qt::Key_J){
        k ='j';


    }
    if (event->key() == Qt::Key_K){
        k = 'k';


    }
    if (event->key() == Qt::Key_L){
        k ='l';


    }
    if (event->key() == Qt::Key_Z){
        k = 'z';


    }
    if (event->key() == Qt::Key_X){
        k = 'x';


    }
    if (event->key() == Qt::Key_C){
        k = 'c';


    }
    if (event->key() == Qt::Key_V){
        k = 'v';


    }
    if (event->key() == Qt::Key_B){
        k = 'b';


    }
    if (event->key() == Qt::Key_N){
        k = 'n';


    }
    if (event->key() == Qt::Key_M){

        k = 'm';
    }

    //if (mark == 1){
    //    k=k1;
    //    mark=0;
    //}
    ui->enter->setStyleSheet(style1);
    ui->q->setStyleSheet(style1);
     ui->w->setStyleSheet(style1);
      ui->e->setStyleSheet(style1);
       ui->r->setStyleSheet(style1);
       ui->t->setStyleSheet(style1);
       ui->y->setStyleSheet(style1);
       ui->u->setStyleSheet(style1);
       ui->i->setStyleSheet(style1);
       ui->o->setStyleSheet(style1);
       ui->p->setStyleSheet(style1);
       ui->a->setStyleSheet(style1);
       ui->s->setStyleSheet(style1);
       ui->d->setStyleSheet(style1);
       ui->f->setStyleSheet(style1);
       ui->g->setStyleSheet(style1);
       ui->h->setStyleSheet(style1);
       ui->j->setStyleSheet(style1);
       ui->k->setStyleSheet(style1);
       ui->l->setStyleSheet(style1);
       ui->z->setStyleSheet(style1);
       ui->x->setStyleSheet(style1);
       ui->c->setStyleSheet(style1);
       ui->v->setStyleSheet(style1);
       ui->b->setStyleSheet(style1);
       ui->n->setStyleSheet(style1);
       ui->m->setStyleSheet(style1);
       ui->space->setStyleSheet(style1);







    if (startstring.length()==(count+1)){
        ui->enter->setStyleSheet(style2);
    }
    else
    {
        ui->enter->setStyleSheet(style1);
    }

    if (startstring[count+1]==' '){
        ui->space->setStyleSheet(style2);
    }
    else if ( k==' ' && startstring[count]!=' ')
     {
         ui->space->setStyleSheet(style3);

     }
    if (startstring[count+1]=='q'){
        ui->q->setStyleSheet(style2);
    }
    else if ( k=='q' && startstring[count]!='q')
     {
         ui->j->setStyleSheet(style3);

     }
    if (startstring[count+1]=='w'){
        ui->w->setStyleSheet(style2);
    }
    else if ( k=='w' && startstring[count]!='w')
     {
         ui->j->setStyleSheet(style3);

     }
    if (startstring[count+1]=='e'){
        ui->e->setStyleSheet(style2);
    }
    else if ( k=='e' && startstring[count]!='e')
     {
         ui->j->setStyleSheet(style3);

     }
    if (startstring[count+1]=='a'){
        ui->a->setStyleSheet(style2);
    }
    else if ( k=='a' && startstring[count]!='a')
     {
         ui->a->setStyleSheet(style3);

     }
    if (startstring[count+1]=='z'){
        ui->z->setStyleSheet(style2);
    }
    else if ( k=='z' && startstring[count]!='z')
     {
         ui->z->setStyleSheet(style3);

     }

    if (startstring[count+1]=='s'){
        ui->s->setStyleSheet(style2);
    }
    else if ( k=='s' && startstring[count]!='s')
     {
         ui->s->setStyleSheet(style3);

     }
    if (startstring[count+1]=='x'){
        ui->x->setStyleSheet(style2);
    }
    else if ( k=='x' && startstring[count]!='x')
     {
         ui->x->setStyleSheet(style3);

     }

    if (startstring[count+1]=='d'){
        ui->d->setStyleSheet(style2);
    }
    else if ( k=='d' && startstring[count]!='d')
     {
         ui->d->setStyleSheet(style3);

     }
    if (startstring[count+1]=='c'){
        ui->c->setStyleSheet(style2);
    }
    else if ( k=='c' && startstring[count]!='c')
     {
         ui->c->setStyleSheet(style3);

     }
    if (startstring[count+1]=='v'){
        ui->v->setStyleSheet(style2);
    }
    else if ( k=='v' && startstring[count]!='v')
     {
         ui->v->setStyleSheet(style3);

     }
    if (startstring[count+1]=='t'){
        ui->t->setStyleSheet(style2);
    }
    else if ( k=='t' && startstring[count]!='t')
     {
         ui->t->setStyleSheet(style3);

     }
    if (startstring[count+1]=='i'){
        ui->i->setStyleSheet(style2);
    }
    else if ( k=='i' && startstring[count]!='i')
     {
         ui->i->setStyleSheet(style3);

     }
    if (startstring[count+1]=='j'){
        ui->j->setStyleSheet(style2);
    }
    else if ( k=='j' && startstring[count]!='j')
     {
         ui->j->setStyleSheet(style3);

     }




    if (startstring[count+1]=='k'){
        ui->k->setStyleSheet(style2);
    }
    else if ( k=='k' && startstring[count]!='k')
     {
         ui->k->setStyleSheet(style3);

     }


    if (startstring[count+1]=='o'){
        ui->o->setStyleSheet(style2);
    }
    else if ( k=='o' && startstring[count]!='o')
     {
         ui->o->setStyleSheet(style3);

     }
    if (startstring[count+1]=='p'){
        ui->p->setStyleSheet(style2);
    }
    else if ( k=='p' && startstring[count]!='p')
     {
         ui->p->setStyleSheet(style3);

     }


    if (startstring[count+1]=='g'){
        ui->g->setStyleSheet(style2);
    }
    else if ( k=='g' && startstring[count]!='g')
     {
         ui->g->setStyleSheet(style3);

     }
    if (startstring[count+1]=='h'){
        ui->h->setStyleSheet(style2);
    }
    else if ( k=='h' && startstring[count]!='h')
     {
         ui->h->setStyleSheet(style3);

     }
    if (startstring[count+1]=='t'){
        ui->t->setStyleSheet(style2);
    }
    else if ( k=='t' && startstring[count]!='t')
     {
         ui->t->setStyleSheet(style3);

     }
    if (startstring[count+1]=='y'){
        ui->y->setStyleSheet(style2);
    }
    else if ( k=='y' && startstring[count]!='y')
     {
         ui->y->setStyleSheet(style3);

     }
    if (startstring[count+1]=='r'){
        ui->r->setStyleSheet(style2);
    }
    else if ( k=='r' && startstring[count]!='r')
     {
         ui->r->setStyleSheet(style3);

     }
    if (startstring[count+1]=='u'){
        ui->u->setStyleSheet(style2);
    }
    else if ( k=='u' && startstring[count]!='u')
     {
         ui->u->setStyleSheet(style3);

     }
    if (startstring[count+1]=='b'){
        ui->b->setStyleSheet(style2);

    }
    else if ( k=='b' && startstring[count]!='b')
     {
         ui->b->setStyleSheet(style3);

     }


    if (startstring[count+1]=='n'){
        ui->n->setStyleSheet(style2);
    }
    else if ( k=='n' && startstring[count]!='n')
     {
         ui->n->setStyleSheet(style3);

     }
    if (startstring[count+1]=='m'){
        ui->m->setStyleSheet(style2);
    }
    else if ( k=='m' && startstring[count]!='m')
     {
         ui->m->setStyleSheet(style3);

     }
    if (startstring[count+1]==' '){
        ui->space->setStyleSheet(style2);
    }
    else if ( k==' ' && startstring[count]!=' ')
     {
         ui->space->setStyleSheet(style3);

     }
    if (startstring[count+1]=='f'){
        ui->f->setStyleSheet(style2);
    }
    else if ( k=='f' && startstring[count]!='f')
     {
         ui->f->setStyleSheet(style3);

     }
    if (startstring[count+1]=='l'){
        ui->l->setStyleSheet(style2);
    }
    else if ( k=='l' && startstring[count]!='l')
     {
         ui->l->setStyleSheet(style3);

     }




    keyv1=keyv;
    keyv += startstring[count];
    keyv2 += k;
    if ( startstring[count]!=keyv2[count])
    {
    mistakes+=1;
    }
    ui->label_42->setText(keyv);
    count+=1;
    count1+=1;

    if(count1>0){accuracy = 100*(count1-mistakes+1)/(count1);};
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
    if (level==1){
        for(int i = 0; i<12; i++ ){

            startstring+=level1[rnd(15)]+' ';
        }
    }
    else if(level==2){
        for(int i = 0; i<8; i++ ){

            startstring+=level2[rnd(15)]+' ';
        }
    }
    else if(level==3){
        for(int i = 0; i<13; i++ ){

            startstring+=level3[rnd(15)]+' ';
        }
    }
    else if(level==4){
        for(int i = 0; i<11; i++ ){

            startstring+=level4[rnd(15)]+' ';
        }
    }
    else if(level==5){
        for(int i = 0; i<7; i++ ){

            startstring+=level5[rnd(15)]+' ';
        }
    }
    ui->enter->setStyleSheet(style1);
    ui->q->setStyleSheet(style1);
     ui->w->setStyleSheet(style1);
      ui->e->setStyleSheet(style1);
       ui->r->setStyleSheet(style1);
       ui->t->setStyleSheet(style1);
       ui->y->setStyleSheet(style1);
       ui->u->setStyleSheet(style1);
       ui->i->setStyleSheet(style1);
       ui->o->setStyleSheet(style1);
       ui->p->setStyleSheet(style1);
       ui->a->setStyleSheet(style1);
       ui->s->setStyleSheet(style1);
       ui->d->setStyleSheet(style1);
       ui->f->setStyleSheet(style1);
       ui->g->setStyleSheet(style1);
       ui->h->setStyleSheet(style1);
       ui->j->setStyleSheet(style1);
       ui->k->setStyleSheet(style1);
       ui->l->setStyleSheet(style1);
       ui->z->setStyleSheet(style1);
       ui->x->setStyleSheet(style1);
       ui->c->setStyleSheet(style1);
       ui->v->setStyleSheet(style1);
       ui->b->setStyleSheet(style1);
       ui->n->setStyleSheet(style1);
       ui->m->setStyleSheet(style1);
    ui->space->setStyleSheet(style1);
    ui->label_34->setText(startstring);
    accuracy=100;
    mistakes=0;
    ui->label_41->setText( QString::number(mistakes));
    ui->label_40->setText( QString::number(accuracy)+'%');

    ui->label_39->setText(QString::number(0));
    ttt.start();

    }


}











void MainWindow::on_label_42_linkActivated(const QString &link)
{


}

void MainWindow::on_label_42_linkHovered(const QString &link)
{


}

void MainWindow::testovoy(){


}

void MainWindow::on_label_42_windowIconTextChanged(const QString &iconText)
{

}

void MainWindow::on_label_42_objectNameChanged(const QString &objectName)
{

}

void MainWindow::on_pushButton_clicked()
{
    level=1;

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

void MainWindow::on_l1_5_clicked()
{
    level=5;
}
