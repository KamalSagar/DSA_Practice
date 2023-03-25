#include<iostream>
using namespace std;
char a[32];

void printk_ary(int n, int k){
    if(n<1)
        printf("%s \n",a);

    else{
        for(int j=0; j<k; j++){
            a[n-1]=j+'0';
            printk_ary(n-1,k);
        }
    }
}

int main(){

    printk_ary(5,3);

    return 0;
}