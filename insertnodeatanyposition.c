#include <stdio.h>
#include <stdlib.h>

/* Structure of a node */
struct node {
    int data;          // Data 
    struct node *next; // Address 
}*head;

/* Function prototypes */
void createList(int n);
void insertNodeAtPosition(int data, int position);
void displayList();

int main() {
    int n, data, position;

    /* Create a singly linked list */
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createList(n);

    printf("\nData in the list \n");
    displayList();

    /* Insert data at any position */
    printf("\nEnter data to insert: ");
    scanf("%d", &data);
    printf("Enter the position to insert the new node: ");
    scanf("%d", &position);

    insertNodeAtPosition(data, position);

    printf("\nData in the list after insertion\n");
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

/* Insert a node at any position */
void insertNodeAtPosition(int data, int position) {
    struct node *newNode, *temp;
    int i;

    newNode = (struct node *)malloc(sizeof(struct node));

    if (newNode == NULL) {
        printf("Unable to allocate memory.\n");
    } else {
        newNode->data = data; // Link data to new node
        newNode->next = NULL;

        /* Insert at the beginning */
        if (position == 1) {
            newNode->next = head;
            head = newNode;
        } else {
            temp = head;

            /* Traverse to the node before the insertion point */
            for (i = 1; i < position - 1 && temp != NULL; i++) {
                temp = temp->next;
            }

            /* If the position is invalid */
            if (temp == NULL) {
                printf("Invalid position! List has fewer nodes.\n");
            } else {
                newNode->next = temp->next; // Link the new node to the next node
                temp->next = newNode;      // Link the previous node to the new node
            }
        }

        printf("NODE INSERTED SUCCESSFULLY\n");
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
