#include<iostream>

using namespace std;
int main(){
    int arr[]={3,5,5,1,7,2};
    int n=sizeof(arr)/sizeof(arr[0]);

    //selection sort
    int min_index;
    for(int i=0;i<n-1;i++){
        min_index=i;
        for(int j=i+1;j<n;j++){
            min_index=(arr[j]<arr[min_index])?j:min_index;
        }
        swap(arr[i],arr[min_index]);
    }
    
    //display output
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }
    return 0;
}