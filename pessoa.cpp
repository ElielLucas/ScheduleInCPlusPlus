#include "pessoa.h"
namespace tp2
{
Pessoa::Pessoa():
    nome(""),
    endereco(""),
    email("")
{

}
Pessoa::Pessoa(QString nome, QString endereco,QString email)
{
    setNome(nome);
    setEndereco(endereco);
    setEmail(email);
}

void Pessoa::setNome(QString nome)
{
    if(nome=="")throw QString("Escreva um nome!");
    this->nome=nome;
}

void Pessoa::setEmail(QString email)
{
    QString emaill=email;
    int arroba=0,ponto=0;
    int cntAArro=0, cntDArro=0, com=0;
    int tam=email.length();

    for (int i = 0; i < tam; i++)
    {
       if(arroba==0)cntAArro++;

       if(email[i] == '@')
       {
           if(cntAArro<8)throw QString("O email deve ter no minimo:\n-7 caracteres antes do @\n-5 caracteres depois do @\n-deve ter @\n-deve ter .com");
           arroba++;
           if(arroba>1)throw QString("O email deve ter no minimo:\n-7 caracteres antes do @\n-5 caracteres depois do @\n-deve ter @\n-deve ter .com");
       }

       if(arroba==1)cntDArro++;

       if(email[i] == '.')
       {
           if(cntDArro<7)throw QString("O email deve ter no minimo:\n-7 caracteres antes do @\n-5 caracteres depois do @\n-deve ter @\n-deve ter .com");
           ponto++;
           if(ponto>1)throw QString("O email deve ter no minimo:\n-7 caracteres antes do @\n-5 caracteres depois do @\n-deve ter @\n-deve ter .com");
       }

       if(ponto==1 && (email[i]=='c' && email[i+1]=='o' && email[i+2]=='m'))
       {
           com=1;
           break;
       }

    }
    if(ponto!= 1 || arroba!=1 || com!=1)throw QString("O email deve ter no minimo:\n-7 caracteres antes do @\n-5 caracteres depois do @\n-deve ter @\n-deve ter .com");

    this->email=email;
}

void Pessoa::setEndereco(QString endereco)
{
    if(endereco=="")throw QString("Escreva algum endereço!");
    this->endereco=endereco;
}

}
