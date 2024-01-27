#include<stdio.h>
#include <malloc.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*left;
    struct Node*right;
};
typedef struct Node Node;

Node* insert(Node*node,int value){
    if(node==NULL){
        Node*newNode=(Node*)malloc(sizeof(Node));
        newNode->data=value;
        newNode->left=NULL;
        newNode->right=NULL;
        node=newNode;
    }
    else if(value<node->data){
        node->left=insert(node->left,value);
    }
    else if(value>node->data){
        node->right=insert(node->right,value);
    }
    else{
        printf("Duplicate value are not allowed\n");
    }
    return node;
}

void inorderTraversal(Node*root){
    if(root!=NULL){
        inorderTraversal(root->left);
        printf("%d\t",root->data);
        inorderTraversal(root->right);
    }
}
void preorderTraversal(Node*root){
    if(root!=NULL){
        printf("%d\t",root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(Node*root){
    if(root!=NULL){
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d\t",root->data);
    }
}

void search(Node*root,int item){
    if(root==NULL){
        printf("\n%d is not found in tree\n",item);
    }
    else if(root->data==item){
        printf("\n%d is present in tree\n",item);
    }
    else if(item<root->data){
        search(root->left,item);
    }
    else{
        search(root->right,item);
    }
}


int main(){
    int choice,value;
    Node*root=NULL;
    while(1){
    printf("**********************************************\n");
    printf("*          Binary Search Tree (BST)          *\n");
    printf("**********************************************\n");

    printf("1.Insert\n");
    printf("2.Inorder Traversal\n");
    printf("3.Preorder Traversal\n");
    printf("4.Postorder Traversal\n");
    printf("5.Search\n");
    printf("6.Exit\n");
    printf("Enter your choice:\t");
    scanf("%d",&choice);

        switch (choice){
        case 1: printf("Enter the value to insert:\t");
                scanf("%d",&value);
                root=insert(root,value);
                break;

        case 2: printf("\nInorder Traversal:\n");
                inorderTraversal(root);
                printf("\n");
                break;

        case 3: printf("\nPreorder Traversal:\n");
                preorderTraversal(root);
                printf("\n");
                break;

        case 4: printf("\nPostorder Traversal:\n");
                postorderTraversal(root);
                printf("\n");
                break;

        case 5: printf("Enter the value to search:\t");
                scanf("%d",&value);
                search(root,value);
                break;
        case 6: exit(0);
                
        default:printf("Enter the valid option\n");
            break;
        }

        printf("\n\n");
    }
    
    return 0;
}

