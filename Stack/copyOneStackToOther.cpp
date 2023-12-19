/*Inbult stack in stl

For creating  a stack, we must include the <stack> header file in our code. We then use this syntax to define the std::stack:
  
The functions associated with stack are: 
empty() – Returns whether the stack is empty – Time Complexity : O(1) 
size() – Returns the size of the stack – Time Complexity : O(1) 
top() – Returns a reference to the top most element of the stack – Time Complexity : O(1) 
push(g) – Adds the element ‘g’ at the top of the stack – Time Complexity : O(1) 
pop() – Deletes the most recent entered element of the stack – Time Complexity : O(1) 
*/

//problem statement : Copy content of one stack to another stack
//concept : popping the content of source stack and pushing to temp stack will reverse it
//          and doing same thing between temp and destination will make exact copy

#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int>srcStack;
    stack<int>tempStack;
    stack<int>destStack;

    srcStack.push(10);
    srcStack.push(20);
    srcStack.push(30);
    srcStack.push(40);


   while(!srcStack.empty()){
        tempStack.push(srcStack.top());
        srcStack.pop();
    }

    while(!tempStack.empty()){
        destStack.push(tempStack.top());
        tempStack.pop();
    }

    cout<<"Destination stack content"<<endl;
    while(!destStack.empty()){
        cout<<destStack.top()<<endl;
        destStack.pop();
    }
  
    return 0;
}