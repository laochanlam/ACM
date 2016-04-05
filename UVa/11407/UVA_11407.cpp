#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
int main() {
	int t, n, i, j;
	long long int DP[10001];
	DP[0] = 0;
	for(i = 1; i <= 10000; i++)	
        DP[i] = 99999;
	for(i = 1; i <= 100; i++) 
    {
    
		for(j = i*i; j <= 10000; j++)
		DP[j] = min(DP[j],DP[j-i*i]+1);	
	}
    
    scanf("%d",&t);
    for (i=0;i<t;i++)
    {
        scanf("%d",&n);
        printf("%lld\n",DP[n]);
    }

}
