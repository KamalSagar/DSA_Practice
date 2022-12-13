// Trapping rain water problem
#include<iostream>
using namespace std;

int main(){

    int arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    int right[n], left[n];

    right[0] = arr[0];
    for(int i=1; i<n; i++)
        right[i] = max(arr[i],right[i-1]);

    left[n-1] = arr[n-1];
    for(int i=n-2; i>=0; i--)
        left[i] = max(arr[i],left[i+1]);
    

    for(int i=0; i<n; i++)
        cout<<right[i]<<" ";
    cout<<endl;
    
    for(int i=0; i<n; i++)
        cout<<left[i]<<" ";
    cout<<endl;
    
    int total=0;
    for(int i=0; i<n; i++){
        total += min(left[i],right[i]) - arr[i];
    }

    cout<<total;
    return 0;
}