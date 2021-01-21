#ifndef INFOW_H
#define INFOW_H

#include <QDialog>

namespace Ui {
class infow;
}

class infow : public QDialog
{
    Q_OBJECT

public:
    explicit infow(QWidget *parent = nullptr);
    ~infow();

private:
    Ui::infow *ui;
};

#endif // INFOW_H
