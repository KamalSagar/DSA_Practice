#include<iostream>
using namespace std;

    bool isIsomorphic(string s, string t) {

        int DictStoT[256]={-1};
        int DictTtoS[256]={-1};
        
        for(int i=0; i<256; i++){
            DictStoT[i] = -1;
            DictTtoS[i] = -1;
        }

        for(int i=0; i<s.size(); ++i){
            char c1 = s[i];
            char c2 = t[i];
            cout<<"c1, c2 : "<<c1<<", "<<c2<<endl;
            if(DictStoT[c1]==-1 && DictTtoS[c2]==-1){
                DictStoT[c1] = c2;
                DictTtoS[c2] = c1;
                cout<<"i: "<<i<<" | "<<DictStoT[c1]<<" "<<DictTtoS[c2]<<endl;
            }
            else if(!(DictStoT[c1]==c2 && DictTtoS[c2]==c1)){
                return false;
            }
        }
        return true;
    }

int main(){

    cout<<isIsomorphic("egg","add");



    return 0;
}
