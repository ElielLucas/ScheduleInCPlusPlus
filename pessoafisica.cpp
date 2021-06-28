#include "pessoafisica.h"
namespace tp2
{
PessoaFisica::PessoaFisica():
    cpf(0),
    data(""),
    estadoCivil("")
{

}
PessoaFisica::PessoaFisica(QString nome, QString endereco, QString email, long long cpf, int dia, int mes, int ano, QString estadocivil):
   Pessoa(nome, endereco, email)
{
    setIdentifica(cpf);
    setData(dia,mes,ano);
    setEstadoCivil(estadocivil);
}

void PessoaFisica::setIdentifica(long long identifica)
{
    QString CPF=QString::number(identifica);
    QString aux;
    // Elimina CPFs invalidos conhecidos
    if (CPF.length() != 11   ||
        CPF == "00000000000" ||
        CPF == "11111111111" ||
        CPF == "22222222222" ||
        CPF == "33333333333" ||
        CPF == "44444444444" ||
        CPF == "55555555555" ||
        CPF == "66666666666" ||
        CPF == "77777777777" ||
        CPF == "88888888888" ||
        CPF == "99999999999" ||
        CPF == "")
        throw QString("CPF inválido!");

    int digito1=0;
    int digito2=0;
    /////////////////////Digito1//////////////////////////////////
    for(int i = 0, j = 10; i < CPF.length()-2; i++, j--)
    {
        aux=CPF[i];
        digito1+=aux.toInt()*j;
    }
    digito1%=11;
    if(digito1 < 2) digito1 = 0;
    else digito1 = 11 - digito1%11;

    aux=CPF[9];
    if((aux.toInt()) != digito1) throw QString("CPF inválido!");

    //////////////////////Digito2/////////////////////////////////
    for(int i = 0, j = 11; i < CPF.length()-1; i++, j--)
    {
        aux=CPF[i];
        digito2+=aux.toInt()*j;
    }
    digito2%=11;
    if(digito2 < 2) digito2 = 0;
    else digito2 = 11 - digito2%11;

    aux=CPF[10];
    if((aux.toInt()) != digito2) throw QString("CPF inválido!");

    cpf=identifica;
 }

void PessoaFisica::setEstadoCivil(QString estadoCivil)
{
    QString verifica=estadoCivil.toLower();
    QString aux;
    if(verifica!="casado" && verifica!="solteiro" && verifica!="divorciado" && verifica!="viuvo")throw QString("Estado civil inválido!");
    aux=verifica[0].toUpper();
    verifica[0]=aux[0];
    this->estadoCivil=verifica;
}

void PessoaFisica::setData(int dia, int mes, int ano)
{
    if(dia==0 || mes==0 || ano==0)
        throw QString("Data inválida!");
    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30)
        throw QString("Data inválida!");
    if ((ano % 4) != 0 && mes == 2 && dia > 28)
        throw QString("Data inválida!");
    if ((ano%4) == 0 && mes == 2 && dia > 29)
        throw QString("Data inválida!");

    QString data=QString::number(dia) + " / " +
                 QString::number(mes) + " / " +
                 QString::number(ano);
    this->data=data;
}

QString PessoaFisica::print()const
{
    QString saida;
    saida+="\nNome: "+getNome();
    saida+="\nEndereço: "+getEndereco();
    saida+="\nEmail: "+getEmail();
    saida+="\nCPF: "+QString::number(getIdentifica());
    saida+="\nData de nascimento: "+getData();
    saida+="\nEstado Civil: "+getEstadoCivil();
    return saida;
}




}
