#ifndef AGENDA_H
#define AGENDA_H
#include<node.h>
namespace tp2
{
class Agenda: public Node
{
private:
    Node* head;
    Node* IT;
public:
    Agenda();
    bool pushPessoa(Pessoa* dat);
    bool searchIdentifica(long long iden, QString* dat);
    bool searchNome(QString nome, QString* dat);
    bool removeIdentificacao(long long iden, QString* dat);
    bool removeNome(QString nome, QString* dat);
    bool printAll(QString *saida);
    bool ordenaIden();
    bool ordenaNomes();
};
}

#endif // AGENDA_H
