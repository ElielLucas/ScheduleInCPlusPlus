#ifndef NODE_H
#define NODE_H
#include<pessoa.h>
namespace tp2
{
class Node
{
    public:
    Pessoa *D;
    Node *next;
    Node *prev;

    Node();
    static Node*  montaNode(Pessoa *dat);
    static Pessoa* desmontaNode(Node *P);

};
}

#endif // NODE_H
