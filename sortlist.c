#include <stdio.h>
#include <stdlib.h>

/* Structure of a node */
struct node {
    int data;          // Data
    struct node *next; // Address
}*head;

/* Function prototypes */
void createList(int n);
void sortList();
void displayList();

int main() {
    int n;

    /* Create a singly linked list */
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createList(n);

    printf("\nData in the list before sorting:\n");
    displayList();

    /* Sort the linked list */
    sortList();

    printf("\nData in the list after sorting:\n");
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

/* Sort the linked list */
void sortList() {
    struct node *current, *index;
    int temp;

    /* Check if the list is empty */
    if (head == NULL) {
        printf("List is empty. Cannot sort.\n");
        return;
    }

    current = head;

    /* Traverse through the list */
    while (current != NULL) {
        /* Index points to the next node */
        index = current->next;

        while (index != NULL) {
            /* Swap data if current node is greater than index node */
            if (current->data > index->data) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
        current = current->next;
    }

    printf("LIST SORTED SUCCESSFULLY\n");
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
