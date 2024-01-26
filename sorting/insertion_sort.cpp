#include<iostream>

using namespace std;
int main(){
    int arr[]={5,2,11,-2,7,7,4};
    int n=sizeof(arr)/sizeof(arr[0]);

    //insertion sort
    for(int i=0;i<n-1;i++){
        int j=i+1;
        
        while(j>=0 && arr[j]<arr[j-1]){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }
    return 0;
}