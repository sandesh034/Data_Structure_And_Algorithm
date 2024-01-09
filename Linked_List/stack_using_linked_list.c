#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>


struct linked_list{
    int data;
    struct linked_list*next;
};
typedef struct linked_list Node;
Node*top =NULL;


void push (int value){
    if(top==NULL){
        Node*newNode=(Node*)malloc(sizeof(Node));
        newNode->data=value;
        newNode->next=NULL;
        top=newNode;
    }
    else{
        Node*newNode=(Node*)malloc(sizeof(Node));
        newNode->data=value;
        newNode->next=top;
        top=newNode;
    }
}



void pop(){
    Node*ptr=top;
    if(ptr==NULL){
        printf("The stack is empty\n");
    }
    else if(ptr->next==NULL){
       printf("The popped element is:\t%d\n",ptr->data);
       free(ptr);
       top=NULL;  
    }
    else{ 
        printf("The popped element is:\t%d\n",ptr->data);
        top=ptr->next;
        free(ptr);
    }
}

void display(){
    Node*ptr=top;
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
    if(top==NULL){
        printf("The stack is empty\n");
    }
    else{
         printf("The value of peek is:\t%d\n",top->data);
    }
}

int main(){
  int choice,value;
  while(1){
       printf("Stack operation\n");
       printf("________________\n");
       printf("1.Push\n");
       printf("2.Pop\n");
       printf("3.Display\n");
       printf("4.Peek\n");
       printf("5.Exit\n");
       printf("Enter your choice:\t");
       scanf("%d",&choice);
       switch (choice){
       case 1: printf("Enter the value to insert:\t");
               scanf("%d",&value);
               push(value);
               break;
      case 2: pop();
              break;
      case 3: display();
              break;
      case 4: peek();
              break;
      case 5: exit(0);
              break;
     default:printf("Enter the valid option\n");
            break;
       }
  }
 
    return 0;
}