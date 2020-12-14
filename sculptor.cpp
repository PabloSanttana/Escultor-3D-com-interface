#include "sculptor.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <QDebug>
using namespace std;


Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
    nx = _nx; ny = _ny; nz = _nz;
    r=0.00; g=1.00; b=0.00; a=1.00;

    qDebug()<<"nx "<<nx;
    qDebug()<<"ny "<<ny;
    qDebug()<<"nz "<<nz;


    v = new Voxel**[nx];
    for(int i=0; i<nx;i++){
        v[i] = new Voxel*[ny];
        for(int j=0;j<ny;j++){
            v[i][j] = new Voxel[nz];
            for(int k =0; k<nz;k++){
                v[i][j][k].isOn = false;
            }
        }
    }

}

Sculptor::~Sculptor()
{

    for(int i=0; i<nx;i++){
        for(int j=0;j<ny;j++){
           delete[] v[i][j];
        }
        delete[] v[i];
    }

    delete[] v;
    qDebug()<<"Delete"<<nx;

}

void Sculptor::setColor(float red, float green, float blue, float alpha)
{
    r = red;
    g = green;
    b = blue;
    a = alpha;
     qDebug() << "Scultor Cor : r , g, b ->"<<  r <<","<<g<<","<<b;
}

void Sculptor::putVoxel(int x, int y, int z)
{
        if(!((x>= 0 && x<nx) && (y>= 0 && y<ny) && (z>= 0 && z<nz)) ){

            errorInterval();

        }else{
            v[x][y][z].isOn = true;
            v[x][y][z].r = r;
            v[x][y][z].g = g;
            v[x][y][z].b = b;
            v[x][y][z].a = a;
           qDebug() <<"criado um purVOxel "<< x <<"," <<y <<","<<z;
        }

}

void Sculptor::cutVoxel(int x, int y, int z)
{
    if(!((x>= 0 && x<nx) && (y>= 0 && y<ny) && (z>= 0 && z<nz)) ){

        errorInterval();

    }else {
v[x][y][z].isOn = false;
}

}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    if((x0>= 0 && x1<nx) && (y0>= 0 && y1<ny) && (z0>= 0 && z1<nz)){

        for( int i=x0 ;i<=x1;i++){
            for( int j=y0 ;j<=y1;j++){
                for( int k=z0 ;k<=z1;k++){
                    v[i][j][k].isOn = true;
                    v[i][j][k].r = r;
                    v[i][j][k].g = g;
                    v[i][j][k].b = b;
                    v[i][j][k].a = a;
                }
            }
        }
    }else {
        errorInterval();
    }

}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
     if((x0>= 0 && x1<nx) && (y0>= 0 && y1<ny) && (z0>= 0 && z1<nz)){

         for( int i=x0 ;i<=x1;i++){
             for( int j=y0 ;j<=y1;j++){
                 for( int k=z0 ;k<=z1;k++){
                     v[i][j][k].isOn = false;

                 }
             }
         }
     }else {
        errorInterval();
     }

}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    int positionX,positionY,positionZ;
    float result;

    if((xcenter <nx) &&(ycenter<ny) && (zcenter <nz)){

        for( int i=0 ;i<nx;i++){
            for( int j=0 ;j<ny;j++){
                for( int k=0 ;k<nz;k++){

                    positionX = xcenter - i;
                    positionY = ycenter - j;
                    positionZ = zcenter - k;

                    result = pow(positionX,2) + pow(positionY,2) + pow(positionZ,2);

                    result = sqrt(result);
                    if(result <=radius){
                        v[i][j][k].isOn = true;
                        v[i][j][k].r = r;
                        v[i][j][k].g = g;
                        v[i][j][k].b = b;
                        v[i][j][k].a = a;
                    }


                }
            }
        }

    }else {
        errorInterval();
}






}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    int positionX,positionY,positionZ;
    float result;

     if((xcenter <nx) &&(ycenter<ny) && (zcenter <nz)){
         for( int i=0 ;i<nx;i++){
             for( int j=0 ;j<ny;j++){
                 for( int k=0 ;k<nz;k++){

                     positionX = i - xcenter;
                     positionY = j - ycenter;
                     positionZ = k - zcenter;

                     result = pow(positionX,2) + pow(positionY,2) + pow(positionZ,2);

                     result = sqrt(result);
                     if(result <=radius){
                         v[i][j][k].isOn = false;

                     }


                 }
             }
         }
     }else {
        errorInterval();
 }


}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    float positionX,positionY,positionZ;
    float result;

      if((xcenter <nx) &&(ycenter<ny) && (zcenter <nz)){
          for( int i=0 ;i<nx;i++){
              for( int j=0 ;j<ny;j++){
                  for( int k=0 ;k<nz;k++){

                      positionX = (i - xcenter);
                      positionY = (j - ycenter);
                      positionZ = (k - zcenter);

                      result = (pow(positionX,2))/pow(rx,2) + (pow(positionY,2))/pow(ry,2) + (pow(positionZ,2))/pow(rz,2);

                      if( result <= 1 ){
                          v[i][j][k].isOn = true;
                          v[i][j][k].r = r;
                          v[i][j][k].g = g;
                          v[i][j][k].b = b;
                          v[i][j][k].a = a;

                      }


                  }
              }
          }
      }else {
          errorInterval();
  }


}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    float positionX,positionY,positionZ;
    float result;
     if((xcenter <nx) &&(ycenter<ny) && (zcenter <nz)){
         for( int i=0 ;i<nx;i++){
             for( int j=0 ;j<ny;j++){
                 for( int k=0 ;k<nz;k++){

                     positionX = (i - xcenter);
                     positionY = (j - ycenter);
                     positionZ = (k - zcenter);

                     result = (pow(positionX,2))/pow(rx,2) + (pow(positionY,2))/pow(ry,2) + (pow(positionZ,2))/pow(rz,2);

                     if( result <= 1 ){
                         v[i][j][k].isOn = false;


                     }


                 }
             }
         }
     }else {
        errorInterval();
 }

}

