// find the longest sub array with equal number of 0s and 1s
#include<iostream>
#include<unordered_map>

using namespace std;

int naive(int arr[], int n){

    int max_len=0;

    for(int i=0; i<n; i++){
        int curr_len=0, ones=0, zeros=0;
        for(int j=i; j<n; j++){
            if(arr[j] == 0)
                zeros++;
            if(arr[j] == 1)
                ones++;

            if(ones == zeros){
                curr_len = ones + zeros;
                max_len = max(curr_len, max_len);
            }
        }
    }
    return max_len;
}

int efficient(int arr[], int n){
    int pre_sum = 0;
    int res = 0;
    unordered_map<int,int> m;
    for(int i=0; i<n; i++)
        if(arr[i]==0)
            arr[i] = -1;

    for(int i=0; i<n; i++){
        pre_sum += arr[i];

        if(pre_sum==0)
            res = i+1;
        
        if(m.find(pre_sum)==m.end())
            m.insert({pre_sum, i});

        if(m.find(pre_sum)!=m.end())
            res = max(res,i-m[pre_sum]);
    }
    return res;
}

int main(){
    int arr[] = {1,0,1,1,1,0,0,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<naive(arr,n)<<endl;
    cout<<efficient(arr,n)<<endl;

    return 0;
}