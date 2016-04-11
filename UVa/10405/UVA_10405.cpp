#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iostream>
using namespace std;

int dp[1001][1001];

int main(){
    string a,b;
    int i,j;
    memset(dp,0,sizeof(dp));
    a.clear();b.clear();
    while (getline(cin,a))
    {
        getline(cin,b);
        a.insert(0,"-");
        b.insert(0,"-");
 
        for (i=1;i<a.length();i++)
            for (j=1;j<b.length();j++)
                if ( a[i] == b[j] )
                    dp[i][j] = dp[i-1][j-1]+1;
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
    
        cout<<dp[a.length()-1][b.length()-1]<<endl;    
    }

}
