#include<cstdio>
#include<iostream>
using namespace std;

long long int factorial(long long int n){
    long long int  ans = 0;
    long long int  i;
    for (i=n;i>1;i--)
        ans += i*(i-1);
    return ans;
}


int main(){
    long long int n,m,c,ans;
    long long int row,col,dia;
    int i,j;
    while (scanf("%lld %lld",&m,&n) != EOF)
    {
      //  scanf("%lld %lld",&m,&n);
        if (m==0 && n==0) return 0;
        if (n>m) 
        {c = n; //m>n
         n = m;
         m = c;
        }
        row = (n*(n-1))*m;
        col = (m*(m-1))*n;
        dia =2* (((m-n+1)*n*(n-1) + (factorial(n-1)*2)));
        ans = row + col + dia ;
        printf("%lld\n",ans);
         
    }
}
