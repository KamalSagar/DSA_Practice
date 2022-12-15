#include<iostream>
using namespace std;

void maxHeapify(int arr[], int n, int i){

    int left = (i*2)+1, right = (i*2)+2;
    int largest = i;
    if(left<n && arr[left]>arr[largest]) 
        largest = left;
    if(right<n && arr[right]>arr[largest])
        largest = right;

    if(largest != i){
        swap(arr[i],arr[largest]);
        maxHeapify(arr,n,largest);
    }
}

void buildHeap(int arr[], int n){

    for(int i=(n-2)/2; i>=0; i--){
        maxHeapify(arr,n,i);
    }
}

void heapSort(int arr[], int n){
    
    buildHeap(arr,n);
    for(int i=n-1; i>=1; i--){
        swap(arr[i], arr[0]);
        maxHeapify(arr,i,0);
    }
}

int main(){
    int n; cin>>n;
    int arr[n];
    
    for(int i=0; i<n; i++)
        cin>>arr[i];
    

    heapSort(arr,n);
    
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}