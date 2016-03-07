#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;

int main(){
    int s,n,i,j = 0;
    int a[20000];
    int count = 0;
    scanf("%d %d",&n,&s);
    while (1)
    {
        n--;
        if (n<0) break;
        scanf("%d",&a[j]);
        j++;
    }
    sort(a,a+j);

    for (i=0;i<j;i++)
        for (n=i+1;n<j;n++)
            if (a[i] + a[n] <= s)
                count ++ ;
            else
                break;
    cout<<count;
}
