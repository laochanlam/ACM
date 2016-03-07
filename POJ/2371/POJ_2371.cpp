#include<algorithm>
#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int main(){
    int n,i;
    int c;
    int a[100001];
    string shit;
        scanf("%d",&n);
    for (i=1;i<=n;i++)
        scanf("%d\n",&a[i]);
    sort(a+1,a+n+1);
    getline(cin,shit);
    
    scanf("\n%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%d",&c);

        printf("%d\n",a[c]);
    }   
}
