#ifndef LIST_H
#define LIST_H
#include "node.h"

class lista
{
public:

    node *head,*last;

    lista();
    int size;
    void addfirst(node*);
    void delete_node(node*);
    void addlast(node*);
    node* getLowestF();
    bool isinList(node*);
    void printNodes();
    void printNodes2();
    node* getNode(int index);

};

#endif // LIST_H
