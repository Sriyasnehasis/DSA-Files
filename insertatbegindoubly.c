#include <stdio.h>
#include <stdlib.h>

/* 
 * Basic structure of Node 
 */
struct node {
    int data;
    struct node *prev;
    struct node *next;
} *head, *last;

/*
 * Function prototypes 
 */
void createList(int n);
void insertAtBeginning(int data);
void displayListFromFirst();

int main() {
    int n, data;

    head = NULL;
    last = NULL;

    /* Create the doubly linked list */
    printf("Enter the number of nodes you want to create: ");
    scanf("%d", &n);

    createList(n);

    printf("\nData in the list before insertion:\n");
    displayListFromFirst();

    /* Insert a node at the beginning */
    printf("\nEnter data to insert at the beginning of the list: ");
    scanf("%d", &data);

    insertAtBeginning(data);

    printf("\nData in the list after insertion:\n");
    displayListFromFirst();

    return 0;
}

/**
 * Create a doubly linked list of n nodes.
 */
void createList(int n) {
    int i, data;
    struct node *newNode;

    if (n >= 1) {
        head = (struct node *)malloc(sizeof(struct node));

        if (head != NULL) {
            printf("Enter data of 1 node: ");
            scanf("%d", &data);

            head->data = data;
            head->prev = NULL;
            head->next = NULL;

            last = head;

            /* Create the remaining n-1 nodes */
            for (i = 2; i <= n; i++) {
                newNode = (struct node *)malloc(sizeof(struct node));

                if (newNode != NULL) {
                    printf("Enter data of %d node: ", i);
                    scanf("%d", &data);

                    newNode->data = data;
                    newNode->prev = last; // Link new node with the previous node
                    newNode->next = NULL;

                    last->next = newNode; // Link previous node with the new node
                    last = newNode;       // Make new node as last node
                } else {
                    printf("Unable to allocate memory.");
                    break;
                }
            }

            printf("\nDOUBLY LINKED LIST CREATED SUCCESSFULLY\n");
        } else {
            printf("Unable to allocate memory.");
        }
    }
}

/**
 * Insert a node at the beginning of the doubly linked list.
 */
void insertAtBeginning(int data) {
    struct node *newNode;

    newNode = (struct node *)malloc(sizeof(struct node));

    if (newNode != NULL) {
        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = head; // Link the new node to the current head

        if (head != NULL) {
            head->prev = newNode; // Update the previous link of the current head
        }

        head = newNode; // Update head to the new node

        printf("\nNODE INSERTED SUCCESSFULLY AT THE BEGINNING\n");
    } else {
        printf("Unable to allocate memory.");
    }
}

/**
 * Display the content of the list from beginning to end.
 */
void displayListFromFirst() {
    struct node *temp;
    int n = 1;

    if (head == NULL) {
        printf("List is empty.");
    } else {
        temp = head;
        printf("\n\nDATA IN THE LIST:\n");

        while (temp != NULL) {
            printf("DATA of %d node = %d\n", n, temp->data);

            n++;
            temp = temp->next; // Move to the next node
        }
    }
}
