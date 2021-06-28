#include "interfacephysicalperson.h"
#include "ui_interfacephysicalperson.h"

InterfacePhysicalPerson::InterfacePhysicalPerson(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InterfacePhysicalPerson)
{
    ui->setupUi(this);
    agenda=nullptr;
}


InterfacePhysicalPerson::~InterfacePhysicalPerson()
{
    delete ui;
}

void InterfacePhysicalPerson::on_pushButtonStartCadastro_clicked()
{
    try
    {
        QString nome=ui->lineEditNome_2->text();
        QString endereco=ui->lineEditEndereco_2->text();
        QString email=ui->lineEditEmail_2->text();

        int dia=ui->lineEditDia_2->text().toInt();
        int mes=ui->lineEditMes_2->text().toInt();
        int ano=ui->lineEditAno_2->text().toInt();
        QString estCivil=ui->lineEditEstadoCivil_2->text();
        long long cpf=ui->lineEditCpf_2->text().toLongLong();
        tp2::Pessoa* pesso=new tp2::PessoaFisica(nome, endereco, email, cpf, dia, mes, ano, estCivil);

        QString aux;
        bool ok=agenda->searchIdentifica(pesso->getIdentifica(),&aux);
        if(!ok)
        {
            ok=agenda->pushPessoa(pesso);
            if(ok) QMessageBox::information(this,"Adicionado na Agenda",pesso->print());
            else  throw QString("Não foi possível inserir!");
        }else throw QString("Já existe uma pessoa com esse número de documento!");

    }catch (QString erro)
    {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void InterfacePhysicalPerson::on_pushButtonStartSearchCPF_clicked()
{
    try
    {
        QString saida="Dados: ";
        long long iden=0;
        iden=ui->lineEditCpfSearch->text().toLongLong();

        bool ok=agenda->searchIdentifica(iden,&saida);

        if(ok)ui->textEditResultadoSearchCpf->setText(saida);
        else ui->textEditResultadoSearchCpf->setText("Não foi possível encontrar!");

    }catch (QString erro)
    {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void InterfacePhysicalPerson::on_pushButtonStartSearchName_clicked()
{
    try
    {
        QString saida="Dados:";
        QString nome=ui->lineEditNomeSearch->text();

        bool ok=agenda->searchNome(nome,&saida);
        if(ok)ui->textEditResultadoSearchNome->setText(saida);
        else ui->textEditResultadoSearchNome->setText("Não foi possível encontrar!");

    }catch (QString erro)
    {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void InterfacePhysicalPerson::on_pushButtonStartRemoveCpf_clicked()
{
    try
    {
        QString saida="Dados: ";
        long long iden=0;
        iden=ui->lineEditCpfRemove->text().toLongLong();

        bool ok=agenda->removeIdentificacao(iden,&saida);
        if(ok)QMessageBox::information(this,"Removido da Agenda",saida);
        else ui->textEditResultadoRemoveCpf->setText("Não foi possível remover!");

    }catch(QString erro)
    {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void InterfacePhysicalPerson::on_pushButtonStartRemoveName_clicked()
{
    try
    {
        QString saida="Dados: ";
        QString nome=ui->lineEditNomeRemove->text();

        bool ok=agenda->removeNome(nome,&saida);
        if(ok) QMessageBox::information(this,"Removido da Agenda",saida);
        else ui->textEditResultadoRemoveNome->setText("Não foi possível remover!");

    }catch(QString erro)
    {
        QMessageBox::information(this,"ERRO",erro);
    }
}
