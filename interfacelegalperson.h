#ifndef INTERFACELEGALPERSON_H
#define INTERFACELEGALPERSON_H
#include<qmessagebox.h>
#include <QDialog>
#include<agenda.h>
#include<pessoa.h>
#include<pessoafisica.h>
#include<pessoajuridica.h>

namespace Ui {
class InterfaceLegalPerson;
}

class InterfaceLegalPerson : public QDialog
{
    Q_OBJECT

public:
    explicit InterfaceLegalPerson(QWidget *parent = nullptr);
    ~InterfaceLegalPerson();
    void setAgenda(tp2::Agenda* x){agenda=x;}

private slots:
    void on_pushButtonStartCadastro_clicked();

    void on_pushButtonStartSearchCnpj_clicked();

    void on_pushButtonStartSearchName_clicked();

    void on_pushButtonStartRemoveCnpj_clicked();

    void on_pushButtonStartRemoveName_clicked();

private:
    Ui::InterfaceLegalPerson *ui;
    tp2::Agenda* agenda;
};

#endif // INTERFACELEGALPERSON_H
