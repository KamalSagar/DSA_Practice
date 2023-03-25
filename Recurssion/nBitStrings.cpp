// Generate all string of n bits
#include<iostream>
using namespace std;

void printString(char a[], int n){
    if(n<1){
        printf("%s \n",a);
    }

    else{
        a[n-1]='0';
        printString(a,n-1);
        a[n-1]='1';
        printString(a,n-1);
    }
}

int main(){

    char a[4];

    printString(a,3);

    return 0;
}