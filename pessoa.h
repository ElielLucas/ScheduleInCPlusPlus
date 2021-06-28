#ifndef PESSOA_H
#define PESSOA_H
#include<QString>
#include<string.h>
namespace tp2
{
class Pessoa
{
private:

    QString nome;
    QString endereco;
    QString email;
public:
    Pessoa();
    Pessoa(QString nome, QString endereco,QString email);
    QString getNome()const{return nome;}
    QString getEndereco()const{return endereco;}
    QString getEmail()const{return email;}
    void setNome(QString nome);
    void setEndereco(QString endereco);
    void setEmail(QString email);


    virtual long long getIdentifica()const=0;
    virtual void setIdentifica(long long identifica)=0;
    virtual QString print()const=0;
};
}
#endif // PESSOA_H
