#include<iostream>
using namespace std;

int table[256];

void initialize(){
    
    table[0]=0;

    for(int i=0; i<256; i++){
        table[i] = (i&1) + table[i/2];
    }
}



int main(){

    initialize();
    int n; cin>>n;
    int res = table[n & 0xff];
    n = n>>8;
    res = res + table[n & 0xff];
    n = n>>8;
    res = res + table[n & 0xff];
    n = n>>8;
    res = res + table[n & 0xff];

    cout<<res;

    return 0; 
}