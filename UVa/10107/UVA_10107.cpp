#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    long long int a[10000];
    int count = 0;
    long long int ans;
    int i;
    while (scanf("%lld",&a[count])!=EOF)
    {
        sort(a,a+count+1);
        
        if (count % 2 == 0)
        {
            ans = count / 2;
            printf("%lld\n",a[ans]);
        }
        else 
        {
            ans = (a[count/2] + a[count/2+1]) / 2;
            printf("%lld\n",ans);
        }
        count++;
        }
}