void Sculptor::writeOFF(char *filename)
{
     cout<<"Arquivo"<< endl;
    ofstream arquivo;
     arquivo.open(filename);

     if(arquivo.is_open() == true){
         cout << "Iniciando" << endl;
     }

     arquivo << "OFF" << endl;

     int numeros_Vox = 0;
     int numeros_Face = 0;

     for(int i = 0; i < nx; i++){
         for(int j = 0; j < ny; j++){
             for(int k = 0; k < nz; k++){
                 if (v[i][j][k].isOn == true){
                     numeros_Vox++;
                 }
             }
         }
     }

     arquivo << 8*numeros_Vox << " " << 6*numeros_Vox << " " << 0 << endl;

     for(int i = 0; i < nx; i++){
         for(int j = 0; j < ny; j++){
             for (int k = 0; k < nz; k++) {
                 if(v[i][j][k].isOn == true){
                     arquivo<<-0.5+i<<" "<<0.5+j<<" "<<-0.5+k<<endl;
                     arquivo<<-0.5+i<<" "<<-0.5+j<<" "<<-0.5+k<<endl;
                     arquivo<<0.5+i<<" "<<-0.5+j<<" "<<-0.5+k<<endl;
                     arquivo<<0.5+i<<" "<<0.5+j<<" "<<-0.5+k<<endl;
                     arquivo<<-0.5+i<<" "<<0.5+j<<" "<<0.5+k<<endl;
                     arquivo<<-0.5+i<<" "<<-0.5+j<<" "<<0.5+k<<endl;
                     arquivo<<0.5+i<<" "<<-0.5+j<<" "<<0.5+k<<endl;
                     arquivo<<0.5+i<<" "<<0.5+j<<" "<<0.5+k<<endl;
                 }
             }
         }
     }

       arquivo << fixed << setprecision(2); // numeros floats vão sair com 2 casa
     for(int i = 0; i < nx; i++){
         for(int j = 0; j < ny; j++){
             for (int k = 0; k< nz; k++) {
                 if(v[i][j][k].isOn == true){
                      arquivo<<"4 "<<0+numeros_Face*8<<" "<<3+numeros_Face*8<<" "<<2+numeros_Face*8<<" "<<1+numeros_Face*8<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl
                             <<"4 "<<4+numeros_Face*8<<" "<<5+numeros_Face*8<<" "<<6+numeros_Face*8<<" "<<7+numeros_Face*8<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl
                             <<"4 "<<0+numeros_Face*8<<" "<<1+numeros_Face*8<<" "<<5+numeros_Face*8<<" "<<4+numeros_Face*8<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl
                             <<"4 "<<0+numeros_Face*8<<" "<<4+numeros_Face*8<<" "<<7+numeros_Face*8<<" "<<3+numeros_Face*8<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl
                             <<"4 "<<3+numeros_Face*8<<" "<<7+numeros_Face*8<<" "<<6+numeros_Face*8<<" "<<2+numeros_Face*8<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl
                             <<"4 "<<1+numeros_Face*8<<" "<<2+numeros_Face*8<<" "<<6+numeros_Face*8<<" "<<5+numeros_Face*8<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                     numeros_Face++;
                 }
             }
         }
     }



     arquivo.close();
}

void Sculptor::errorInterval()
{
    qDebug() <<"Erro, algum valor esta fora do intervalo da matriz, nao e possivel realizar a operacao"<<endl;
     qDebug() <<"intervalo aceitavel"<<endl;
     qDebug() <<"X: "<<0 <<" a " << nx-1<<" Y: "<<0<<" a " << ny-1<<" Z: "<<0<<" a " << nz-1<<endl;
}

Voxel Sculptor::matrizShow(int x, int y, int z)
{
    return  v[x][y][z];
}
