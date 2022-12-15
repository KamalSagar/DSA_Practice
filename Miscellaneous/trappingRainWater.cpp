// Trapping rain water problem
#include<iostream>
using namespace std;

// TC - O(n), Space - O(n)
int trappedWater(int arr[], int n){
     int right[n], left[n];

    right[0] = arr[0];
    for(int i=1; i<n; i++)
        right[i] = max(arr[i],right[i-1]);

    left[n-1] = arr[n-1];
    for(int i=n-2; i>=0; i--)
        left[i] = max(arr[i],left[i+1]);
    
    // for(int i=0; i<n; i++)
    //     cout<<right[i]<<" ";
    // cout<<endl;
    
    // for(int i=0; i<n; i++)
    //     cout<<left[i]<<" ";
    // cout<<endl;

    int total=0;
    for(int i=0; i<n; i++){
        total += min(left[i],right[i]) - arr[i];
    }

    return total;
}

int trappedWaterOptimal(int arr[], int n){
    int left = 0, right = n-1;
    int leftMax = 0, rightMax = 0, res = 0;

    while(left<right){
        if(arr[left]<=arr[right]){
            if(arr[left]>=leftMax) leftMax = arr[left];
            else res += leftMax - arr[left];
            left++;
        }
        else{
            if(arr[right]>=rightMax) rightMax = arr[right];
            else res += rightMax - arr[right];
            right--;
        }
    }

    return res;
}


int main(){

    int arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
   
    cout<<trappedWater(arr,n)<<endl;
    cout<<trappedWaterOptimal(arr,n);
    return 0;
}