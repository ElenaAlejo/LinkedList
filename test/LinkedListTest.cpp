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

// This test is for check if upper boulandries are meet, but due it takes a long time to process I will not run it in Continuous basis.
// TEST(LinkedListTest, MaxNumber){ 
//     Node* head = createList(INT_MAX);
//     validateLinkedList(head, INT_MAX);
// }

void validateLinkedList(Node* head, int size){
    for(int i = 0; i < size; i++ ){
        int currentData = head->data;
        printf("Checking if %d is equals to %d \n", currentData, DEFAULT_VALUE);
        GTEST_ASSERT_EQ( currentData, DEFAULT_VALUE);
        head = head->next;
    }
    ASSERT_TRUE(head == NULL);
}
