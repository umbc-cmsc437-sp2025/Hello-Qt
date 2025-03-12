#include "dialog2.h"
#include "ui_dialog2.h"

Dialog2::Dialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);
}

Dialog2::~Dialog2()
{
    delete ui;
}

void Dialog2::on_dial_valueChanged(int value)
{
    char str[255];
    printf("Hello %d\n", value);
    fflush(stdout);
    sprintf(str, "QLabel{background-color: #%02xffff;};", value);
    ui->label->setStyleSheet(QString(str));
}

