#include<iostream>
using namespace std;

class Node{
    int value;
    Node*next;
    public:

    Node(int value){
        this->value=value;
        this->next=NULL;
    }

    void insertAtStart(Node* &head,int data){
        Node *temp=new Node(data);
        temp.next=head;
        head=temp;
    }

    void display(Node *head){
        Node *temp= head
        while(temp!=NULL){
         cout<<temp->value<<endl;
         temp=temp->next;
        }
    }

}

int main(){
    return 0;
}