#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief A classe MainWindow é uma subclasse de  QMainWindow
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief MainWindow clase construtor com parametro
     * @param parent variável do tipo ponteiro para QWidget
     */
    MainWindow(QWidget *parent = nullptr);
    /**
     * @brief ~MainWindow Este método é o destrutor da classe
     *
     */
    ~MainWindow();

public slots:
    /**
     * @brief openJanelaNew Este método abre uma janela para a criação de uma nova matriz
     */
    void openJanelaNew(void);

private slots:

    /**
     * @brief on_pushButtonPutVoxel_clicked Este método selecionar o PutVoxel
     */
    void on_pushButtonPutVoxel_clicked();
    /**
     * @brief on_pushButtonCutVoxel_clicked Este método selecionar o CutVoxel
     */

    void on_pushButtonCutVoxel_clicked();
    /**
     * @brief on_pushButtonPutBox_clicked Este método selecionar o PutBox
     */

    void on_pushButtonPutBox_clicked();
    /**
     * @brief on_pushButtonCutBox_clicked Este método selecionar o CutBox
     */
    void on_pushButtonCutBox_clicked();
    /**
     * @brief on_pushButtonPutSphere_clicked Este método selecionar o PutSphere
     */

    void on_pushButtonPutSphere_clicked();
    /**
     * @brief on_pushButtonCutSphere_clicked Este método selecionar o CutSphere
     */

    void on_pushButtonCutSphere_clicked();
    /**
     * @brief on_pushButtonPutEllipsoid_clicked Este método selecionar o PutEllipsoid
     */

    void on_pushButtonPutEllipsoid_clicked();
    /**
     * @brief on_pushButtonCutEllipsoid_clicked  Este método selecionar o CutEllipsoid
     */

    void on_pushButtonCutEllipsoid_clicked();
    /**
     * @brief closed este método fecha o programa
     */

    void closed();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
