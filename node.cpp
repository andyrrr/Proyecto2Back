#include "node.h"

node::node(int i, int x, int y)
{
    this->id = i;
    this->x_coord = x;
    this->y_coord = y;
    this->available = true;
    this->diagonal = false;
    this->parent = nullptr;
    this->next = nullptr;
    this->G = 0;
    this->H = 0;
}

int node::getF()
{
    return G+H;
}

void node::ManhattanDistance(node* end)
{
    int count = 0;

    if(this->x_coord <= end->x_coord and this->y_coord <= end->y_coord)//x mayor, y mayor
    {
        for(int i=this->x_coord ; i!=end->x_coord; i++)
        {
            count++;
        }
        for (int j=this->y_coord; j!=end->y_coord; j++)
        {
            count++;
        }
    }
    if(this->x_coord >= end->x_coord and this->y_coord >= end->y_coord)//x menor, y menor
    {
        for(int i=this->x_coord ; i!=end->x_coord; i--)
        {
            count++;
        }
        for (int j=this->y_coord; j!=end->y_coord; j--)
        {
            count++;
        }
    }
    if(this->x_coord <= end->x_coord and this->y_coord >= end->y_coord) //x mayor, y menor
    {
        for(int i=this->x_coord ; i!=end->x_coord; i++)
        {
            count++;
        }
        for (int j=this->y_coord; j!=end->y_coord; j--)
        {
            count++;
        }
    }
    if(this->x_coord >= end->x_coord and this->y_coord <= end->y_coord) //x menor, y mayor
    {
        for(int i=this->x_coord ; i!=end->x_coord; i--)
        {
            count++;
        }
        for (int j=this->y_coord; j!=end->y_coord; j++)
        {
            count++;
        }
    }

    this->H = count*10;
    //std::cout<<"Se ha calculado H con éxito para el nodo " << this->id << " H= " << this->H <<std::endl;
}

void node::setG()
{
    if(this->diagonal==true)//se calcula G
    {
        this->G = parent->G+14;
    }else{
        this->G = parent->G+10;
    }
}
