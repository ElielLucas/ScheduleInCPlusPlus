#include "agenda.h"
namespace tp2
{
Agenda::Agenda()
{
    head = 0;
    IT = 0;
}

bool Agenda::searchIdentifica(long long iden, QString* dat)
{
    IT = head;
    while(IT && (IT->D)->getIdentifica()!=iden)
    {
        IT = IT -> next;
    }
    if (IT)
    {
        *dat+= (IT -> D)->print();
        return true;
    }
    return false;
}

bool Agenda::searchNome(QString nome, QString* dat)
{
    for(IT = head;IT && (IT -> D)->getNome() != nome; IT = IT -> next);

    if (!IT) return false;

    *dat += (IT -> D)->print();
    return true;
}
bool Agenda::removeNome(QString nome, QString* dat)
{
    for(IT = head;IT && (IT -> D)->getNome() != nome; IT = IT -> next);

    if (!IT) return false;

    if(IT->prev) (IT->prev)->next = IT->next;
    else head = IT->next;

    if(IT->next)(IT->next)->prev = IT->prev;

    *dat=desmontaNode(IT)->print();
     IT=head;
     return true;
}
bool Agenda::removeIdentificacao(long long iden, QString* dat)
{
    for(IT = head; IT && (IT->D)->getIdentifica() != iden; IT = IT->next);

    if (!IT) return false;

    if(IT->prev) (IT->prev)->next = IT->next;

    else head = IT->next;

    if(IT->next)(IT->next)->prev = IT->prev;

    *dat += desmontaNode(IT)->print();
    IT=head;
    return true;
}

bool Agenda::pushPessoa(Pessoa* dat)
{
        Node* P = montaNode(dat);
        if (!P)  return false;

        P->next=head;
        P->prev=0;
        if(head) (P->next)->prev=P;

        head=P;
        IT=P;
        return true;
}

bool Agenda::ordenaIden()
{
    if(!head || !head->next)
        throw QString("Não é possível ordenar uma agenda com um ou nenhum elemento!");

    Pessoa* k;
    Node* P, *P2;

    for(P=head; P ; P=P->next)
    {
       for(P2=head; P2 ;P2=P2->next)
       {
           if((P->D)->getIdentifica() < (P2->D)->getIdentifica())
           {
                k=P->D;
                (P->D)=P2->D;
                P2->D=k;
           }
       }
    }
   return true;
}
bool Agenda::ordenaNomes()
{
    if(!head || !head->next)
        throw QString("Não é possível ordenar uma agenda com um ou nenhum elemento!");

    Pessoa* k;
    Node* P, *P2;
    for(P=head; P ; P=P->next)
    {
        for(P2=head; P2 ;P2=P2->next)
        {
            if(((P->D)->getNome() < (P2->D)->getNome()))
            {
                 k=P->D;
                 (P->D)=P2->D;
                 P2->D=k;
            }
        }
    }
   return true;
}
bool Agenda::printAll(QString *saida)
{
    IT=head;
    if(!IT)return false;
    while(IT)
    {
        *saida+=(IT->D)->print();
        *saida+="\n\n***********************************************";
        IT=IT->next;
    }
    IT=head;
    return true;
}




}
