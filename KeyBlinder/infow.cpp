#include "infow.h"
#include "ui_infow.h"
#include <QPixmap>

infow::infow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::infow)
{
    ui->setupUi(this);
    this->setFixedSize(697,542);

}

infow::~infow()
{

    delete ui;
}
