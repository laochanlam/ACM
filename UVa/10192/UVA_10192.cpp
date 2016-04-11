#include<cstdio>
#include<vector>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<string>
using namespace std;

int dp[101][101] = {0};
string a,b;

int main(){
    int i,j,count = 0;
    while (getline(cin,a))
    {
        if (a == "#") break;
        count++;
        getline(cin,b);
        a.insert(0,"-"); b.insert(0,"-");
        for (i=1;i<a.size();i++)
            for (j=1;j<b.size();j++)
        {
            if (a[i] == b[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
        
        printf("Case #%d: you can visit at most %d cities.\n",count,dp[a.size()-1][b.size()-1]);
 /*                 
        for (i=0;i<a.size();i++)
        {cout<<endl;
            for (j=0;j<b.size();j++)
                cout<<dp[i][j];
        }
*/
        a.clear();b.clear();
        memset(dp,0,sizeof(dp));
    }
}
