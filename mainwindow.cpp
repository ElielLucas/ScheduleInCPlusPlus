#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    desabilitarNome();
    desabilitarEndereco();
    desabilitarEmail();
    desabilitarCpf();
    desabilitarData();
    desabilitarEstadoCivil();
    desabilitarCnpj();
    desabilitarInscricaoEstadual();
    desabilitarRazaoSocial();

    desabilitarCheks();
    habilitarCheks();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::desabilitarNome()
{
    ui->lineEditNome->setDisabled(true);
    ui->labelNome->setDisabled(true);
}
void MainWindow::desabilitarEndereco()
{
    ui->lineEditEndereco->setDisabled(true);
    ui->labelEndereco->setDisabled(true);
}
void MainWindow::desabilitarEmail()
{
    ui->lineEditEmail->setDisabled(true);
    ui->labelEmail->setDisabled(true);
}
void MainWindow::desabilitarCpf()
{
    ui->lineEditCpf->setDisabled(true);
    ui->labelCpf->setDisabled(true);
}
void MainWindow::desabilitarData()
{
    ui->lineEditDia->setDisabled(true);
    ui->lineEditMes->setDisabled(true);
    ui->lineEditAno->setDisabled(true);
    ui->labelData->setDisabled(true);
    ui->labelBarra1->setDisabled(true);
    ui->labelBarra2->setDisabled(true);
}
void MainWindow::desabilitarEstadoCivil()
{
    ui->lineEditEstadoCivil->setDisabled(true);
    ui->labelEstadoCivil->setDisabled(true);
}
void MainWindow::desabilitarCnpj()
{
    ui->lineEditCnpj->setDisabled(true);
    ui->labelCnpj->setDisabled(true);
}
void MainWindow::desabilitarInscricaoEstadual()
{
    ui->lineEditInscricaoEstadual->setDisabled(true);
    ui->labelInscricaoEstadual->setDisabled(true);
}
void MainWindow::desabilitarRazaoSocial()
{
    ui->lineEditRazaoSocial->setDisabled(true);
    ui->labelRazaoSocial->setDisabled(true);
}
void MainWindow::habilitarNome()
{
    ui->lineEditNome->setEnabled(true);
    ui->labelNome->setEnabled(true);
}
void MainWindow::habilitarEndereco()
{
    ui->lineEditEndereco->setEnabled(true);
    ui->labelEndereco->setEnabled(true);
}
void MainWindow::habilitarEmail()
{
    ui->lineEditEmail->setEnabled(true);
    ui->labelEmail->setEnabled(true);
}
void MainWindow::habilitarCpf()
{
    ui->lineEditCpf->setEnabled(true);
    ui->labelCpf->setEnabled(true);
}
void MainWindow::habilitarData()
{
    ui->lineEditDia->setEnabled(true);
    ui->lineEditMes->setEnabled(true);
    ui->lineEditAno->setEnabled(true);
    ui->labelBarra1->setEnabled(true);
    ui->labelBarra2->setEnabled(true);
    ui->labelData->setEnabled(true);
}
void MainWindow::habilitarEstadoCivil()
{
    ui->lineEditEstadoCivil->setEnabled(true);
    ui->labelEstadoCivil->setEnabled(true);
}
void MainWindow::habilitarCnpj()
{
    ui->lineEditCnpj->setEnabled(true);
    ui->labelCnpj->setEnabled(true);
}
void MainWindow::habilitarInscricaoEstadual()
{
    ui->lineEditInscricaoEstadual->setEnabled(true);
    ui->labelInscricaoEstadual->setEnabled(true);
}
void MainWindow::habilitarRazaoSocial()
{
    ui->lineEditRazaoSocial->setEnabled(true);
    ui->labelRazaoSocial->setEnabled(true);
}
void MainWindow::desabilitarCheks()
{
    desabilitarCheksAdicionar();
    desabilitarCheksProcurarIden();
    desabilitarCheksRemoverIden();
    desabilitarCheksProcurarNome();
    desabilitarCheksRemoverNome();
    desabilitarCheksMostrar();
}
void MainWindow::habilitarCheks()
{
    habilitarCheksAdicionar();
    habilitarCheksProcurarIden();
    habilitarCheksProcurarNome();
    habilitarCheksRemoverIden();
    habilitarCheksRemoverNome();
    habilitarCheksMostrar();
}
void MainWindow::desabilitarCheksAdicionar()
{
    ui->checkBoxAdicionar->setDisabled(true);
}
void MainWindow::habilitarCheksAdicionar()
{
    ui->checkBoxAdicionar->setEnabled(true);
}
void MainWindow::desabilitarCheksProcurarIden()
{
    ui->checkBoxProcurarIden->setDisabled(true);
}
void MainWindow::habilitarCheksProcurarIden()
{
    ui->checkBoxProcurarIden->setEnabled(true);
}
void MainWindow::desabilitarCheksProcurarNome()
{
    ui->checkBoxProcurarNome->setDisabled(true);
}
void MainWindow::habilitarCheksProcurarNome()
{
    ui->checkBoxProcurarNome->setEnabled(true);
}
void MainWindow::desabilitarCheksRemoverIden()
{
    ui->checkBoxRemoverIden->setDisabled(true);
}
void MainWindow::habilitarCheksRemoverIden()
{
    ui->checkBoxRemoverIden->setEnabled(true);
}
void MainWindow::desabilitarCheksRemoverNome()
{
    ui->checkBoxRemoverNome->setDisabled(true);
}
void MainWindow::habilitarCheksRemoverNome()
{
    ui->checkBoxRemoverNome->setEnabled(true);
}
void MainWindow::desabilitarCheksMostrar()
{
    ui->checkBoxMostrar->setDisabled(true);
}
void MainWindow::habilitarCheksMostrar()
{
    ui->checkBoxMostrar->setEnabled(true);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
tp2::Agenda agenda;
tp2::Pessoa *pesso;
void MainWindow::on_pushButtonStart_clicked()
{
    try
    {
        if(!ui->checkBoxAdicionar->isChecked() && !ui->checkBoxProcurarIden->isChecked() &&
           !ui->checkBoxProcurarNome->isChecked() && !ui->checkBoxRemoverIden->isChecked() &&
           !ui->checkBoxRemoverNome->isChecked() && !ui->checkBoxMostrar->isChecked())
            throw QString("Escolha uma das funções acima!");
        if((ui->radioButtonPessoaFisica->isChecked() || ui->radioButtonPessoaJuridica->isChecked()) && ui->checkBoxAdicionar->isChecked())
        {
            QString nome=ui->lineEditNome->text();
            QString endereco=ui->lineEditEndereco->text();
            QString email=ui->lineEditEmail->text();
            if(ui->radioButtonPessoaFisica->isChecked())
            {
                int dia=ui->lineEditDia->text().toInt();
                int mes=ui->lineEditMes->text().toInt();
                int ano=ui->lineEditAno->text().toInt();
                QString estCivil=ui->lineEditEstadoCivil->text();
                long long cpf=ui->lineEditCpf->text().toLongLong();
                pesso=new tp2::PessoaFisica(nome, endereco, email, cpf, dia, mes, ano, estCivil);
            }else if(ui->radioButtonPessoaJuridica->isChecked())
            {
                QString razaoSocial=ui->lineEditRazaoSocial->text();
                long long inscricaoEstadual=ui->lineEditInscricaoEstadual->text().toLongLong();
                long long cnpj=ui->lineEditCnpj->text().toLongLong();
                pesso=new tp2::PessoaJuridica (nome, endereco, email, cnpj, inscricaoEstadual, razaoSocial);
            }
            QString aux;
            bool eae=agenda.searchIdentifica(pesso->getIdentifica(),&aux);
            if(!eae)
            {
                eae=agenda.pushPessoa(pesso);
                if(eae) QMessageBox::information(this,"Adicionado na Agenda",pesso->print());
                else  ui->textEditResultado->setText("Não foi possível inserir!");
            }else throw QString("Já existe uma pessoa com esse número de documento!");

        }else if((ui->radioButtonPessoaFisica->isChecked() || ui->radioButtonPessoaJuridica->isChecked())  && ui->checkBoxProcurarIden->isChecked())
        {
           long long iden=0;
           if(ui->radioButtonPessoaFisica->isChecked()) iden=ui->lineEditCpf->text().toLongLong();
           else if(ui->radioButtonPessoaJuridica->isChecked()) iden=ui->lineEditCnpj->text().toLongLong();

           QString saida="Dados: ";
           bool eae=agenda.searchIdentifica(iden,&saida);

           if(eae)ui->textEditResultado->setText(saida);
           else ui->textEditResultado->setText("Não foi possível encontrar!");
        }else if((ui->radioButtonPessoaFisica->isChecked() || ui->radioButtonPessoaJuridica->isChecked())  && ui->checkBoxProcurarNome->isChecked())
        {
           QString nome=ui->lineEditNome->text();
           QString saida="Dados:";
           bool eae=agenda.searchNome(nome,&saida);
           if(eae)ui->textEditResultado->setText(saida);
           else ui->textEditResultado->setText("Não foi possível encontrar!");

        }else if((ui->radioButtonPessoaFisica->isChecked() || ui->radioButtonPessoaJuridica->isChecked()) && ui->checkBoxRemoverIden->isChecked())
        {
            long long iden=0;
            if(ui->radioButtonPessoaFisica->isChecked())iden=ui->lineEditCpf->text().toLongLong();
            else if(ui->radioButtonPessoaJuridica->isChecked()) iden=ui->lineEditCnpj->text().toLongLong();

            QString saida="Dados: ";
            bool eae=agenda.removeIdentificacao(iden,&saida);
            if(eae)QMessageBox::information(this,"Removido da Agenda",saida);
            else ui->textEditResultado->setText("Não foi possível remover!");
       }else if((ui->radioButtonPessoaFisica->isChecked() || ui->radioButtonPessoaJuridica->isChecked()) && ui->checkBoxRemoverNome->isChecked())
       {
           QString nome=ui->lineEditNome->text();
           QString saida="Dados: ";

           bool eae=agenda.removeNome(nome,&saida);
           if(eae) QMessageBox::information(this,"Removido da Agenda",saida);
           else ui->textEditResultado->setText("Não foi possível remover!");

       }else if(ui->checkBoxMostrar->isChecked())
       {
          QString saida="Agenda:\n\n***********************************************";
          bool eae=agenda.printAll(&saida);
          if(eae)ui->textEditResultado->setText(saida);
          else ui->textEditResultado->setText("A agenda está vazia!");
       }
    }catch (QString erro)
    {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButtonOrdenar_clicked()
{
    try
    {
        bool eae=agenda.ordenaIden();
        if(eae)
        {
            QString saida="Dados:\n\n***********************************************";
            agenda.printAll(&saida);
            saida+="\n\nOrdenado com sucesso!";
            ui->textEditResultado->setText(saida);
        }
    } catch (QString erro)
    {
        QMessageBox::information(this,"AVISO",erro);
    }

}

void MainWindow::on_pushButtonOrdenarNomes_clicked()
{
    try
    {
        bool eae=agenda.ordenaNomes();
        if(eae)
        {
            QString saida="Dados:\n\n***********************************************";
            agenda.printAll(&saida);
            saida+="\n\nOrdenado com sucesso!";
            ui->textEditResultado->setText(saida);
        }
    } catch (QString erro)
    {
        QMessageBox::information(this,"AVISO",erro);
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void MainWindow::on_checkBoxAdicionar_stateChanged(int arg1)
{
    try
    {
        if(arg1)
        {
            if(!ui->radioButtonPessoaFisica->isChecked() && !ui->radioButtonPessoaJuridica->isChecked())throw QString("Escolha sua categoria de pessoa!");
            desabilitarCheksProcurarIden();
            desabilitarCheksRemoverIden();
            desabilitarCheksProcurarNome();
            desabilitarCheksRemoverNome();
            desabilitarCheksMostrar();
            if(ui->radioButtonPessoaFisica->isChecked())
            {
                habilitarNome();
                habilitarEndereco();
                habilitarEmail();
                habilitarData();
                habilitarCpf();
                habilitarEstadoCivil();
            }else if(ui->radioButtonPessoaJuridica->isChecked())
            {
                habilitarNome();
                habilitarEndereco();
                habilitarEmail();
                habilitarRazaoSocial();
                habilitarCnpj();
                habilitarInscricaoEstadual();
            }
        }else
        {
            habilitarCheks();
            ui->lineEditNome->clear();
            ui->lineEditEndereco->clear();
            ui->lineEditEmail->clear();
            ui->lineEditRazaoSocial->clear();
            ui->lineEditCnpj->clear();
            ui->lineEditInscricaoEstadual->clear();
            ui->lineEditDia->clear();
            ui->lineEditMes->clear();
            ui->lineEditAno->clear();
            ui->lineEditCpf->clear();
            ui->lineEditEstadoCivil->clear();
            ui->textEditResultado->clear();
            desabilitarNome();
            desabilitarEndereco();
            desabilitarEmail();
            desabilitarRazaoSocial();
            desabilitarCnpj();
            desabilitarInscricaoEstadual();
            desabilitarData();
            desabilitarCpf();
            desabilitarEstadoCivil();
        }
    }catch (QString erro)
    {
        QMessageBox::information(this,"AVISO",erro);
    }
}

void MainWindow::on_checkBoxProcurarIden_stateChanged(int arg1)
{  
    try
    {
        if(arg1)
        {
            if(!ui->radioButtonPessoaFisica->isChecked() && !ui->radioButtonPessoaJuridica->isChecked())throw QString("Escolha sua categoria de pessoa!");
            desabilitarCheksAdicionar();
            desabilitarCheksRemoverIden();
            desabilitarCheksProcurarNome();
            desabilitarCheksRemoverNome();
            desabilitarCheksMostrar();
            if(ui->radioButtonPessoaFisica->isChecked())
            {
                habilitarCpf();
            }else if(ui->radioButtonPessoaJuridica->isChecked())
            {
                habilitarCnpj();
            }

        }else
        {
            habilitarCheks();
            ui->lineEditCpf->clear();
            ui->lineEditCnpj->clear();
            ui->textEditResultado->clear();
            desabilitarCpf();
            desabilitarCnpj();
        }
    }catch (QString erro)
    {
        QMessageBox::information(this,"AVISO",erro);
    }
}

void MainWindow::on_checkBoxRemoverIden_stateChanged(int arg1)
{
    try
    {
        if(arg1)
        {
            if(!ui->radioButtonPessoaFisica->isChecked() && !ui->radioButtonPessoaJuridica->isChecked())throw QString("Escolha sua categoria de pessoa!");
            desabilitarCheksProcurarIden();
            desabilitarCheksProcurarNome();
            desabilitarCheksRemoverNome();
            desabilitarCheksAdicionar();
            desabilitarCheksMostrar();
            if(ui->radioButtonPessoaFisica->isChecked())
            {
                habilitarCpf();
            }else if(ui->radioButtonPessoaJuridica->isChecked())
            {
                habilitarCnpj();
            }
        }else
        {
            habilitarCheks();
            ui->lineEditCpf->clear();
            ui->lineEditCnpj->clear();
            ui->textEditResultado->clear();
            desabilitarCpf();
            desabilitarCnpj();
        }
    }catch (QString erro)
    {
        QMessageBox::information(this,"AVISO",erro);
    }
}

void MainWindow::on_checkBoxMostrar_stateChanged(int arg1)
{
    try
    {
        if(arg1)
        {
            if(!ui->radioButtonPessoaFisica->isChecked() && !ui->radioButtonPessoaJuridica->isChecked())throw QString("Escolha sua categoria de pessoa!");
            desabilitarCheksProcurarIden();
            desabilitarCheksProcurarNome();
            desabilitarCheksRemoverNome();
            desabilitarCheksRemoverIden();
            desabilitarCheksAdicionar();
        }else
        {
            habilitarCheks();
            ui->textEditResultado->clear();
        }
    }catch (QString erro)
    {
        QMessageBox::information(this,"AVISO",erro);
    }

}
void MainWindow::on_checkBoxProcurarNome_stateChanged(int arg1)
{
    try
    {
        if(arg1)
        {
            if(!ui->radioButtonPessoaFisica->isChecked() && !ui->radioButtonPessoaJuridica->isChecked())throw QString("Escolha sua categoria de pessoa!");
            desabilitarCheksAdicionar();
            desabilitarCheksRemoverIden();
            desabilitarCheksProcurarIden();
            desabilitarCheksRemoverNome();
            desabilitarCheksMostrar();
            if(ui->radioButtonPessoaFisica->isChecked() || ui->radioButtonPessoaJuridica->isChecked())
            {
                habilitarNome();
            }
        }else
        {
            habilitarCheks();
            ui->lineEditNome->clear();
            ui->textEditResultado->clear();
            desabilitarNome();
        }
    }catch (QString erro)
    {
        QMessageBox::information(this,"AVISO",erro);
    }
}

void MainWindow::on_checkBoxRemoverNome_stateChanged(int arg1)
{
    try
    {
        if(arg1)
        {
            if(!ui->radioButtonPessoaFisica->isChecked() && !ui->radioButtonPessoaJuridica->isChecked())
                throw QString("Escolha sua categoria de pessoa!");
            desabilitarCheksProcurarIden();
            desabilitarCheksProcurarNome();
            desabilitarCheksRemoverIden();
            desabilitarCheksAdicionar();
            desabilitarCheksMostrar();
            if(ui->radioButtonPessoaFisica->isChecked() || ui->radioButtonPessoaJuridica->isChecked())           
                habilitarNome();

        }else
        {
            habilitarCheks();
            ui->lineEditNome->clear();
            ui->textEditResultado->clear();
            desabilitarNome();
        }
    }catch (QString erro)
    {
        QMessageBox::information(this,"AVISO",erro);
    }
}

void MainWindow::on_radioButtonPessoaFisica_clicked()
{
    ui->lineEditNome->clear();
    ui->lineEditEndereco->clear();
    ui->lineEditEmail->clear();
    ui->lineEditRazaoSocial->clear();
    ui->lineEditCnpj->clear();
    ui->lineEditInscricaoEstadual->clear();
    ui->lineEditDia->clear();
    ui->lineEditMes->clear();
    ui->lineEditAno->clear();
    ui->lineEditCpf->clear();
    ui->lineEditEstadoCivil->clear();

    desabilitarNome();
    desabilitarEndereco();
    desabilitarEmail();
    desabilitarRazaoSocial();
    desabilitarCnpj();
    desabilitarInscricaoEstadual();
}

void MainWindow::on_radioButtonPessoaJuridica_clicked()
{
    ui->lineEditNome->clear();
    ui->lineEditEndereco->clear();
    ui->lineEditEmail->clear();
    ui->lineEditRazaoSocial->clear();
    ui->lineEditCnpj->clear();
    ui->lineEditInscricaoEstadual->clear();
    ui->lineEditDia->clear();
    ui->lineEditMes->clear();
    ui->lineEditAno->clear();
    ui->lineEditCpf->clear();
    ui->lineEditEstadoCivil->clear();
    desabilitarNome();
    desabilitarEndereco();
    desabilitarEmail();
    desabilitarData();
    desabilitarCpf();
    desabilitarEstadoCivil();
}
