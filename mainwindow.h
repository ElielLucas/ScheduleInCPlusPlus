#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QMessageBox>
#include<agenda.h>
#include<pessoafisica.h>
#include<pessoajuridica.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void desabilitarNome();
    void desabilitarEndereco();
    void desabilitarEmail();
    void desabilitarCpf();
    void desabilitarData();
    void desabilitarEstadoCivil();
    void desabilitarCnpj();
    void desabilitarInscricaoEstadual();
    void desabilitarRazaoSocial();

    void habilitarNome();
    void habilitarEndereco();
    void habilitarEmail();
    void habilitarCpf();
    void habilitarData();
    void habilitarEstadoCivil();
    void habilitarCnpj();
    void habilitarInscricaoEstadual();
    void habilitarRazaoSocial();

    void desabilitarCheks();
    void habilitarCheks();
    void desabilitarCheksAdicionar();
    void habilitarCheksAdicionar();
    void desabilitarCheksProcurarIden();
    void habilitarCheksProcurarIden();
    void desabilitarCheksProcurarNome();
    void habilitarCheksProcurarNome();
    void desabilitarCheksRemoverIden();
    void habilitarCheksRemoverIden();
    void desabilitarCheksRemoverNome();
    void habilitarCheksRemoverNome();
    void desabilitarCheksMostrar();
    void habilitarCheksMostrar();


private slots:

    void on_checkBoxAdicionar_stateChanged(int arg1);

    void on_checkBoxProcurarIden_stateChanged(int arg1);

    void on_checkBoxRemoverIden_stateChanged(int arg1);

    void on_checkBoxMostrar_stateChanged(int arg1);

    void on_pushButtonStart_clicked();

    void on_radioButtonPessoaFisica_clicked();

    void on_radioButtonPessoaJuridica_clicked();

    void on_checkBoxProcurarNome_stateChanged(int arg1);

    void on_checkBoxRemoverNome_stateChanged(int arg1);

    void on_pushButtonOrdenar_clicked();

    void on_pushButtonOrdenarNomes_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
