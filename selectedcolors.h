#ifndef SELECTEDCOLORS_H
#define SELECTEDCOLORS_H

#include <QWidget>

/**
 * @brief A classe SelectedColors Serve para visualizar a cor que está selecionada no momento
 */

class SelectedColors : public QWidget
{
    Q_OBJECT
private:
    int r,g,b;
public:
    /**
     * @brief SelectedColors contrutor da classe com parametro
     * @param parent variável do tipo ponteiro para QWidget
     */
    explicit SelectedColors(QWidget *parent = nullptr);
    /**
     * @brief paintEvent método usado para vizualisação das cores selecionada
     * @param event variável do tipo ponteiro para QPaintEvent
     */
    void paintEvent(QPaintEvent *event);

signals:
    /**
     * @brief emitSelectedColors Este método informa a nova cor selecionada
     * @param _r variável do tipo inteiro
     * @param _g variável do tipo inteiro
     * @param _b variável do tipo inteiro
     */
    void emitSelectedColors(int _r,int _g,int _b);

public slots:
    /**
     * @brief setRed Este método informa a nova tonalidade da cor vermelha
     * @param _r variável do tipo inteiro
     */
    void setRed(int _r);
    /**
     * @brief setBlue Este método informa a nova tonalidade da cor azul
     * @param _b variável do tipo inteiro
     */
    void setBlue(int _b);
    /**
     * @brief setGreen Este método informa a nova tonalidade da cor verde
     * @param _gvariável do tipo inteiro
     */
    void setGreen(int _g);

};

#endif // SELECTEDCOLORS_H
