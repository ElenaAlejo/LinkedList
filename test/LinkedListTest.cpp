#include <gtest/gtest.h>
#include "../LinkedList.hpp"
#include "LinkedListTest.hpp"

TEST(LinkedListTest, createList){
    const int SIZE = 5;
    Node* head = createList(SIZE);
    validateLinkedList(head, SIZE);
}

TEST(LinkedListTest, createEmptyList){
    const int SIZE = 0;
    Node* head = createList(SIZE);
    ASSERT_TRUE(head == NULL);
}

TEST(LinkedListTest, createSmallerList){ 
    const int SIZE = 1;
    Node* head = createList(SIZE);
    validateLinkedList(head, SIZE);
}

TEST(LinkedListTest, twoNodes){ 
    const int SIZE = 2;
    Node* head = createList(SIZE);
    validateLinkedList(head, SIZE);
}

TEST(LinkedListTest, invalidValue){ 
    const int SIZE = -1;
    Node* head = createList(SIZE);
    ASSERT_TRUE(head == NULL);
}

// This test is for check if upper boulandries are meet.
// As it takes a long time to process I will not run it in Continuous basis.
// TEST(LinkedListTest, MaxNumber){ 
//     Node* head = createList(INT_MAX);
//     validateLinkedList(head, INT_MAX);
// }

TEST(LinkedListTest, CleanMemory){
    const int SIZE = 6;
    Node* head = createList(SIZE);
    validateLinkedList(head, SIZE);
    cleanMemory(head);
    ASSERT_NE(nullptr, head);
}

void validateLinkedList(Node* head, int size){
    int count = 0;

    while(head && count <= size){
        count++;
        checkDefaultValue(head->data);
        head = head->next;
    }

    ASSERT_TRUE(head == NULL);
    ASSERT_EQ(size, count);
}

void checkDefaultValue(int currentData){
    printf("Checking if %d is equals to %d \n", currentData, DEFAULT_VALUE);
        GTEST_ASSERT_EQ(currentData, DEFAULT_VALUE);
}
