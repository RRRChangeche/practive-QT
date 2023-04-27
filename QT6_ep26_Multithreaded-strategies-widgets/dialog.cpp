
#include "dialog.h"
#include "./ui_dialog.h"


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}



void Dialog::on_pushButton_clicked()
{
    // Work Intensive!!!
    // The applicatio will hang up!
    qInfo() << QThread::currentThread();
    QThread::currentThread()->msleep(60000);
}

