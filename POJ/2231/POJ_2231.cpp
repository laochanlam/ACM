#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;

int main(){
    int n;
    int i,j;
    long long int ans = 0;
    int count = 0;
    long long int a[10000];
    scanf("%d\n",&n);
    for (i=0;i<n;i++)
        scanf("%lld",&a[i]);
    sort(a,a+n);
    for (i=0;i<n-1;i++)
            ans = ans + (n-i-1)*(i+1)*(a[i+1]-a[i]);

    
    printf("%lld",ans*2);
   }
