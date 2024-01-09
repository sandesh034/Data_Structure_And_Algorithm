#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct linked_list
{
    int data;
    struct linked_list*next;
};
typedef struct linked_list Node;
Node*start=NULL;

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


void insertAtSpecifiedPosition(int value, int position) {
    Node *ptr = start;
    int i;
    if (position < 1) {
        printf("Invalid position\n");
        return;
    }

    else if(ptr == NULL) {
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->data = value;
        newNode->next = NULL;
        start = newNode;
    } 
    else {
        for(i = 1; i < position - 1 && ptr->next != NULL; i++) {
            ptr = ptr->next;
        }

        if (ptr == NULL) {
            printf("Invalid position\n");
            return;
        }
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->data = value;
        newNode->next = ptr->next;
        ptr->next = newNode;
    }
}

void insertAtEnd(int value) {
    Node *ptr = start;

    // inserting at the beginning if the list is empty
    if(ptr == NULL) {
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->data = value;
        newNode->next = NULL;
        start = newNode;
    } else {
        while(ptr->next != NULL) {
             ptr = ptr->next;
        }

        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->data = value;
        newNode->next = NULL;
        ptr->next = newNode;
    }
}

void deleteAtBegining(){
    Node*ptr=start;
    if(ptr==NULL){
        printf("The linked list is empty");
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
void deleteAtSpecifiedPosition(int position){
    Node*ptr=start,*temp;
    int i;
    if(start==NULL){
        printf("The linked list is empty\n");
        return;
    }
    else if(position<=0){
        printf("Invalid position\n");
    }

    else  if(position==1){
        start=ptr->next;
        free(ptr);
        return;
    }

    else{
        for(i=1;i<position-1 && ptr->next!=NULL;i++){
            ptr=ptr->next;
            i++;
        }
            
        if (ptr == NULL || ptr->next == NULL) {
            printf("Invalid position\n");
            return;
        }
        else{
            temp=ptr->next;
            ptr->next=temp->next;
            free(temp);
        }
    }
}

void deleteAtEnd(){
    Node*ptr=start;
    if(ptr==NULL){
        printf("The linked list is empty\n");
    }
    else{
        while (ptr->next->next!=NULL){
            ptr=ptr->next;
        }
        free(ptr->next);
        ptr->next=NULL;
    }
}
void display() {
    Node *ptr = start;

    if (ptr == NULL) {
        printf("The linked list is empty\n\n");
    } else {
        while (ptr != NULL) {
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        } 
        printf("\n");
    }
}
void search(int item) {
    Node *ptr = start;
    int position = 1;

    if (ptr == NULL) {
        printf("The linked list is empty\n");
    } else {
        while (ptr != NULL) {
            if (ptr->data == item) {
                printf("The element %d is found at position %d\n\n", ptr->data, position);
                return;
            }
            ptr = ptr->next;
            position++;
        }
        printf("The element %d is not found in the linked list\n\n", item);
    }
}



int main(){
    int choice,value,position;
    while(1){
        printf("Linked-List Operation:\n");
        printf("______________________\n");
        printf("1.Insert At Begining\n");
        printf("2.Insert At Specified Position\n");
        printf("3.Insert At End\n"); 
        printf("4.Delete At Begining\n");
        printf("5.Delete At Specified Position\n");
        printf("6.Delete At End\n");
        printf("7.Display\n");
        printf("8.Search\n");
        printf("9.Exit\n");
        printf("Enter your choice:\t");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: printf("Enter the value to insert:\t");
                scanf("%d",&value);
                insertAtBegining(value);
                printf("\n");
                break;
        case 2: printf("Enter the value to insert:\t");
                scanf("%d",&value);
                printf("Enter the position to insert:\t");
                scanf("%d",&position);
                insertAtSpecifiedPosition(value,position);
                printf("\n");
                break;

        case 3: printf("Enter the value to insert:\t");
                scanf("%d",&value);
                insertAtEnd(value);
                printf("\n");
                break;    

        case 4: deleteAtBegining();
                break;
                
        case 5: printf("Enter the position to delete:\t");
                scanf("%d",&position);
                deleteAtSpecifiedPosition(position);
                break;

        case 6: deleteAtEnd();
                break;
                  
    
        case 7: display();
                break;   

        case 8: printf("Enter the element to seatch:\t");
                scanf("%d",&value);
                search(value);
                break;
        case 9: exit(1);
                break;
        
        default:printf("Enter the valid option\n");
                break;
        }
    }   
    
    return 0;
}