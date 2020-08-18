#include "LinkedList.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

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
    if (head && next)
    {
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
                if (aux)
                {
                    next->next = aux;
                    next = aux;
                }
                else
                {
                    // As we couldn´t allocate, clean the memory
                    cleanMemory(head);
                }
            }
        }

        // Last next is not defined
        next->next = NULL;
    }
    else
    {
        // As we couldn´t allocate, clean the memory
        cleanMemory(head);
    }

    return head;
}

Node *initNode()
{
    Node *node = NULL;
    try
    {
        node = new Node();
        node->data = 0;
        node->next = NULL;
    }
    catch (std::bad_alloc &ba)
    {
        std::cerr << "Could not allocate memory: " << ba.what() << '\n';
    }
    
    return node;
}

void cleanMemory(Node *head)
{

    while (head)
    {
        Node *aux = head->next;
        delete head;
        head = aux;
    }
}
