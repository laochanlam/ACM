
#include<cstdio>
#include<iostream>
using namespace std;

int main(){
    int i,j,k,n,s;
    int a[3] = {0};
    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        for (j=0;j<3;j++)
          scanf("%d",&a[j]);
        
        for (j=0;j<3;j++)
          for (k=j+1;k<3;k++)
        {
            if (a[k]>a[j])
            {
                s=a[k];
                a[k]=a[j];
                a[j]=s;
            }
        }
        printf("Case %d: %d\n",i,a[1]);
    }
}
