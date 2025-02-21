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
void deleteFirstNode();
void displayListFromFirst();

int main() {
    int n;

    head = NULL;
    last = NULL;

    /* Create the doubly linked list */
    printf("Enter the number of nodes you want to create: ");
    scanf("%d", &n);

    createList(n);

    printf("\nData in the list before deletion:\n");
    displayListFromFirst();

    /* Delete the first node */
    printf("\nDeleting the first node...\n");
    deleteFirstNode();

    printf("\nData in the list after deletion:\n");
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
 * Delete the first node of the doubly linked list.
 */
void deleteFirstNode() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty. No node to delete.\n");
        return;
    }

    temp = head;
    head = head->next; // Move the head to the next node

    if (head != NULL) {
        head->prev = NULL; // Update the previous pointer of the new head
    } else {
        last = NULL; // If the list becomes empty, update the last pointer
    }

    free(temp); // Free the memory of the old head
    printf("FIRST NODE DELETED SUCCESSFULLY.\n");
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
