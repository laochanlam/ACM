#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;


int main(){
    int a[10000];
    int n,i;
    scanf("%d",&n);
    for (i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    printf("%d",a[n/2]);
}
