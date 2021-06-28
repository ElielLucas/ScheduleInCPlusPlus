#ifndef INTERFACESCHEDULE_H
#define INTERFACESCHEDULE_H
#include<qmessagebox.h>
#include <QDialog>
#include<agenda.h>
#include<pessoa.h>
#include<pessoafisica.h>
#include<pessoajuridica.h>
namespace Ui {
class InterfaceSchedule;
}

class InterfaceSchedule : public QDialog
{
    Q_OBJECT

public:
    explicit InterfaceSchedule(QWidget *parent = nullptr);
    ~InterfaceSchedule();
    void setAgenda(tp2::Agenda* x);

    void on_pushButtonOrdenar_clicked();

    void on_pushButtonOrdenarNomes_clicked();

private:
    Ui::InterfaceSchedule *ui;
    tp2::Agenda* agenda;
};

#endif // INTERFACESCHEDULE_H
