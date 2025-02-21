#include <stdio.h>
#include <stdlib.h>

/* Structure of a node */
struct node {
    int data;          // Data
    struct node *next; // Address
}*head;

/* Function prototypes */
void createList(int n);
void deleteNodeAtPosition(int position);
void displayList();

int main() {
    int n, position;

    /* Create a singly linked list */
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createList(n);

    printf("\nData in the list \n");
    displayList();

    /* Delete a node at any position */
    printf("\nEnter the position of the node to delete: ");
    scanf("%d", &position);

    deleteNodeAtPosition(position);

    printf("\nData in the list after deletion\n");
    displayList();

    return 0;
}

/* Create a list of n nodes */
void createList(int n) {
    struct node *newNode, *temp;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));

    if (head == NULL) {
        printf("Unable to allocate memory.\n");
        return;
    }else{

    printf("Enter the data of node 1: ");
    scanf("%d", &data);

    head->data = data; // Link the data field with data
    head->next = NULL; // Link the address field to NULL

    temp = head;

    /* Create n-1 nodes and link them */
    for (i = 2; i <= n; i++) {
        newNode = (struct node *)malloc(sizeof(struct node));

        if (newNode == NULL) {
            printf("Unable to allocate memory.\n");
            break;
        } else {
            printf("Enter the data of node %d: ", i);
            scanf("%d", &data);

            newNode->data = data; // Link the data field of newNode with data
            newNode->next = NULL; // Link the address field of newNode with NULL

            temp->next = newNode; // Link previous node to the newNode
            temp = temp->next;
        }
    }

    printf("SINGLY LINKED LIST CREATED SUCCESSFULLY\n");
  }
}

/* Delete a node at any position */
void deleteNodeAtPosition(int position) {
    struct node *temp, *prev;
    int i;

    /* If the list is empty */
    if (head == NULL) {
        printf("List is empty. Cannot delete node.\n");
        return;
    }

    temp = head;

    /* If the node to be deleted is the first node */
    if (position == 1) {
        head = head->next; // Move head to the next node
        free(temp);        // Free memory of the old head
        printf("NODE DELETED SUCCESSFULLY\n");
        return;
    }else{

    /* Traverse to the node before the node to be deleted */
    for (i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    /* If the position is invalid */
    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position! List has fewer nodes.\n");
    } else {
        prev = temp->next;        // Node to be deleted
        temp->next = prev->next;  // Link the previous node to the next node
        free(prev);               // Free memory of the node to be deleted
        printf("NODE DELETED SUCCESSFULLY\n");
    }
}
}

/* Display the entire list */
void displayList() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        temp = head;
        while (temp != NULL) {
            printf("Data = %d\n", temp->data); // Print data of current node
            temp = temp->next;                 // Move to next node
        }
    }
}
