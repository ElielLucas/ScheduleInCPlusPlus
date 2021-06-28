#ifndef PESSOAJURIDICA_H
#define PESSOAJURIDICA_H
#include<pessoa.h>
namespace tp2
{
class PessoaJuridica : public Pessoa
{
private:
    long long cnpj;
    long long inscricaoEstadual;
    QString razaoSocial;

public:
    PessoaJuridica();
    PessoaJuridica(QString nome, QString endereco,QString email, long long cnpj, long long incricaoEstadual, QString razaoSocial);
    long long getInscricaoEstadual()const{return inscricaoEstadual;}
    QString getRazaoSocial()const{return razaoSocial;}
    void setInscricaoEstadual(long long inscricaoEstadual);
    void setRazaoSocial(QString razaoSocial);

    virtual QString print()const override;
    virtual long long getIdentifica()const override{return cnpj;}
    virtual void setIdentifica(long long identifica)override;
};
}
#endif // PESSOAJURIDICA_H
