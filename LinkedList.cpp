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
    next = head;
    if (head)
    {
        // Create rest of the nodes
        for (int i = 0; i < size - 1; i++)
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
                throw std::runtime_error(std::string("Error when trying to allocate memory"));
            }
        }

        // Last next is not defined
        next->next = NULL;
        next->data = 0;
    }
    else
    {
        // As we couldn´t allocate, clean the memory
        cleanMemory(head);
        throw std::runtime_error(std::string("Error when trying to allocate memory"));
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
