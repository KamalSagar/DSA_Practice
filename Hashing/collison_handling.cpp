#include<iostream>
#include<list>

using namespace std;

struct myHash{
    int bucket;
    list<int> *table;

    myHash(int b){
        bucket = b;
        table = new list<int>[b];
    }

    void insert(int key){
        int i = key%bucket;
        table[i].push_back(key);
    }

    bool search(int key){
        int i=key%bucket;
        for(auto x:table[i])
            if(x==key)
                return true;

        return false;
    }

    void remove(int key){
        int i = key%bucket;
        table[i].remove(key);
    }

};

int main(){

    myHash htable(5);

    htable.insert(5);
    htable.insert(25);
    htable.insert(6);
    htable.insert(9);
    htable.insert(13);
    htable.insert(39);

    cout<<htable.search(39)<<endl;
    cout<<htable.search(11)<<endl;
    cout<<htable.search(5)<<endl;
    htable.remove(5);
    cout<<htable.search(5)<<endl;


    return 0;

}