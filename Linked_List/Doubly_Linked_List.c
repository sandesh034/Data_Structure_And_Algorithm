#include<stdio.h>
#include<malloc.h>

struct doublyLinkedList{
    int data;
    struct doublyLinkedList* left;
    struct doublyLinkedList* right;
};
typedef struct doublyLinkedList Node;

Node*start=NULL;

void insertAtBegining(int value){
    Node*newNode=(Node*)malloc(sizeof(Node));
    newNode->left=NULL;
    newNode->right=NULL;
    newNode->data=value;
    
    if(start==NULL){
        start=newNode;
    }
    else{
        newNode->right=start;
        start->left=newNode;
        start=newNode;
    }
};

void insertAtEnd(int value){
    Node*newNode=(Node*)malloc(sizeof(Node));
    newNode->left=NULL;
    newNode->right=NULL;
    newNode->data=value;
    
    if(start==NULL){
        start=newNode;
    }
    else{
        Node*ptr=start;
        while(ptr->right!=NULL){
            ptr=ptr->right;
        }
        newNode->left=ptr;
        ptr->right=newNode;
    }
};

void insertAtSpecifiedPosition(int value, int position){
    Node*newNode=(Node*)malloc(sizeof(Node));
    newNode->left=NULL;
    newNode->right=NULL;
    newNode->data=value;
    
    /*if position is less than or equal 1 insert at begining
    if the position is greater than size(no of element) insert at end 
    otherwise insert at specified position*/
    
    if(position<=1){
      if(start==NULL){
          start=newNode;
      }
      else{
          newNode->right=start;
          start->left=newNode;
          start=newNode;
      }
    }
    else{
        Node*ptr=start;
        int i=1;
        for(i=1;i<position;i++){
            if(i==position-1){    //inserting at specified position
                newNode->right=ptr->right;
                newNode->left=ptr;
                ptr->right->left=newNode;
                ptr->right=newNode;
                return ;
            }
            
            if(ptr->right==NULL){  // if position >size insert at end
                newNode->left=ptr;
                ptr->right=newNode;
                return ;
            }
            ptr=ptr->right;
        
        }
    }
    
};


void deleteAtBegining(){
    if(start==NULL){
        printf("The linked list is empty\n");
    }
    else{
        Node*temp=start;
        start=start->right;
        start->left=NULL;
        free(temp);
    }
};

void deleteAtEnd(){
    if(start==NULL){
         printf("The linked list is empty\n");
    }
    else if(start->right==NULL){
        free(start->right);
        start=NULL;
    }
    else{
        Node*ptr=start;
        while(ptr->right->right!=NULL){
            ptr=ptr->right;
        }
        free(ptr->right);
         ptr->right=NULL;
    }
}

void deleteAtSpecifiedPosition(int position){
    if(position<1){
        printf("Invalid position. Position should be positive integer\n");
    }
    else if(start==NULL){
        printf("The linked list is empty\n");
    }
    else{
        Node*ptr=start;
        int i=1;
        for(i=1;i<=position;i++){
            if(i==position-1){
                Node*temp=ptr->right->right;
                free(ptr->right);
                ptr->right=temp;
                temp->left=ptr;
                return;
            }
            if(ptr==NULL){
                printf("invalid position\n");
                return ;
            }
            ptr=ptr->right;
        }
    }
}

void display(){
    if(start==NULL){
        printf("The linked list is empty\n");
    }
    else{
        Node*ptr=start;
        while(ptr!=NULL){
            printf("%d\t",ptr->data);
            ptr=ptr->right;
        }
        printf("\n");
    }
};



int main(){
    insertAtBegining(10);
    insertAtBegining(20);
    insertAtBegining(30);
    insertAtEnd(40);
    insertAtEnd(50);
    insertAtSpecifiedPosition(60,10);
    display();
    deleteAtBegining();
    display();
    deleteAtEnd();
    display();
    deleteAtSpecifiedPosition(3);
    display();
   
    return 0;
}