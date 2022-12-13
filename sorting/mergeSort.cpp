#include<iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high){
    int n = (mid-low) + 1;
    int m = (high-mid);
    int left[n], right[m];

    for(int i=0; i<n; i++){
        left[i] = arr[i+low];
    }
 
    for(int i=0; i<m; i++){
        right[i] = arr[i+mid+1];
    }

    int i=0, j=0, k=low;
    while(i<n && j<m){
        if(left[i]<=right[j]){
            arr[k] = left[i];
            i++;
            k++;
        }

        else{
            arr[k]=right[j];
            j++;
            k++;
        }
    }

    while(i<n){
        arr[k] = left[i];
        i++; k++;
    }

    while(j<m){
        arr[k] = right[j];
        j++; k++;
    }

}

void mergeSort(int arr[], int l, int r){

    if(r>l){
        int mid = l + (r-l)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr,l, mid, r);
    }
}

int main(){

    int n; cin>>n;
    int arr[n];
    
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    mergeSort(arr,0,n-1);

    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    
    return 0;
}