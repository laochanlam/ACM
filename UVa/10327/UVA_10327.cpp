#include<cstdio>
#include<iostream>
using namespace std;

int main(){
    int i,j;
    int count = 1;
    int n;
    int step = 0;
    int a[1001];
    while(scanf("%d",&n) != EOF)
    {
        
        for (i=1;i<=n;i++)
            scanf("%d",&a[i]);
        while (count < n)
        {
            
            if ( a[count]>a[count+1] )
            {
                j = a[count+1];
                a[count+1] = a[count];
                a[count] = j;
                step++;
                count = 0;
            }
            count++;
        }
        printf("Minimum exchange operations : %d\n",step);
        count = 0;
        step = 0;
    }
}
