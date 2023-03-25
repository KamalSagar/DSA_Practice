#include<iostream>
#include<unordered_set>
#include<vector>

using namespace std;

bool subArraySum(vector<int> a, int sum){
    int pre_sum = 0;
    unordered_set<int> h;

    for(int i=0; i<a.size(); i++){
        pre_sum += a[i];

        if(pre_sum==sum)
            return true;
        if(h.find(pre_sum-sum)!=h.end())
            return true;
        h.insert(pre_sum);
    }

    return false;
}

bool equalSumArray(vector<int> arr, int n){
    int total_sum = 0;
    for(int i=0; i<n; i++)
        total_sum += arr[i];
    if(total_sum%2!=0)
        return false;

    vector<int> m3;
    vector<int> m5;
    vector<int> other;

    for(int i=0; i<n; i++){
        if(arr[i]%5==0)
            m5.push_back(arr[i]);
        else if(arr[i]%3==0)
            m3.push_back(arr[i]);
        else    
            other.push_back(arr[i]);
    }

    int sum3=0, sum5=0;
    for(int i=0; i<m5.size(); i++)
        sum5+=m5[i];
    
    for(int i=0; i<m3.size(); i++)
        sum3+=m3[i];

    if(sum3==(total_sum/2) || sum5==(total_sum/2))
        return true;
    else if(sum3>(total_sum/2) || sum5>(total_sum/2))
        return false;

    if(subArraySum(other,(total_sum/2)-sum3) || subArraySum(other,(total_sum/2)-sum5))
        return true;
    else if(m3.size() == 0 || m5.size() == 0)
        return subArraySum(arr,(total_sum/2));
    
    return false;
}

int main(){

    vector<int> arr{1,4,3};
    cout<<equalSumArray(arr,arr.size())<<endl;
}