#include<iostream>
using namespace std;

void merge(int arr1[], int arr2[], int n, int m){

    int arr[n+m];
    int i=0, j=0, k=0;
    while(i<n && j<m){

        if(arr1[i]<arr2[j]){
            arr[k] = arr1[i];
            i++;
            k++;
        }

        if(arr1[i]>arr2[j]){
            arr[k] = arr2[j];
            j++;
            k++;
        }
    }

    while(i<n){
        arr[k] = arr1[i];
        i++;
        k++;
    }

    while(j<m){
        arr[k] = arr2[j];
        j++;
        k++;
    }
     
    for(int k=0; k<n+m; k++){
        cout<<arr[k]<<" ";
    }
}

int main(){

    int n,m;

    cin>>n;
    int arr1[n];
    for(int i=0; i<n; i++)
        cin>>arr1[i];

    cin>>m;
    int arr2[m];
    for(int i=0; i<m; i++)
        cin>>arr2[i];

    merge(arr1,arr2,n,m);

    return 0;
}