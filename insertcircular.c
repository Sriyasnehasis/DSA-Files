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
void insertAtBeginning(int data);
void insertAtEnd(int data);
void insertAtPosition(int data, int position);

int main() {
    int n, choice, data, position;

    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createCircularList(n);

    while (1) {
        printf("\nCircular Linked List Operations:\n");
        printf("1. Display List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Position\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayCircularList();
                break;
            case 2:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 3:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 4:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert the node: ");
                scanf("%d", &position);
                insertAtPosition(data, position);
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

/* Insert a node at the beginning of the circular linked list */
void insertAtBeginning(int data) {
    struct node *newNode, *temp;

    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = head;

    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
    } else {
        temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode; // Update the last node's next
        head = newNode;       // Update the head
    }

    printf("Node inserted at the beginning.\n");
}

/* Insert a node at the end of the circular linked list */
void insertAtEnd(int data) {
    struct node *newNode, *temp;

    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = head;

    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
    } else {
        temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printf("Node inserted at the end.\n");
}

/* Insert a node at a specific position in the circular linked list */
void insertAtPosition(int data, int position) {
    struct node *newNode, *temp;
    int i;

    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;

    if (position == 1) {
        insertAtBeginning(data);
        return;
    }

    temp = head;
    for (i = 1; i < position - 1 && temp->next != head; i++) {
        temp = temp->next;
    }

    if (temp->next == head && i != position - 1) {
        printf("Invalid position! List has fewer nodes.\n");
        free(newNode);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Node inserted at position %d.\n", position);
    }
}
