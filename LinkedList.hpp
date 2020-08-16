#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
struct Node
{
    int data;
    struct Node *next;
};

Node* createList(int size); 

Node* initNode();

#endif /* LINKED_LIST_HPP */