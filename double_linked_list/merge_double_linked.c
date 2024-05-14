#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to concatenate two doubly linked lists
struct Node* concatenateLists(struct Node* list1, struct Node* list2) {
    if (list1 == NULL) {
        return list2;
    }
    struct Node* temp = list1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = list2;
    if (list2 != NULL) {
        list2->prev = temp;
    }
    return list1;
}

// Function to display a doubly linked list
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* list1 = createNode(10);
    list1->next = createNode(20);
    list1->next->prev = list1;
    list1->next->next = createNode(30);
    list1->next->next->prev = list1->next;

    struct Node* list2 = createNode(40);
    list2->next = createNode(50);
    list2->next->prev = list2;

    printf("List 1: ");
    display(list1);

    printf("List 2: ");
    display(list2);

    struct Node* mergedList = concatenateLists(list1, list2);
    printf("Merged list: ");
    display(mergedList);

    return 0;
}
