#include<iostream>
using namespace std;

class Queue{
    int front,rear,MAX_SIZE,*arr;
    public:
    Queue(int size){
        front=-1;
        rear=-1;
        MAX_SIZE=size;
        arr=new int[MAX_SIZE];
    }
    void enqueue(int value){
        if((front==-1)&&(rear==-1)||(front>rear)){
            front=0;
            rear=0;
            arr[rear]=value;
        }
        else if((front==0)&&(rear==MAX_SIZE-1)){
            cout<<"The queue is full"<<endl;
        }
        else{
            rear++;
            arr[rear]=value;
        }
    }

    void dequeue(){
        if((front==-1)&&(rear==-1)||(front>rear)){
            cout<<"The queue is empty"<<endl;
        }
        else {
            cout<<"The Dequeued element is "<<arr[front]<<endl;
            front++;
        }
    }
    void display(){
        if((front==-1)&&(rear==-1)){
            cout<<"The queue is empty"<<endl;
        }
        else{
            for(int i=front;i<=rear;i++){
              cout<<arr[i]<<endl;
        }
        }  
    }
    void displayFront(){
        cout<<arr[front]<<endl;
    }
    ~Queue(){
        delete[] arr;
    }

};


int main(){
    int value,choice;
    bool status=true;
    Queue q(10);

    while(status){
    cout<<"QUEUE OPERATION"<<endl;
    cout<<"---------------"<<endl;
    cout<<"1. Enqueue"<<endl;
    cout<<"2. Dequeue"<<endl;
    cout<<"3. Display"<<endl;
    cout<<"4. Front"<<endl;
    cout<<"5. Exit"<<endl;
    cout<<"Enter Your Choice:\t";
    cin>>choice;
    
    switch(choice){
        case 1: cout<<"Enter the value to insert:\t";
                cin>> value;
                q.enqueue(value);
                break;
        case 2: q.dequeue();
                break;
        case 3: q.display();
                break;
        case 4: q.displayFront();
                break;
        case 5: status =false;
                break;
        default: cout<<"Enter the valid  option";
                 break;
       }
    }
    return 0;
}