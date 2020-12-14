#include "janelanew.h"
#include "ui_janelanew.h"

JanelaNew::JanelaNew(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JanelaNew)
{
    ui->setupUi(this);
}

JanelaNew::~JanelaNew()
{
    delete ui;
}

int JanelaNew::getDimX(){
return ui->inputEixoX->text().toInt();
}
int JanelaNew::getDimY(){
    return  ui->inputEixoY->text().toInt();
}
int JanelaNew::getDimZ(){
    return  ui->inputEixoZ->text().toInt();
}
