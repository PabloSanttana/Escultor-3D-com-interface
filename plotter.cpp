#include "plotter.h"
#include "sculptor.h"
#include "Voxel.h"
#include <QPainter>
#include <QDebug>
#include <QBrush>
#include <QPen>
#include <cmath>
#include <QMouseEvent>
#include <Qt>
#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>

Sculptor *v;
bool acitve = false;

Plotter::Plotter(QWidget *parent) : QWidget(parent){
    setMouseTracking(true);
    nx=10;
    ny=10;
    nz=10;
    coodX = -1;
    coodY = -1;
    coodZ =0;
    raioEsfera=1;
    rxElipse=1;
    ryElipse=1;
    rzElipse=1;
    dxCubo=1;
    dyCubo=1;
    dzCubo=1;
    selectedMetodo=0;
}

Plotter::Plotter()
{
    nx=10;
    nz=10;
    ny=10;
    v = new Sculptor(nx,ny,nz);
}

Plotter::~Plotter()
{

}

Plotter::Plotter(int _nx, int _ny, int _nz){
    nx=_nx;
    nz=_nz;
    ny=_ny;

    if(acitve){
        v->~Sculptor();
    }

    v = new Sculptor(nx,ny,nz);
    acitve = true;
    //qDebug() << "x ->" << nx;
   // qDebug() << "z ->" << nz;
   // qDebug() << "y ->" << ny;
    repaint();
}

void Plotter::paintEvent(QPaintEvent *event){

   Voxel voxel;

   QPainter painter(this);
   QBrush brush;
   QPen pen;
    float x1,x2,y1,y2,z,constX, constY;

   brush.setColor(QColor(255,0,255,0)); // cor de fundo
   brush.setStyle(Qt::SolidPattern);

   // caneta da caneta
   pen.setColor(QColor(255,255,0,0));
   pen.setWidth(2);
   // informa ao pintor qual brush atual
   painter.setBrush(brush);
   // informa ao pintor qual a canate atual
   painter.setPen(pen);
   // desenha um retangulo pegando toda a tela
   painter.drawRect(0,0,width(),height()); // container


   // fazendo a matriz
   brush.setColor(QColor(255,255,255)); // cor de fundo

   pen.setColor(QColor(150,150,150));
   pen.setWidth(1);

   painter.setBrush(brush);
   painter.setPen(pen);

   constX = width()/nx;
   constY = height()/ny;

   x1 =1;
   x2 = constX;

   for (int j=0; j < nx ;j++ ) {

       y1 =1;
       for (int i=0;i < ny ;i++ ) {

           voxel = v->matrizShow(j,i,coodZ);

           if(voxel.isOn){

               brush.setColor(QColor(voxel.r*255,voxel.g*255,voxel.b*255));
               painter.setBrush(brush);

           }else {

               brush.setColor(QColor(255,255,255));
                painter.setBrush(brush);
           }


           painter.drawRect(x1,y1,constX,constY);
           y1= y1 +constY;

       }

     x1 = x1+constX;
   }

}
void Plotter::mousePressEvent(QMouseEvent *event){
    // logica para pegar as posiçoes da mastriz
    float constX = width()/nx; // lagura
    float constY = height()/ny; // altura
    int axX,axY;

    axX =  (int) (event->x()/ constX);
    axY =  (int) (event->y()/ constY);

    if(axX>=0 && axX<nx && axY>=0 && axY<ny){

        emit emitCursorX(axX);
        emit emitCursorY(axY);
        emit emitCursorZ(coodZ);
    }

    if(event->buttons() == Qt::LeftButton && axX>=0 && axX<nx && axY>=0 && axY<ny){


        coodX =  axX; // evente localização do mouse dividido pela largura vai me da a posição
        coodY =  axY;
        //qDebug() << "posição em x , y, z ->" << (int) (event->x()/ constX) <<", "<<  (int) (event->y()/ constY) << "," <<coodZ;
        qDebug() << "posição em X , Y, Z ->" << coodX <<", "<<  coodY << "," << coodZ;


         setMetodos();

        repaint();
    }
}
void Plotter::mouseMoveEvent(QMouseEvent *event){
    // logica para pegar as posiçoes da mastriz
    float constX = width()/nx; // lagura
    float constY = height()/ny; // altura
    int axX,axY;

    axX =  (int) (event->x()/ constX);
    axY =  (int) (event->y()/ constY);

    if(axX>=0 && axX<nx && axY>=0 && axY<ny){

        emit emitCursorX(axX);
        emit emitCursorY(axY);
        emit emitCursorZ(coodZ);
    }

    if(event->buttons() == Qt::LeftButton && axX>=0 && axX<nx && axY>=0 && axY<ny ){
        coodX = axX; // evente localização do mouse dividido pela largura vai me da a posição
        coodY =  axY;
        qDebug() << "posição em X , Y, Z ->" << coodX <<", "<<  coodY << "," << coodZ;

        setMetodos();

        repaint();
    }
}
void Plotter::setDimXYZ(int _nx,int _ny,int _nz){

    nx=_nx;nz=_nz;ny=_ny;

    Plotter(_nx,_ny,_nz);

    emit emitResetBlue(0);
    emit emitResetRed(0);
    emit emitResetGreen(255);
    emit emitResetProfundidade(0);
}

