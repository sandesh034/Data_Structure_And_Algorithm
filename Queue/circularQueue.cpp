#include<iostream>
using namespace std;

class Circularqueue{
    int front,rear,MAX_SIZE,*arr,value;
    static int count;
    public:
    Circularqueue(int size){
        front=-1;
        rear=-1;
        MAX_SIZE=size;
        arr=new int[MAX_SIZE];
    }

    bool isEmpty(){
      if((front==-1)&&(rear==-1)) return true;
      else return false;
    }

    bool isFull(){
        if(front==((rear+1)%MAX_SIZE)) return true;
        else return false;
    }
    void Enqueue(){
        if(isFull()){
            cout<<"The Queue is Full\n";
        }
        else if((front==-1)&&(rear==-1)){
            front=0;
            rear=0;
            cout<<"Enter the value to insert:\t";
            cin>> value;
            arr[rear]=value;
            count++;
        }
        else{
            rear=(rear+1)%MAX_SIZE;
            cout<<"Enter the value to insert:\t";
            cin>> value;
            arr[rear]=value;
            count++;
        }
    }

    void Dequeue(){
        if(isEmpty()){
            cout<<"The Queue is Empty"<<endl;
        }
        else if(front==rear){
           cout<<"The Dequeued Element is\t"<<arr[front]<<endl;
           front=rear=-1;
           count--;
        }
        else{
            cout<<"The Dequeued Element is\t"<<arr[front]<<endl;
            front=(front+1)%MAX_SIZE;
            count--;
        }
    }
    void Display(){
        if(isEmpty()){
            cout<<"The Queue is Empty"<<endl;
        }
        else{
            int i=front;
            while(i!=rear){
                cout<<arr[i]<<"\t";
                i=(i+1)%MAX_SIZE;
            }
            cout<<arr[i];  //printing last element
            cout<<"\n";
        }
    }

    void noOfElement(){
        cout<<"Number of Element\t"<<count<<endl;
    }
    void displayFront(){
        if(isEmpty()){
             cout<<"The Queue is Empty"<<endl;
        }
        else{
             cout<<"Front Element\t"<<arr[front]<<endl;
        }
        
    }

    ~Circularqueue(){
        delete[] arr;
    }
};
int Circularqueue::count=0;

int main(){
    int choice;
    bool status=true;
    Circularqueue q(3);

    while(status){
    cout<<"QUEUE OPERATION"<<endl;
    cout<<"---------------"<<endl;
    cout<<"1. Enqueue"<<endl;
    cout<<"2. Dequeue"<<endl;
    cout<<"3. Display"<<endl;
    cout<<"4. Front"<<endl;
    cout<<"5. No of Elements"<<endl;
    cout<<"6. Exit"<<endl;
    cout<<"Enter Your Choice:\t";
    cin>>choice;
    
    switch(choice){
        case 1: q.Enqueue();
                break;
        case 2: q.Dequeue();
                break;
        case 3: q.Display();
                break;
        case 4: q.displayFront();
                break;
        case 5: q.noOfElement();
                break;
        case 6: status =false;
                break;
        default: cout<<"Enter the valid  option";
                 break;
       }
    }
    return 0;
}