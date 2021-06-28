#include "pessoajuridica.h"
namespace tp2
{
PessoaJuridica::PessoaJuridica():
    cnpj(0),
    razaoSocial(""),
    inscricaoEstadual(0)
{

}
PessoaJuridica::PessoaJuridica(QString nome, QString endereco,QString email, long long cnpj, long long inscricaoEstadual, QString razaoSocial):
    Pessoa(nome, endereco, email)
{
    setIdentifica(cnpj);
    setInscricaoEstadual(inscricaoEstadual);
    setRazaoSocial(razaoSocial);
}

void PessoaJuridica::setIdentifica(long long identifica)
{  
    QString CNPJ=QString::number(identifica);
    QString aux;
    // Elimina CPFs invalidos conhecidos
    if (CNPJ.length() != 14   ||
        CNPJ == "00000000000" ||
        CNPJ == "11111111111" ||
        CNPJ == "22222222222" ||
        CNPJ == "33333333333" ||
        CNPJ == "44444444444" ||
        CNPJ == "55555555555" ||
        CNPJ == "66666666666" ||
        CNPJ == "77777777777" ||
        CNPJ == "88888888888" ||
        CNPJ == "99999999999" ||
        CNPJ == "")
        throw QString("CNPJ inválido!");

///////////////////////////////Digito1//////////////////////////////////////////
    int tamanho = CNPJ.length() - 2;
    int soma = 0;
    int pos = tamanho - 7;
    for (int i = tamanho; i >= 1; i--)
    {
      aux=CNPJ[tamanho - i];
      soma += aux.toInt() * pos--;
      if (pos < 2)pos = 9;
    }
    aux=CNPJ[tamanho];
    int resultado = soma % 11 < 2 ? 0 : 11 - soma % 11;
    if (resultado != aux.toInt()) throw QString("CNPJ inválido!");

///////////////////////////////Digito2//////////////////////////////////////////
    tamanho = tamanho + 1;
    soma = 0;
    pos = tamanho - 7;
    for (int i = tamanho; i >= 1; i--)
    {
      aux=CNPJ[tamanho - i];
      soma += aux.toInt() * pos--;
      if (pos < 2)pos = 9;
    }
    aux=CNPJ[tamanho];
    resultado = soma % 11 < 2 ? 0 : 11 - soma % 11;
    if (resultado != aux.toInt()) throw QString("CNPJ inválido!");

    cnpj=identifica;
}
void PessoaJuridica::setInscricaoEstadual(long long inscricaoEstadual)
{
    if(inscricaoEstadual<=0)throw QString("Escreva o número de Inscrição Estadual.");

    this->inscricaoEstadual=inscricaoEstadual;
}
void PessoaJuridica::setRazaoSocial(QString razaoSocial)
{
    if(razaoSocial=="")throw QString ("Escreva uma razão social!");
    this->razaoSocial=razaoSocial;
}

QString PessoaJuridica::print()const
{
    QString saida;
    saida+="\nNome: "+getNome();
    saida+="\nEndereço: "+getEndereco();
    saida+="\nEmail: "+getEmail();
    saida+="\nCNPJ: "+QString::number(getIdentifica());
    saida+="\nInscrição Estadual: "+QString::number(getInscricaoEstadual());
    saida+="\nRazão Social: "+getRazaoSocial();
    return saida;
}

}
