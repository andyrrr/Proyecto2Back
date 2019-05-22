#include "list.h"

#include "iostream"

lista::lista()
{
    size = 0;
    head = nullptr;
    last = nullptr;

}

void lista::addfirst(node *n)
{
    if(this->head==nullptr)
    {
        this->head = n;
        n->next = nullptr;
    }else{
        n->next = this->head;
        this->head = n;
    }
    this->size++;
}


void lista::addlast(node *n)
{
    if (!head)
    {
        head = n;
        n->next = nullptr;
        this->size++;
        return;
    }else{

        node *temp = head;
        while(temp->next != nullptr)
        {
         temp = temp->next;
        }
        temp->next = n;
        n->next = nullptr;
    }
    this->size++;

}

void lista::delete_node(node *n)
{
    node *temp;
    if(head == nullptr)
    {
        return;
    }
    else if(n == head)
    {
        this->head = head->next;
    }
    else
    {
        temp = head;
        while(temp->next->id != n->id)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
    }
    this->size--;
}


node* lista::getLowestF()
{
    node* temp = this->head;
    node* lowestF = this->head;
    while(temp != nullptr)
    {
        if(temp->getF()<lowestF->getF())
        {
         lowestF = temp;

        }
        temp =temp->next;
    }
    return lowestF;
}


bool lista::isinList(node *n)
{
    node* temp = this->head;
    while(temp != nullptr)
    {
        if(temp->id==n->id)
        {

            return true;
        }
        temp = temp->next;
    }

    return false;
}

node* lista::getNode(int i){
    int lugar=0;
    node *actual = head;
    while (lugar<i){
        actual = actual->next;
        lugar++;
    }
    return actual;
}

void lista::printNodes()
{
    node *temp = head;
    int i = 1;
    while(temp != nullptr)
    {
        std::cout << i << ") ID: " << temp->id << " (" << temp->x_coord<<","<<temp->y_coord<<")"<<std::endl;
        temp = temp->next;
        i++;
    }
    std::cout << "El tamaño es " << this->size << std::endl;
}

void lista::printNodes2()
{
    node *temp = head;
    int i = 1;
    while(temp != nullptr)
    {
        std::cout << i << ") ID: " << temp->id << " (" << temp->x_coord<<","<<temp->y_coord<<")"<<"F: "<<temp->getF()<< std::endl;
        temp = temp->next;
        i++;
    }
    std::cout << "El tamaño es " << this->size << std::endl;
}
