// Check subarray sum equal to 0
#include<iostream>
#include<unordered_set>

using namespace std;

bool naive(int a[], int n){
    
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=i; j<n; j++){
            sum += a[j];
            if(sum==0){
                return true;
            }
        }
    }

    return false;
}

// Using prefix sum and hash
bool efficient(int a[], int n){
    int pre_sum=0;
    unordered_set<int> h;

    for(int i=0; i<n; i++){
        pre_sum += a[i];
        if(h.find(pre_sum)!=h.end())
            return true;
        
        if(pre_sum==0)
            return true;

        h.insert(pre_sum);
    }

    return false;
}

int main(){

    int a[] = {4,1,77,-70,-7,8};
    int n = sizeof(a)/sizeof(a[0]);
    
    cout<<naive(a,n)<<endl;
    cout<<efficient(a,n)<<endl;
    return 0;
}