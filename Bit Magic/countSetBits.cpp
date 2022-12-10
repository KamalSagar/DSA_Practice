// brian kernigam algorithm TC - theta(no. of set bits)
#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    int count =0;
    cin>>n;

    while(n){
        n=n &(n-1);
        count++;
    }

    cout<<count;

    return 0;
}