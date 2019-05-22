#ifndef NODE_H
#define NODE_H
#include "iostream"

class node
{
public:

    int id;
    int x_coord;
    int y_coord;
    bool available;
    bool diagonal;
    node *parent;
    node *next;
    int G;
    int H;



    node(int id,int x,int y);
    void ManhattanDistance(node* end);
    void setG();
    int getF();



};
#endif // NODE_H
