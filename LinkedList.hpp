#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
struct Node
{
    int data;
    struct Node *next;
};

Node *createList(int size);

Node *initNode();

void cleanMemory(Node *head);

#endif /* LINKED_LIST_HPP */