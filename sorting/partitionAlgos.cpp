#include<iostream>
using namespace std;

void partition(int a[], int l, int h, int p){
    int n = h-l+1;
    int temp[n];
    int idx=0;

    for(int i=0; i<n; i++){
        if(a[i]<=a[p]){
            temp[idx] = a[i];
            idx++;
        }
    }

    for(int i=0; i<n; i++){
        if(a[i]>a[p]){
            temp[idx] = a[i];
            idx++;
        }
    }

    for(int i=0; i<n; i++)
        a[i] = temp[i];
    
}

int lpartition(int a[], int l, int h){
    int pivot = a[h];
    int i= l-1;
    
    for(int j=l; j<=h-1; j++){
        if(a[j]<pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[h]);
    return i+1;
}

int hpartition(int a[], int l, int h){
    int pivot = a[l];

    int i=l-1, j= h+1;

    while(true){
        do{
            i++;
        }while(a[i]<pivot);

        do{
            j--;
        }while(a[j]>pivot);
        if(i>=j) return j;
        swap(a[i],a[j]);
    }

}

int main(){

    int n; cin>>n;
    int arr[n];

    for(int i=0; i<n; i++)
        cin>>arr[i];

    // partition(arr,0,n-1, n-1);
    // lpartition(arr,0,n-1);

    hpartition(arr,0,n-1);


    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";

    return 0;
}