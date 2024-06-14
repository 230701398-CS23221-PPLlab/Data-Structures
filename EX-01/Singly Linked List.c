#include <stdio.h> 
#include <stdlib.h> 
  
// Define the structure for a node in the linked list 
struct Node { 
    int data; 
    struct Node* next; 
}; 
  
// Function to create a new node 
struct Node* createNode(int value) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    if (newNode == NULL) { 
        printf("Memory allocation failed\n"); 
        exit(1); 
    } 
    newNode->data = value; 
    newNode->next = NULL; 
    return newNode; 
} 
  
// Function to insert a node at the beginning of the list 
void insertAtBeginning(struct Node** head, int value) { 
    struct Node* newNode = createNode(value); 
    newNode->next = *head; 
    *head = newNode; 
} 
  
// Function to insert a node after a given node 
void insertAfter(struct Node* prevNode, int value) { 
    if (prevNode == NULL) { 
        printf("Previous node cannot be NULL\n"); 
        return; 
    } 
    struct Node* newNode = createNode(value); 
    newNode->next = prevNode->next; 
    prevNode->next = newNode; 
} 
  
// Function to insert a node at the end of the list 
void insertAtEnd(struct Node** head, int value) { 
    struct Node* newNode = createNode(value); 
    if (*head == NULL) { 
        *head = newNode; 
        return; 
    } 
    struct Node* temp = *head; 
    while (temp->next != NULL) { 
        temp = temp->next; 
    } 
    temp->next = newNode; 
} 
  
// Function to find an element in the list 
struct Node* findElement(struct Node* head, int value) { 
    struct Node* current = head; 
    while (current != NULL) { 
        if (current->data == value) { 
            return current; 
        } 
        current = current->next; 
    } 
    return NULL; 
} 
  
// Function to find the next node after a given node 
struct Node* findNext(struct Node* node) { 
    if (node != NULL && node->next != NULL) { 
        return node->next; 
    } 
    return NULL; 
} 
  
// Function to find the previous node before a given node 
struct Node* findPrevious(struct Node* head, struct Node* node) { 
    if (head == node) { 
        return NULL; 
    } 
    struct Node* current = head; 
    while (current != NULL && current->next != node) { 
        current = current->next; 
    } 
    return current; 
} 
  
// Function to check if a node is the last node in the list 
int isLast(struct Node* node) { 
    return (node != NULL && node->next == NULL); 
} 
  
// Function to check if the list is empty 
int isEmpty(struct Node* head) { 
    return (head == NULL); 
} 
  
// Function to delete the first node in the list 
void deleteFirst(struct Node** head) { 
    if (*head == NULL) { 
        printf("List is empty\n"); 
        return; 
    } 
    struct Node* temp = *head; 
    *head = (*head)->next; 
    free(temp); 
} 
  
// Function to delete the node after a given node 
void deleteAfter(struct Node* prevNode) { 
    if (prevNode == NULL || prevNode->next == NULL) { 
        printf("Invalid previous node\n"); 
        return; 
    } 
    struct Node* temp = prevNode->next; 
    prevNode->next = temp->next; 
    free(temp); 
} 
  
// Function to delete the last node in the list 
void deleteLast(struct Node** head) { 
    if (*head == NULL) { 
        printf("List is empty\n"); 
        return; 
    } 
    if ((*head)->next == NULL) { 
        free(*head); 
        *head = NULL; 
        return; 
    } 
    struct Node* secondLast = *head; 
    while (secondLast->next->next != NULL) { 
        secondLast = secondLast->next; 
    } 
    free(secondLast->next); 
    secondLast->next = NULL; 
} 
  
// Function to delete the entire list 
void deleteList(struct Node** head) { 
    struct Node* current = *head; 
    struct Node* next; 
    while (current != NULL) { 
        next = current->next; 
        free(current); 
        current = next; 
    } 
    *head = NULL; 
} 
  
// Function to display the list 
void displayList(struct Node* head) { 
    struct Node* current = head; 
    while (current != NULL) { 
        printf("%d -> ", current->data); 
        current = current->next; 
    } 
    printf("NULL\n"); 
} 
  
int main() { 
    struct Node* head = NULL; 
  
    // Insert nodes 
    insertAtBeginning(&head, 10); 
    insertAtEnd(&head, 20); 
    insertAfter(head, 10, 15); 
  
    // Display the list 
    printf("Initial list:\n"); 
    displayList(head); 
  
    // Find and display an element 
    int searchValue = 15; 
    struct Node* searchResult = findElement(head, searchValue); 
    if (searchResult != NULL) { 
        printf("Element %d found in the list\n", searchValue); 
    } else { 
        printf("Element %d not found in the list\n", searchValue); 
    } 
  
    // Delete nodes 
    deleteFirst(&head); 
    deleteAfter(head); 
    deleteLast(&head); 
  
    // Display the modified list 
    printf("List after deletions:\n"); 
    displayList(head); 
  
    // Delete the entire list 
    deleteList(&head); 
  
    return 0; 
} 
