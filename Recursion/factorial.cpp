#include <iostream>
using namespace std;

int factorial(int n){
    if(n==0||n==0){
        return 1;
    }
    else{
        return n*factorial(n-1);
    }
}

int main(){
    int n;
    cout<<"Enter the number:\t";
    cin>>n;
    cout<<"The factorial of "<<n<<" is:\t"<<factorial(n)<<endl;
    return 0;
}