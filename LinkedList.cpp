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

    try
    {
        head = initNode();
        next = head;
        // Create rest of the nodes
        for (int i = 0; i < size - 1; i++)
        {
            Node *aux = initNode();
            next->next = aux;
            next = aux;
        }

        // Last next is not defined
        next->next = NULL;
        next->data = 0;
    }
    catch (std::bad_alloc)
    {
        cleanMemory(head);
        throw std::runtime_error(std::string("Error when trying to allocate memory"));
    }

    return head;
}

Node *initNode()
{
    Node *node = new Node();
    node->data = 0;
    node->next = NULL;

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
