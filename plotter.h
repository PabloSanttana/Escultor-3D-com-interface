#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>

/**
 * @brief A classe Plotter é responsavel pela interação do usuário com a matriz é tambem pela sua visualização
 */

class Plotter : public QWidget
{
    Q_OBJECT
private:
    int nx,ny,nz,coodX,coodY,coodZ,r,g,b,
    raioEsfera,
    rxElipse,ryElipse,rzElipse,
    dxCubo,dyCubo,dzCubo,selectedMetodo;
public:
    /**
     * @brief Plotter esse método é um construtor com parametro de entrada
     * @param parent  variavel ponteiro para QWidget
     */
    explicit Plotter(QWidget *parent = nullptr);
    /**
     * @brief Plotter contrutor da classe sem argumento
     */
    Plotter();
    /**
     * @brief ~Plotter destrutor da classe
     */
    ~Plotter();
    /**
     * @brief Plotter contrutor da uma nova matriz
     * @param _nx Variável do tipo inteiro que representa dimensão no eixo x
     * @param _ny Variável do tipo inteiro que representa dimensão no eixo y
     * @param _nz Variável do tipo inteiro que representa dimensão no eixo z
     */
    Plotter(int _nx,int _ny,int _nz);
    /**
     * @brief paintEvent Método responsável pela visualização da matriz em duas dimensões
     * @param event Variável ponteiro do tipo QPaintEvent
     */
    void paintEvent(QPaintEvent *event);
    /**
     * @brief mousePressEvent Método para captura evento de click no mouse
     * @param event variável ponteiro para QMouseEvent
     */
    void mousePressEvent(QMouseEvent *event);
    /**
     * @brief mouseMoveEvent  Método para captura evento do mouse
     * @param event variável ponteiro para QMouseEvent
     */
    void mouseMoveEvent(QMouseEvent *event);

signals:

    /**
       * @brief emitResetRed esse Método informa uma mudança na tonalidade vermelha
       * @param _r variável do tipo inteiro vai de 0 a 255
       */

      void emitResetRed(int _r);
      /**
       * @brief emitResetBlue este Método informa uma mudança na tonalidade azul
       * @param _b variável do tipo inteiro vai de 0 a 255
       */
      void emitResetBlue(int _b);
      /**
       * @brief emitResetGreen este Método informa uma mudança na tonalidade verde
       * @param _g variável do tipo inteiro vai de 0 a 255
       */
      void emitResetGreen(int _g);
      /**
       * @brief emitResetProfundidade este Método informa uma mudança na profundidade no eixo z da matriz
       * @param _f variável do tipo inteiro
       */
      void emitResetProfundidade(int _f);

      /**
       * @brief emitCursorX este Método informa uma mudança do mouse por cima do eixo x da matiz
       * @param _x variável do tipo inteiro
       */
      void emitCursorX(int _x);
      /**
       * @brief emitCursorY este Método informa uma mudança do mouse por cima do eixo y da matiz
       * @param _y variável do tipo inteiro
       */
      void emitCursorY(int _y);
      /**
       * @brief emitCursorZ este Método informa uma mudança do mouse por cima do eixo z da matiz
       * @param _z variável do tipo inteiro
       */
      void emitCursorZ(int _z);

public slots:
      /**
     * @brief setDimXYZ este método cria uma nova matriz com as dimensões desejadas
     * @param _nx variável do tipo inteiro representa a dimensão do eixo x
     * @param _ny variável do tipo inteiro representa a dimensão do eixo y
     * @param _nz variável do tipo inteiro representa a dimensão do eixo z
     */
    void setDimXYZ(int _nx,int _ny,int _nz);
    /**
     * @brief deleteMatrix deleta uma matriz
     */
    void deleteMatrix();
    /**
     * @brief setColors Este método mudar a cor do próximo objeto que será inserido na matriz
     * @param r variável do tipo inteiro representa a tonalidade vermelha
     * @param g variável do tipo inteiro representa a tonalidade verde
     * @param b variável do tipo inteiro representa a tonalidade azul
     */
    void setColors(int r,int g,int b);
    /**
     * @brief setCoodenadaZ Este métdo muda a profundidade da matrix no eixo z
     * @param _z variável do tipo inteiro
     */
    void setCoodenadaZ(int _z);
    /**
     * @brief saveFigure Este método para salvar a escultura
     */
    void saveFigure();

    /**
     * @brief setPutVoxel Este método cria um voxel
     */
    void setPutVoxel();
    /**
     * @brief setCutVoxel Este método remove um voxel
     */
    void setCutVoxel();
    /**
     * @brief setPutBox Este método cria uma caixa
     */
    void setPutBox();
    /**
     * @brief setCutBox Este método remove uma caixa
     */
    void setCutBox();
    /**
     * @brief setPutSphere Este método cria uma esfera
     */
    void setPutSphere();
    /**
     * @brief setCutSphere Este método remove uma esfera
     */
    void setCutSphere();
    /**
     * @brief setPutEllipsoid Este método cria um elipsoide
     */
    void setPutEllipsoid();
    /**
     * @brief setCutEllipsoid Este método remove um elipsoide
     */
    void setCutEllipsoid();
    /**
     * @brief setRaioEsfera Este método informa o raio da esfera
     * @param _r variável do tipo inteiro
     */

    void setRaioEsfera(int _r);
    /**
     * @brief setRaioXElipse Este método informa o raio do elipsoide no eixo x
     * @param _x variável do tipo inteiro
     */
    void setRaioXElipse(int _x);
    /**
     * @brief setRaioYElipse Este método informa o raio do elipsoide no eixo y
     * @param _y variável do tipo inteiro
     */
    void setRaioYElipse(int _y);
    /**
     * @brief setRaioZElipse Este método informa o raio do elipsoide no eixo z
     * @param _z variável do tipo inteiro
     */
    void setRaioZElipse(int _z);
    /**
     * @brief setDimXCubo Este método informa a dimensão da caixa no eixo x
     * @param _x variável do tipo inteiro
     */
    void setDimXCubo(int _x);
    /**
     * @brief setDimYCubo  Este método informa a dimensão da caixa no eixo y
     * @param _y variável do tipo inteiro
     */
    void setDimYCubo(int _y);
    /**
     * @brief setDimZCubo Este método informa a dimensão da caixa no eixo z
     * @param _z variável do tipo inteiro
     */
    void setDimZCubo(int _z);
    /**
     * @brief setMetodos Este método Seleciona  métodos da criação ou de remoção
     */
    void setMetodos();

};

#endif // PLOTTER_H
