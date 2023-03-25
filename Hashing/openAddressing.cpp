#include<iostream>
using namespace std;

struct myHash{
    int *arr;
    int cap,size;

    myHash(int x){
        cap = x;
        size = 0;
        arr = new int[cap];
        for(int i=0; i<cap; i++)
            arr[i] = -1;
    }

    int hash(int key){
        return key%cap;
    }

    bool search(int key){
        int h = hash(key);
        int i=h;

        while(arr[i]!=1){
            if(arr[i]==key)
                return true;
            
            i = (i+1)%cap;
            if(i==h)
                return false;
        }

        return false;
    }

    bool insert(int key){
        if(size==cap)
            return false;
        
        int i = hash(key);
    
        while(arr[i]!=-1 && arr[i]!=-2 && arr[i]!=key)
            i = (i+1)%cap;
        
        if(arr[i]==key)
            return false;
        else{
            arr[i] = key;
            size++;
            return true;
        }

    };

    bool erase(int key){
        if(size==0)
            return false;

        int h = hash(key);
        int i = h;

        while(arr[i]!=key){
            i = (i+1)%cap;

            if(i==h)
                return false;
        }

        if(arr[i] == key){
            arr[i] = -2;
            size--;
            return true;
        }
    }

};

int main(){

    myHash mh(5);

    mh.insert(45);
    mh.insert(44);
    mh.insert(5);
    mh.insert(89);
    mh.insert(12);
    
    mh.erase(45);
    mh.erase(44);
    mh.erase(5);
    mh.erase(89);
    mh.erase(12);

    mh.insert(14);
    

    cout<<mh.search(14);

















    return 0;

}