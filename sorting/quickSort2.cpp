#include<iostream>
using namespace std;

int hpartition(int a[], int l, int h){
    int pivot = a[l];
    int i = l-1, j = h+1;

    while(true){

        do{
            i++;
        }while(a[i]<pivot);
        do{
            j--;
        }while(a[j]>pivot);
        if(i>=j)
            return j;
        swap(a[i],a[j]);
        
    }

}

void qSort(int a[], int l, int h){

    if(l<h){
        int p = hpartition(a, l, h);
        qSort(a,l,p);
        qSort(a, p+1, h);
    }
}

int main(){

    int n; cin>>n;
    int arr[n];

    for(int i=0; i<n; i++)
        cin>>arr[i];

    qSort(arr,0,n-1);


    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";

    return 0;
}