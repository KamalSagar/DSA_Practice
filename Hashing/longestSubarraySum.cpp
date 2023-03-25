#include<iostream>
#include<unordered_map>
using namespace std;

int naive(int *a, int n, int k){
    
    int ans = 0;
    
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=i; j<n; j++){
            sum += a[j];
            if(sum == k){
                ans = max(ans,j-i+1);
            }
        }
    }

    return ans;
}

int efficient(int a[], int n, int sum){
    int pre_sum=0;
    unordered_map<int,int> m;
    int res=0;

    for(int i=0; i<n; i++){
        pre_sum += a[i];
        if(pre_sum == sum)
            res = i+1;

        if(m.find(pre_sum) == m.end())
            m.insert({pre_sum, i});
        
        if(m.find(pre_sum-sum)!=m.end()){
            res = max(res, (i-m[pre_sum-sum]));
        }
    }
    return res;
}

int main(){

    int arr[] = {5,8,-4,-4,9,8,-9, 2,-2};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<naive(arr,n,0)<<endl; 
    cout<<efficient(arr,n,0)<<endl;

    return 0;
}