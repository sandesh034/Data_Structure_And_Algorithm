#include<iostream>
using namespace std;

void swap(int *a, int*b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void bubble_sort(int *arr,int n){
    for(int i=0;i<n-1;i++){
        bool is_sorted=false;

        for(int j=0;j<n-i-1;j++){
            if(*(arr+j)>*(arr+j+1)){
                swap(arr+j,arr+j+1);
                is_sorted=true;
            }
        }

        if(!is_sorted) break;
    }
}
void display(int*arr,int n){
    for(int i=0;i<n;i++){
        cout<<*(arr+i)<<"\t";
    }
}


int main(){
    int arr[]={3,7,1,9,5,2,11};
    bubble_sort(arr,7);
    display(arr,7);
    return 0;
}

/*
NOTE:
There is always n-1 swaps
Time complexity: O(n^2)
Space Complexity: O(n)
Maximum number of swaps: n*(n-1)/2
Worst case: Array already sorted in descending order
*/