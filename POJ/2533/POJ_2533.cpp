#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;


int main(){
    int length[1000];
    int a[1000];
    int i,j,n;
    int maxx;
    scanf("%d",&n);

    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        length[i] = 1;
    }

    for (i=0;i<n;i++)
        for (j=i+1;j<n;j++)
            if (a[i] < a[j])
                length[j] = max (length[j],length[i]+1);
  
    
    
    maxx = 0;
    for (i=0;i<n;i++)
    {
        maxx = max(maxx,length[i]);
    
    }

    cout<<maxx;



}
