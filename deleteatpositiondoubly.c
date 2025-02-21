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
void deleteNodeAtPosition(int position);
void displayListFromFirst();

int main() {
    int n, position;

    head = NULL;
    last = NULL;

    /* Create the doubly linked list */
    printf("Enter the number of nodes you want to create: ");
    scanf("%d", &n);

    createList(n);

    printf("\nData in the list before deletion:\n");
    displayListFromFirst();

    /* Delete a node at a specific position */
    printf("\nEnter the position of the node to delete: ");
    scanf("%d", &position);

    deleteNodeAtPosition(position);

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
 * Delete a node at a specific position in the doubly linked list.
 */
void deleteNodeAtPosition(int position) {
    struct node *temp;
    int i;

    if (head == NULL) {
        printf("List is empty. No node to delete.\n");
        return;
    }

    /* If the position is the first node */
    if (position == 1) {
        temp = head;
        head = head->next; // Move the head to the next node

        if (head != NULL) {
            head->prev = NULL; // Update the previous pointer of the new head
        } else {
            last = NULL; // If the list becomes empty, update the last pointer
        }

        free(temp); // Free memory of the old head
        printf("NODE DELETED SUCCESSFULLY FROM POSITION 1.\n");
        return;
    }

    temp = head;

    /* Traverse to the node at the given position */
    for (i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }

    /* If position is invalid */
    if (temp == NULL) {
        printf("Invalid position! List has fewer nodes.\n");
        return;
    }

    /* If the node to be deleted is the last node */
    if (temp == last) {
        last = last->prev; // Move last pointer to the previous node
        last->next = NULL;
    } else {
        /* Update links of the previous and next nodes */
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    free(temp); // Free the memory of the deleted node
    printf("NODE DELETED SUCCESSFULLY FROM POSITION %d.\n", position);
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
