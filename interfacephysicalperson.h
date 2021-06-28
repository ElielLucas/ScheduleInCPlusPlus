#ifndef INTERFACEPHYSICALPERSON_H
#define INTERFACEPHYSICALPERSON_H
#include<qmessagebox.h>
#include <QDialog>
#include<agenda.h>
#include<pessoa.h>
#include<pessoafisica.h>
#include<pessoajuridica.h>
namespace Ui {
class InterfacePhysicalPerson;
}

class InterfacePhysicalPerson : public QDialog
{
    Q_OBJECT

public:
    explicit InterfacePhysicalPerson(QWidget *parent = nullptr);
    ~InterfacePhysicalPerson();
    void setAgenda(tp2::Agenda* x){agenda=x;}

private slots:
    void on_pushButtonStartCadastro_clicked();

    void on_pushButtonStartSearchCPF_clicked();

    void on_pushButtonStartSearchName_clicked();

    void on_pushButtonStartRemoveCpf_clicked();

    void on_pushButtonStartRemoveName_clicked();

private:
    Ui::InterfacePhysicalPerson *ui;
    tp2::Agenda *agenda;
};

#endif // INTERFACEPHYSICALPERSON_H
