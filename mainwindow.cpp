#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    agenda = new tp2::Agenda;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonPessoaFisica_clicked()
{
    InterfacePhysicalPerson pf;
    pf.setAgenda(agenda);
    pf.exec();
}

void MainWindow::on_pushButtonAgenda_clicked()
{
    InterfaceSchedule agen;
    agen.setAgenda(agenda);
    agen.exec();
}

void MainWindow::on_pushButtonPessoaJuridica_clicked()
{
    InterfaceLegalPerson lp;
    lp.setAgenda(agenda);
    lp.exec();
}
