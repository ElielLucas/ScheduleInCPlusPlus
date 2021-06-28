#include "node.h"
namespace tp2
{
Node::Node():
    D(0)
{
}
Node* Node::montaNode(Pessoa *dat)
{
    Node* P=new Node;
    if(P)
    {
        P->D=dat;
    }
    return P;
}
Pessoa* Node::desmontaNode(Node *P)
{
    Pessoa *x=P->D;
    delete P;
    return x;
}
}
