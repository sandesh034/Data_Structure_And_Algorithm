#include<iostream>
using namespace std;

void TOH(int n, char source,char destination, char auxiliary){
    if(n==1){
        cout<<"Move the disc "<<n<<" from "<<source<<" to "<<destination<<endl;
    }
    else{
        TOH(n-1,source,auxiliary,destination);
        cout<<"Move the disc "<<n<<" from "<<source<<" to "<<destination<<endl;
        TOH(n-1,auxiliary,destination,source);

    }
}

int main(){
    int n;
    cout<<"Enter the number of disc:\t";
    cin>>n;
    TOH(n,'A','B','C');
    return 0;
}