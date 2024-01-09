#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct linked_list{
    int data;
    struct linked_list*next;
};
typedef struct linked_list Node;
Node*start =NULL;

void insertAtBegining(int value){
    if(start==NULL){
        Node*newNode=(Node*)malloc(sizeof(Node));
        newNode->data=value;
        newNode->next=NULL;
        start=newNode;
    }
    else{
        Node*newNode=(Node*)malloc(sizeof(Node));
        newNode->data=value;
        newNode->next=start;
        start=newNode;
    }
}



void deleteFromBegining(){
    Node*ptr=start;
    if(ptr==NULL){
        printf("The linked list is empty\n");
    }
    else if(ptr->next==NULL){
       free(ptr);
       start=NULL;  
    }
    else{
        start=ptr->next;
        free(ptr);
    }
}

void display(){
    Node*ptr=start;
    if(ptr==NULL){
        printf("The linked list is empty\n");
        return;
    }
    while (ptr!=NULL){
       printf("%d\t",ptr->data);
       ptr=ptr->next;
    }
    printf("\n");
}

void peek(){
    if(start==NULL){
        printf("The linked list is empty\n");
    }
    else{
         printf("The value of peek is:\t%d\n",start->data);
    }
}

int main(){
  int choice,value;
  while(1){
       printf("Stack operation\n");
       printf("________________\n");
       printf("1.Enqueue\n");
       printf("2.Dequeue\n");
       printf("3.Display\n");
       printf("4.Peek\n");
       printf("5.Exit\n");
       printf("Enter your choice:\t");
       scanf("%d",&choice);
       switch (choice){
       case 1: printf("Enter the value to insert:\t");
               scanf("%d",&value);
               insertAtBegining(value);
               break;
      case 2: deleteFromBegining();
              break;
      case 3: display();
              break;
      case 4: peek();
              break;
      case 5: exit(0);
       }
  }
 
    return 0;
}