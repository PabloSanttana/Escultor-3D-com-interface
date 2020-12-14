#ifndef SCULPTOR_H
#define SCULPTOR_H

#include "Voxel.h"


class Sculptor{

protected:
    Voxel *** v;
    int nx,ny,nz;
    float r,g,b,a;


public:
    /**
     * @brief Sculptor é o construtor da classe e gera uma matriz com as dimensões desejadas
     * @param _nx é a dimensão no eixo x
     * @param _ny é a dimensão no eixo y
     * @param _nz é a dimensão no eixo z
     *
     */

    Sculptor(int _nx, int _ny, int _nz);
    /**
     * @brief ~Sculpor destrutor da classe
     */
    ~Sculptor();
    /**
     * @brief setColor selecionar a cor que será aplicadas nos próximos metodos e a opacidade deles
     * @param r é um float que vária de 0.00 a 1.00 que representa a intensidade da cor vermalha
     * @param g é um float que vária de 0.00 a 1.00 que representa a intensidade da cor verde
     * @param b é um float que vária de 0.00 a 1.00 que representa a intensidade da cor azul
     * @param alpha é um float que vária de 0.00 a 1.00 que representa a opacidade
     *
     */
    void setColor(float r, float g, float b, float alpha);

    /**
     * @brief putVoxel esse método cria um cubo unico nas coordenadas desejadas
     * @param x é um inteiro que representa a coordenada no eixo x
     * @param y é um inteiro que representa a coordenada no eixo y
     * @param z é um inteiro que representa a coordenada no eixo z
     *
     *
     */

    void putVoxel(int x, int y, int z);
    /**
     * @brief cutVoxel esse método remove um cubo unico nas coordenadas desejadas
     * @param x é um inteiro que representa a coordenada no eixo x
     * @param y é um inteiro que representa a coordenada no eixo y
     * @param z é um inteiro que representa a coordenada no eixo z
     *
     */
    void cutVoxel(int x, int y, int z);
    /**
     * @brief putBox esse método faz uma área de dimensões desejadas nas coordenadas indicadas, desde que esteja
     * dentro dos limites da matriz 3D.
     * @param x0 é um inteiro que representa o início no eixo x
     * @param x1 é um inteiro que representa o final  no eixo x
     * @param y0 é um inteiro que representa o início no eixo y
     * @param y1 é um inteiro que representa o final  no eixo y
     * @param z0 é um inteiro que representa o início  no eixo z
     * @param z1 é um inteiro que representa o final  no eixo z
     *
     *
     */
    void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
    /**
     * @brief cutBox esse método remove uma área de dimensões desejadas nas coordenadas indicadas, desde que esteja
     * dentro dos limites da matriz 3D.
     * @param x0 é um inteiro que representa o início no eixo x
     * @param x1 é um inteiro que representa o final  no eixo x
     * @param y0 é um inteiro que representa o início no eixo y
     * @param y1 é um inteiro que representa o final  no eixo y
     * @param z0 é um inteiro que representa o início no eixo z
     * @param z1 é um inteiro que representa o final  no eixo z
     *
     */
    void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
    /**
     * @brief putSphere esse método faz uma esfera de raio desejado nas coordenadas indicadas, desde que esteja
     * dentro dos limites da matriz 3D.
     * @param xcenter é um inteiro que é a coordenada do centro da esfera no eixo x
     * @param ycenter é um inteiro que é a coordenada do centro da esfera no eixo y
     * @param zcenter é um inteiro que é a coordenada do centro da esfera no eixo z
     * @param radius é um inteiro que é o raio da esfera
     *
     */
    void putSphere(int xcenter, int ycenter, int zcenter, int radius);
    /**
     * @brief cutSphere esse método remove uma esfera de raio desejado nas coordenadas indicadas, desde que esteja
     * dentro dos limites da matriz 3D.
     * @param xcenter é um inteiro que é a coordenada do centro da esfera no eixo x
     * @param ycenter é um inteiro que é a coordenada do centro da esfera no eixo y
     * @param zcenter é um inteiro que é a coordenada do centro da esfera no eixo z
     * @param radius é um inteiro que é o raio da esfera
     *
     *
     *
     */
    void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
    /**
     * @brief putEllipsoid esse método faz uma elipse de raios desejados nas coordenadas indicadas, desde que esteja
     * dentro dos limites da matriz 3D.
     * @param xcenter  é um inteiro que é a coordenada do centro da elipse no eixo x
     * @param ycenter  é um inteiro que é a coordenada do centro da elipse no eixo x
     * @param zcenter  é um inteiro que é a coordenada do centro da elipse no eixo x
     * @param rx é um inteiro que é o raio da elipse no eixo x
     * @param ry é um inteiro que é o raio da elipse no eixo y
     * @param rz é um inteiro que é o raio da elipse no eixo z
     */
    void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    /**
     * @brief cutEllipsoid esse método remove uma elipse de raios desejados nas coordenadas indicadas, desde que esteja
     * dentro dos limites da matriz 3D.
     * @param xcenter  é um inteiro que é a coordenada do centro da elipse no eixo x
     * @param ycenter  é um inteiro que é a coordenada do centro da elipse no eixo x
     * @param zcenter  é um inteiro que é a coordenada do centro da elipse no eixo x
     * @param rx é um inteiro que é o raio da elipse no eixo x
     * @param ry é um inteiro que é o raio da elipse no eixo y
     * @param rz é um inteiro que é o raio da elipse no eixo z
     */
    void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    /**
     * @brief writeOFF esse método criar um arquivo com a extessão .OFF que serve para vizualizar as esculturas que fazemos.
     * @param filename é um ponteiro pra char que é basicamento o nome do arquivo mais .off
     *
     *
     */
    void writeOFF(char* filename);
    /**
     * @brief errorInterval esse método é para mostrar erro de intervalo
     */

    void errorInterval(void);

    /**
     * @brief matrizShow esse método retorna um determinado voxel da matriz
     * @param x é um inteiro que é a coordenada eixo x
     * @param y é um inteiro que é a coordenada eixo y
     * @param z é um inteiro que é a coordenada eixo z
     * @return
     */

    Voxel matrizShow(int x,int y,int z);

};

#endif // SCULPTOR_H
