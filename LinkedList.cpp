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

    if (size > 0)
    {
        head = new Node();
        head->data = 0;
        if (size == 1)
        {
            head->next = NULL;
            return head;
        }
        else
        {
            // Creating second node
            next = new Node();
            next->data = 0;
            head->next = next;
        }
    }

    // Create rest of the nodes
    for (int i = 2; i < size; i++)
    {
        Node *aux = new Node();
        aux->data = 0;
        next->next = aux;
        next = aux;
    }

    // Last next is not defined
    next->next = NULL;

    return head;
}
