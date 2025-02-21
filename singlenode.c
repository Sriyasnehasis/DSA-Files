#include<stdio.h>
#include<stdlib.h>

//datatype of node
struct Node{
       int data;
       struct Node*next;};

       int main(){
           struct Node*head=NULL;
           head = malloc(sizeof(struct Node));

           head->data = 45;
           head->next = NULL;

           printf("The node is %d" , head ->data);

           return 0;

 }