void Plotter::deleteMatrix()
{
    v->~Sculptor();
}

void Plotter::setColors(int r, int g, int b){

     v->setColor(r/255.0,g/255.0,b/255.0,1);
     repaint();
}

void Plotter::setCoodenadaZ(int _z){
    coodZ = _z;
    repaint();
}

void Plotter::saveFigure(){


    if(QMessageBox::question(this,"Salvar","Você deseja salvar essa escultura?") == QMessageBox::Yes){

        v->writeOFF((char*)"figuraSave.off");
         QMessageBox::information(this,"Salvar","Salvo com sucesso");

         if(QMessageBox::question(this,"Escultura salva","Você deseja abrir a escultura?") == QMessageBox::Yes){

             QString path = "file:///E:/PA/build-ProjetoFinal-Desktop_Qt_5_14_2_MinGW_64_bit-Debug/figuraSave.off";
             QDesktopServices::openUrl(QUrl(path));
         }


    }

}

void Plotter::setPutVoxel()
{
    selectedMetodo=0;
   // qDebug() << "setPutVoxel";
}

void Plotter::setCutVoxel()
{
    selectedMetodo=1;
   // qDebug() << "setCutVoxel";
}

void Plotter::setPutBox()
{
    selectedMetodo=2;
  //  qDebug() << "setPutBox";
}

void Plotter::setCutBox()
{
    selectedMetodo=3;
   // qDebug() << "setCutBox";
}

void Plotter::setPutSphere()
{
    selectedMetodo=4;
    // qDebug() << "setPutSphere";
}

void Plotter::setCutSphere()
{
    selectedMetodo=5;
    // qDebug() << "setCutSphere";
}

void Plotter::setPutEllipsoid()
{
    selectedMetodo=6;
    /// qDebug() << "setPutEllipsoid";
}

void Plotter::setCutEllipsoid()
{
    selectedMetodo=7;
   // qDebug() << "setCutEllipsoid";
}

void Plotter::setRaioEsfera(int _r)
{
    raioEsfera=_r;
}

void Plotter::setRaioXElipse(int _x)
{
    rxElipse=_x;

}

void Plotter::setRaioYElipse(int _y)
{
    ryElipse=_y;

}

void Plotter::setRaioZElipse(int _z)
{
    rzElipse=_z;

}

void Plotter::setDimXCubo(int _x)
{
    dxCubo=_x;

}

void Plotter::setDimYCubo(int _y)
{
    dyCubo=_y;

}
void Plotter::setDimZCubo(int _z)
{
    dzCubo=_z;
}

void Plotter::setMetodos()
{

    if(selectedMetodo ==0){
        v->putVoxel(coodX,coodY,coodZ);
    }else if (selectedMetodo==1) {
        v->cutVoxel(coodX,coodY,coodZ);
    }else if (selectedMetodo==2) {

        int x1,y1,z1;

           x1 = coodX+dxCubo ;
           y1 = coodY+dyCubo ;
           z1 = coodZ+dzCubo;

           if(x1>=nx){
               x1 = nx;
           }
           if(y1>=ny){
               y1 = ny ;
           }
           if(z1>=nz){
               z1 = nz;
           }

        v->putBox(coodX,x1-1,coodY,y1-1,coodZ,z1-1);

    }else if(selectedMetodo==3){
        int x1,y1,z1;

           x1 = coodX+dxCubo ;
           y1 = coodY+dyCubo ;
           z1 = coodZ+dzCubo;

           if(x1>=nx){
               x1 = nx;
           }
           if(y1>=ny){
               y1 = ny ;
           }
           if(z1>=nz){
               z1 = nz ;
           }

           v->cutBox(coodX,x1-1,coodY,y1-1,coodZ,z1-1);
    }else if(selectedMetodo==4){
        v->putSphere(coodX,coodY,coodZ,raioEsfera);
    }else if (selectedMetodo==5) {
         v->cutSphere(coodX,coodY,coodZ,raioEsfera);
    }else if (selectedMetodo==6) {
        v->putEllipsoid(coodX,coodY,coodZ,rxElipse,ryElipse,rzElipse);
    }else if (selectedMetodo==7) {
        v->cutEllipsoid(coodX,coodY,coodZ,rxElipse,ryElipse,rzElipse);
    }

}

















