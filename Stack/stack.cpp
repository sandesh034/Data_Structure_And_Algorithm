#include<iostream>
using namespace std;

class Stack{
private:
int MAX_SIZE,top;
int *arr;

public:
Stack(int size){
 this->MAX_SIZE=size;
 this->top=-1;
 arr=new int[MAX_SIZE];
}

bool isEmpty(){
    if(top==-1) return true;
    else return false;
}

bool isFull(){
    if(top==(MAX_SIZE-1)) return true;
    else return false;
}
void display(){
    if(isEmpty()){
        cout<<"The Stack is empty";
    }
    else{
        for(int i=top;i>=0;i--){
        cout<<arr[i]<<endl;
       }
     } 
    }
void push(int value){

    if(isFull()){
        cout<<"The Stack is full"<<endl;
    }
    else {
        top++;
        arr[top]=value;
    }
}
void pop(){
    if(isEmpty()){
      cout<<"The Stack is empty"<<endl;  
    }
    else{
        cout<<arr[top]<<endl;
        top--;
    }
}
void peek(){
     if(isEmpty()){
      cout<<"The Stack is empty"<<endl;  
    }
    else{
    cout<<"The value pointed by the top is : "<<arr[top]<<endl;
    }
}
void noOfElement(){
   cout<<(top+1)<<endl;
}
~Stack(){
    delete[] arr;
}

};

int main(){
    int choice,value;
    bool status=true; 
    Stack s(10);

   
    
    while(status){
        cout<<endl;
         cout<<"Stack Operation"<<endl;
         cout<<"1. Push"<<endl;
         cout<<"2. Pop"<<endl;
         cout<<"3. Display"<<endl;
         cout<<"4. No of Element"<<endl;
         cout<<"5. Peek Element"<<endl;
         cout<<"6. Exit"<<endl<<endl;
         cout<<"Enter your choice"<<endl;
         cin>>choice;
        switch(choice){
            case 1: 
                cout<<"Enter the value to insert"<<endl;
                cin>>value;
                s.push(value);
                break;

             case 2: s.pop();
                     break;
             case 3: s.display();
                     break;
             case 4: s.noOfElement();
                     break;
             case 5: s.peek();
                     break;
             case 6 : status=false;
                     break; 
            default : cout<<"Enter the valid option"<<endl;
        }
    }
    return 0;
    
}