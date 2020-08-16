#include "LinkedList.hpp"
#include <stdio.h>
#include <stdlib.h>

Node *createList(int size)
{
    Node *head = NULL;
    Node *next = NULL;

    if (size <= 0)
    {
        return head;
    }

    head = initNode();
    next = initNode();

    // Create rest of the nodes
    for (int i = 1; i < size; i++)
    {
        if (i == 1)
        {
            head->next = next;
        }
        else
        {
            Node *aux = initNode();
            next->next = aux;
            next = aux;
        }
    }

    // Last next is not defined
    next->next = NULL;

    return head;
}

Node *initNode()
{
    Node *node = new Node();
    node->data = 0;
    node->next = NULL;
    return node;
}
