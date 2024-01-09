#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct linked_list{
    int data;
    struct linked_list* next;
};
typedef struct linked_list Node;

Node*front=NULL;
Node*rear=NULL;

void Enqueue(int value){
    Node*newNode=(Node*)malloc(sizeof(Node));
    newNode->data=value;
    newNode->next=NULL;
       
    if(front==NULL&&rear==NULL){
        front=rear=newNode;
    }
    else{
        rear->next=newNode;
        rear=newNode;
    }
}
void Dequeue(){
    Node*ptr=front;
    if(front==NULL&&rear==NULL){
        printf("The queue is empty\n");
    }
    else if(front==rear){
        printf("The dequeued element is:\t%d\n",ptr->data);
        free(ptr);
        front=rear=NULL; 
    }
    else{
        printf("The dequeued element is:\t%d\n",ptr->data);
        front=ptr->next;
        free(ptr);
    }
}

void Display(){
    Node*ptr=front;
    if(ptr==NULL){
        printf("The queue is empty\n");
    }
    else{
        while (ptr!=NULL){
            printf("%d\t",ptr->data);
            ptr=ptr->next;
        }
        printf("\n"); 
    }
}

int main(){
    int choice,value;
  while(1){
       printf("Queue operation\n");
       printf("________________\n");
       printf("1.Enqueue\n");
       printf("2.Dequeue\n");
       printf("3.Display\n");
       printf("4.Exit\n");
       printf("Enter your choice:\t");
       scanf("%d",&choice);
       switch (choice){
       case 1: printf("Enter the value to insert:\t");
               scanf("%d",&value);
               Enqueue(value);
               break;
      case 2: Dequeue();
              break;
      case 3: Display();
              break;
      case 4: exit(0);
              break;
      default:printf("Enter the valid option\n");
              break;
       }
  }
 
    return 0;
}