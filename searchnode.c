#include <stdio.h>
#include <stdlib.h>

/* Structure of a node */
struct node {
    int data;          // Data
    struct node *next; // Address
}*head;

/* Function prototypes */
void createList(int n);
void searchNode(int key);
void displayList();

int main() {
    int n, key;

    /* Create a singly linked list */
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createList(n);

    printf("\nData in the list:\n");
    displayList();

    /* Search for a node */
    printf("\nEnter the value to search: ");
    scanf("%d", &key);

    searchNode(key);

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
    }

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

/* Search for a node in the list */
void searchNode(int key) {
    struct node *temp = head;
    int position = 1;

    /* Traverse the list to search for the node */
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Node with value %d found at position %d.\n", key, position);
            return;
        }
        temp = temp->next;
        position++;
    }

    printf("Node with value %d not found in the list.\n", key);
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
