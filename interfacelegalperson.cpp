#include "interfacelegalperson.h"
#include "ui_interfacelegalperson.h"

InterfaceLegalPerson::InterfaceLegalPerson(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InterfaceLegalPerson)
{
    ui->setupUi(this);
    agenda=nullptr;
}

InterfaceLegalPerson::~InterfaceLegalPerson()
{
    delete ui;
}

void InterfaceLegalPerson::on_pushButtonStartCadastro_clicked()
{
    try
    {
        QString nome=ui->lineEditNome_2->text();
        QString endereco=ui->lineEditEndereco_2->text();
        QString email=ui->lineEditEmail_2->text();
        QString razaoSocial=ui->lineEditRazaoSocial->text();
        long long inscricaoEstadual=ui->lineEditInscricaoEstadual->text().toLongLong();
        long long cnpj=ui->lineEditCnpj->text().toLongLong();
        tp2::Pessoa* pesso=new tp2::PessoaJuridica (nome, endereco, email, cnpj, inscricaoEstadual, razaoSocial);

        QString aux;
        bool ok=agenda->searchIdentifica(pesso->getIdentifica(),&aux);
        if(!ok)
        {
            ok = agenda->pushPessoa(pesso);
            if(ok) QMessageBox::information(this,"Adicionado na Agenda",pesso->print());
            else  throw QString("Não foi possível inserir!");
        }else throw QString("Já existe uma pessoa jurídica com esse número de documento!");

    }catch (QString erro)
    {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void InterfaceLegalPerson::on_pushButtonStartSearchCnpj_clicked()
{
    try
    {
        long long iden=0;
        iden=ui->lineEditCnpj->text().toLongLong();

        QString saida="Dados: ";
        bool ok = agenda->searchIdentifica(iden,&saida);

        if(ok)ui->textEditResultadoSearchCnpj->setText(saida);
        else ui->textEditResultadoSearchCnpj->setText("Não foi possível encontrar!");

    }catch (QString erro)
    {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void InterfaceLegalPerson::on_pushButtonStartSearchName_clicked()
{
    try
    {
        QString saida="Dados:";
        QString nome=ui->lineEditNome->text();

        bool ok = agenda->searchNome(nome,&saida);
        if(ok)ui->textEditResultadoSearchNome->setText(saida);
        else ui->textEditResultadoSearchNome->setText("Não foi possível encontrar!");

    }catch (QString erro)
    {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void InterfaceLegalPerson::on_pushButtonStartRemoveCnpj_clicked()
{
    try
    {
        QString saida="Dados: ";
        long long iden=0;
        iden=ui->lineEditCnpj->text().toLongLong();

        bool ok = agenda->removeIdentificacao(iden,&saida);
        if(ok)QMessageBox::information(this,"Removido da Agenda",saida);
        else ui->textEditResultadoRemoveCnpj->setText("Não foi possível remover!");

    }catch (QString erro)
    {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void InterfaceLegalPerson::on_pushButtonStartRemoveName_clicked()
{
    try
    {
        QString saida="Dados: ";
        QString nome=ui->lineEditNome->text();

        bool ok = agenda->removeNome(nome,&saida);
        if(ok) QMessageBox::information(this,"Removido da Agenda",saida);
        else ui->textEditResultadoRemoveNome->setText("Não foi possível remover!");
    }catch (QString erro)
    {
        QMessageBox::information(this,"ERRO",erro);
    }
}
