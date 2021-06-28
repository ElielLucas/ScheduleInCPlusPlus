#include "interfaceschedule.h"
#include "ui_interfaceschedule.h"

InterfaceSchedule::InterfaceSchedule(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InterfaceSchedule)
{
    ui->setupUi(this);
    agenda=nullptr;
}

InterfaceSchedule::~InterfaceSchedule()
{
    delete ui;
}

void InterfaceSchedule::setAgenda(tp2::Agenda* x)
{
    agenda=x;

    try
    {
        QString saida="Agenda:\n\n***********************************************";
        bool ok=agenda->printAll(&saida);
        if(ok)ui->textEditResultado->setText(saida);
        else ui->textEditResultado->setText("A agenda está vazia!");

    }catch (QString erro)
    {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void InterfaceSchedule::on_pushButtonOrdenar_clicked()
{
    try
    {
        bool ok=agenda->ordenaIden();
        if(ok)
        {
            QString saida="Dados:\n\n***********************************************";
            agenda->printAll(&saida);
            saida+="\n\nOrdenado com sucesso!";
            ui->textEditResultado->setText(saida);
        }
    } catch (QString erro)
    {
        QMessageBox::information(this,"AVISO",erro);
    }

}

void InterfaceSchedule::on_pushButtonOrdenarNomes_clicked()
{
    try
    {
        bool ok=agenda->ordenaNomes();
        if(ok)
        {
            QString saida="Dados:\n\n***********************************************";
            agenda->printAll(&saida);
            saida+="\n\nOrdenado com sucesso!";
            ui->textEditResultado->setText(saida);
        }
    } catch (QString erro)
    {
        QMessageBox::information(this,"AVISO",erro);
    }
}
