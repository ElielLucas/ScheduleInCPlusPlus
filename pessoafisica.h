#ifndef PESSOAFISICA_H
#define PESSOAFISICA_H
#include<pessoa.h>
namespace tp2
{
class PessoaFisica: public Pessoa
{
private:
    long long cpf;
    QString data;
    QString estadoCivil;

public:
    PessoaFisica();
    PessoaFisica(QString nome, QString endereco, QString email, long long cpf, int dia, int mes, int ano, QString estadocivil);
    QString getData()const{return data;}
    QString getEstadoCivil()const{return estadoCivil;}
    void setData(int dia, int mes, int ano);
    void setEstadoCivil(QString estadoCivil);

    virtual QString print()const override;
    virtual long long getIdentifica()const override{return cpf;}
    virtual void setIdentifica(long long identifica)override;
};
}
#endif // PESSOAFISICA_H
