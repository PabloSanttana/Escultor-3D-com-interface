#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "janelanew.h"
#include "plotter.h"
#include <QPixmap>
#include <QMessageBox>

#include <QDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionNovo,SIGNAL(triggered(bool)),
            this,SLOT(openJanelaNew()));

    connect(ui->actionQuit,SIGNAL(triggered(bool)),
            this,SLOT(closed()));

   ui->containerMatriz->setDimXYZ(10,10,10);
   ui->horizontalSliderProfundidade->setMaximum(9);
   ui->horizontalSliderDXCubo->setMaximum(9);
   ui->horizontalSliderDYCubo->setMaximum(9);
   ui->horizontalSliderDZCubo->setMaximum(9);
   ui->horizontalSliderRXElipse->setMaximum(9);
   ui->horizontalSliderRYElipse->setMaximum(9);
   ui->horizontalSliderRZElipse->setMaximum(9);
   ui->horizontalSliderRaioEsfera->setMaximum(9);

   QPixmap initputVoxel(":/icons/incos/putvoxel.jpg");

   ui->labelIncos->setPixmap(initputVoxel.scaled(390,150,Qt::KeepAspectRatio));
   ui->labelTextIcon->setText("Criar um voxel");




   QPixmap layout(":/icons/incos/layout.png");

   ui->labelLayoutIcon->setPixmap(layout.scaled(390,150,Qt::KeepAspectRatio));


}

MainWindow::~MainWindow()
{
    delete ui;
    ui->containerMatriz->deleteMatrix();

}

void MainWindow::openJanelaNew(){

    JanelaNew novo;

    if(novo.exec() == QDialog::Accepted){

        if(novo.getDimX()>0 && novo.getDimY() >0 && novo.getDimZ()>0){

               ui->containerMatriz->setDimXYZ(novo.getDimX(),novo.getDimY(), novo.getDimZ());
               ui->lcdNumberX->display(novo.getDimX());
               ui->lcdNumberY->display(novo.getDimY());
               ui->lcdNumberZ->display(novo.getDimZ());
               ui->horizontalSliderProfundidade->setMaximum(novo.getDimZ()-1);
               ui->horizontalSliderDXCubo->setMaximum(novo.getDimX());
               ui->horizontalSliderDYCubo->setMaximum(novo.getDimY());
               ui->horizontalSliderDZCubo->setMaximum(novo.getDimZ());
               ui->horizontalSliderRXElipse->setMaximum(novo.getDimX());
               ui->horizontalSliderRYElipse->setMaximum(novo.getDimY());
               ui->horizontalSliderRZElipse->setMaximum(novo.getDimZ());

               if(novo.getDimX() > novo.getDimY() && novo.getDimX() > novo.getDimZ()){
                    ui->horizontalSliderRaioEsfera->setMaximum(novo.getDimX()-1);
               }else if (novo.getDimY() > novo.getDimX() && novo.getDimY() > novo.getDimZ()) {
                    ui->horizontalSliderRaioEsfera->setMaximum(novo.getDimY()-1);
               }else if (novo.getDimZ() > novo.getDimX() && novo.getDimZ() > novo.getDimY()) {
                    ui->horizontalSliderRaioEsfera->setMaximum(novo.getDimZ()-1);
               }else {
                     ui->horizontalSliderRaioEsfera->setMaximum(novo.getDimX()-1);
                }
          }else {

            QMessageBox::warning(this,"Erro","Algumas Dimensões não estam corretas, por favor tente novamente use apenas números");

           }


     }

}

void MainWindow::on_pushButtonPutVoxel_clicked()
{
    QPixmap putVoxel(":/icons/incos/putvoxel.jpg");

    ui->labelIncos->setPixmap(putVoxel.scaled(390,150,Qt::KeepAspectRatio));
    ui->labelTextIcon->setText("Criar um voxel");
}

void MainWindow::on_pushButtonCutVoxel_clicked()
{
    QPixmap cutVoxel(":/icons/incos/CutVoxel.png");

    ui->labelIncos->setPixmap(cutVoxel.scaled(390,150,Qt::KeepAspectRatio));
    ui->labelTextIcon->setText("Remover um voxel");
}



void MainWindow::on_pushButtonPutBox_clicked()
{
    QPixmap putBox(":/icons/incos/putBoXX.png");

    ui->labelIncos->setPixmap(putBox.scaled(390,150,Qt::KeepAspectRatio));
    ui->labelTextIcon->setText("Criar uma caixa");
}

void MainWindow::on_pushButtonCutBox_clicked()
{
    QPixmap cutBox(":/icons/incos/cutBox.jpg");

    ui->labelIncos->setPixmap(cutBox.scaled(390,150,Qt::KeepAspectRatio));
    ui->labelTextIcon->setText("Remover uma caixa");
}

void MainWindow::on_pushButtonPutSphere_clicked()
{
    QPixmap PutSphere(":/icons/incos/PutEsfera.png");

    ui->labelIncos->setPixmap(PutSphere.scaled(390,150,Qt::KeepAspectRatio));
    ui->labelTextIcon->setText("Criar uma esfera");
}

void MainWindow::on_pushButtonCutSphere_clicked()
{
    QPixmap cutSphere(":/icons/incos/CutEsfera.png");

    ui->labelIncos->setPixmap(cutSphere.scaled(390,150,Qt::KeepAspectRatio));
    ui->labelTextIcon->setText("Remover uma esfera");
}

void MainWindow::on_pushButtonPutEllipsoid_clicked()
{
    QPixmap PutEllipsoid(":/icons/incos/PutElipse.png");

    ui->labelIncos->setPixmap(PutEllipsoid.scaled(390,150,Qt::KeepAspectRatio));
    ui->labelTextIcon->setText("Criar um elipsoide");
}

void MainWindow::on_pushButtonCutEllipsoid_clicked()
{
    QPixmap cutEllipsoid(":/icons/incos/CutElipse.png");

    ui->labelIncos->setPixmap(cutEllipsoid.scaled(390,150,Qt::KeepAspectRatio));
    ui->labelTextIcon->setText("Remover um elipsoide");
}

void MainWindow::closed(){

   if(QMessageBox::question(this,"Quit","Você deseja sair?") == QMessageBox::Yes){
         close();
   }


}
