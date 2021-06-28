#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMainWindow>
#include<QMessageBox>
#include<interfacephysicalperson.h>
#include<interfacelegalperson.h>
#include<interfaceschedule.h>

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

    tp2::Agenda* getAgenda(){return agenda;}

private slots:
    void on_pushButtonPessoaFisica_clicked();

    void on_pushButtonAgenda_clicked();

    void on_pushButtonPessoaJuridica_clicked();

private:
    Ui::MainWindow *ui;
    tp2::Agenda *agenda;
};
#endif // MAINWINDOW_H
