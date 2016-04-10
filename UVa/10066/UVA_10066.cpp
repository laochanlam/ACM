#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

int dp[101][101] ;
int a[101];
int b[101];

int main(){
    int i,j,n,m;
    int count= 0;

    while (scanf("%d %d",&n,&m)!=EOF)
    {
        if (m==0 && n==0) break;
        //if (count!=0) cout<<endl;
        count++;
        memset(dp,0,sizeof(dp));
        
        for (i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for (i=1;i<=m;i++)
            scanf("%d",&b[i]);
        
        for (i=1;i<=n;i++)
            for (j=1;j<=m;j++)
        {
            if (a[i] == b[j])
                dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
        }
        printf("Twin Towers #%d\nNumber of Tiles : %d\n\n",count,dp[n][m]);


    }
    
}
