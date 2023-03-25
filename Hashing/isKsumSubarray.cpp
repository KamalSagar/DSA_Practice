#include<iostream>
#include<unordered_set>

using namespace std;

bool subarraySum(int a[], int n, int sum){
    unordered_set<int> h;
    int pre_sum = 0;

    for(int i=0; i<n; i++){
        pre_sum += a[i];

        if(pre_sum==sum)
            return true;
        if(h.find(pre_sum-sum)!=h.end())
            return true;
        
        h.insert(pre_sum);
    }

    return false;
}

int main(){

    int arr[] = {1,3,5,-5,6,7,99};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<subarraySum(arr, n, 100);
}