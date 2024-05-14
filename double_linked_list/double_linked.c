#include <stdio.h>
#include <stdlib.h>
// Define the structure for each node in the doubly linked list
typedef struct Node {
int data;
struct Node* next;
struct Node* prev;
} Node;
// Function to create a new Node
Node* createNode(int data) {
Node* newNode = (Node*)malloc(sizeof(Node));
if (!newNode) {
printf("Error allocating memory!\n");
exit(0);
}
newNode->data = data;
newNode->next = NULL;
newNode->prev = NULL;
return newNode;
}
// Function to print the list
void printList(Node* head) {
Node* temp = head;
printf("Forward: ");
while (temp != NULL) {
printf("%d ", temp->data);
temp = temp->next;
}
printf("\n");
}

int main () {}