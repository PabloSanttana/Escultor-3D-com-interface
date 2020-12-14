#ifndef JANELANEW_H
#define JANELANEW_H

#include <QDialog>

namespace Ui {
class JanelaNew;
}

/**
 * @brief A classe JanelaNew  é uma subclasse de QDialog,
 * Este método e responsável por mostrar uma segunda tela para a criação de um nova matriz
 */

class JanelaNew : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief JanelaNew Este método é o construtor da classe
     * @param parent variável do tipo ponteiro para QWidget
     */
    explicit JanelaNew(QWidget *parent = nullptr);
    /**
     * @brief ~JanelaNew Este método é o destrutor da classe
     *
     */
    ~JanelaNew();
    /**
     * @brief getDimX Este método retorna o valor da dimensão do eixo x da matriz
     * @return inteiro
     */
    int getDimX();
    /**
     * @brief getDimY Este método retorna o valor da dimensão do eixo y da matriz
     * @return inteiro
     */
    int getDimY();
    /**
     * @brief getDimZ Este método retorna o valor da dimensão do eixo z da matriz
     * @return inteiro
     */
    int getDimZ();

private:
    Ui::JanelaNew *ui;
};

#endif // JANELANEW_H
