#include <stdio.h>
#include <stdlib.h>

/* Structure of a node */
struct node {
    int data;
    struct node *next;
} *head = NULL;

/* Function prototypes */
void createCircularList(int n);
void displayCircularList();
void deleteAtBeginning();
void deleteAtEnd();
void deleteAtPosition(int position);

int main() {
    int n, choice, position;

    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createCircularList(n);

    while (1) {
        printf("\nCircular Linked List Operations:\n");
        printf("1. Display List\n");
        printf("2. Delete at Beginning\n");
        printf("3. Delete at End\n");
        printf("4. Delete at Position\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayCircularList();
                break;
            case 2:
                deleteAtBeginning();
                break;
            case 3:
                deleteAtEnd();
                break;
            case 4:
                printf("Enter the position of the node to delete: ");
                scanf("%d", &position);
                deleteAtPosition(position);
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

/* Create a circular linked list of n nodes */
void createCircularList(int n) {
    struct node *newNode, *temp;
    int data, i;

    if (n <= 0) {
        printf("Invalid number of nodes.\n");
        return;
    }

    head = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data of node 1: ");
    scanf("%d", &data);
    head->data = data;
    head->next = head; // Circular link
    temp = head;

    for (i = 2; i <= n; i++) {
        newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data of node %d: ", i);
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = head; // Circular link
        temp->next = newNode;
        temp = newNode;
    }
}

/* Display the circular linked list */
void displayCircularList() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

/* Delete the first node of the circular linked list */
void deleteAtBeginning() {
    struct node *temp, *last;

    if (head == NULL) {
        printf("List is empty. No node to delete.\n");
        return;
    }

    temp = head;

    if (head->next == head) { // Only one node
        head = NULL;
    } else {
        last = head;
        while (last->next != head) {
            last = last->next;
        }
        last->next = head->next;
        head = head->next;
    }

    free(temp);
    printf("Node deleted from the beginning.\n");
}

/* Delete the last node of the circular linked list */
void deleteAtEnd() {
    struct node *temp, *prev;

    if (head == NULL) {
        printf("List is empty. No node to delete.\n");
        return;
    }

    temp = head;

    if (head->next == head) { // Only one node
        head = NULL;
    } else {
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
    }

    free(temp);
    printf("Node deleted from the end.\n");
}

/* Delete a node at a specific position in the circular linked list */
void deleteAtPosition(int position) {
    struct node *temp, *prev;
    int i;

    if (head == NULL) {
        printf("List is empty. No node to delete.\n");
        return;
    }

    if (position == 1) {
        deleteAtBeginning();
        return;
    }

    temp = head;

    for (i = 1; i < position && temp->next != head; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp->next == head && i != position) {
        printf("Invalid position! List has fewer nodes.\n");
    } else {
        prev->next = temp->next;
        free(temp);
        printf("Node deleted from position %d.\n", position);
    }
}
