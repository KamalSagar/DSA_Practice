#include<iostream>
using namespace std;

int isSorted(int arr[], int n){

    if(n==1)
        return 1;

    return (arr[n-1]<arr[n-2])?0:isSorted(arr,n-1);
}

int main(){

int arr[5] = {2,2,38,46,56};

cout<<isSorted(arr,5);

return 0;

}