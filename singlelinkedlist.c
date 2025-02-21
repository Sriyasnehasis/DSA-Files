#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next;
};
int main(){
    struct Node*Node1 = NULL;
    Node1 = malloc(sizeof(struct Node));

    Node1->data = 17;
    Node1->next = NULL;

    struct Node*Node2 = NULL;
    Node2 = malloc(sizeof(struct Node));

    Node2->data = 89;
    Node2->next = NULL;

    Node1->next = Node2;

    printf("Node1 data: %d\n",Node1->data);
    printf("Node2 data: %d\n", Node1->next->data);

    return 0;


}