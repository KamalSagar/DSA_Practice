#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<vector<int>> memo;

int lcs(string s1, string s2, int m, int n){
    
    if(memo[m][n] != -1)
        return memo[m][n];
    if(m==0 || n==0)
        memo[m][n]=0;
    else{    
        if(s1[m-1]==s2[n-1])
            memo[m][n] = 1 + lcs(s1,s2,m-1, n-1);
        else    
            memo[m][n] = max(lcs(s1,s2,m-1,n),lcs(s1,s2,m,n-1));
    }
    return memo[m][n];
}

int main(){
    string s1 = "axyz";
    string s2 = "baz";
    int m=s1.size();
    int n = s2.size();

    for(int i=0; i<=m; i++){
        vector<int> temp(n+1,-1);
        memo.push_back(temp);
    }

    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            cout<<memo[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<lcs(s1,s2,s1.size(),s2.size())<<endl;
}