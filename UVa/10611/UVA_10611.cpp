#include<cstdio>
#include<iostream>
using namespace std;

main(){
    int a[50000] ;
    int i,m;
    int n,time;
    int curr;
    int upper = 0,lower = 0;
    scanf("%d",&n);
    for (i=0;i<n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&m);
    for (i=0;i<m;i++)
    {
        scanf("%d",&curr);
        time = 0; upper = 0;lower = 0;
        while (time < n)
        {
            if (a[time] > curr)
            {
                upper = a[time];
                break;
            }
            if (a[time] < curr)
                lower = a[time];
            time ++;

        }
        if (lower == 0 && upper == 0)
            printf("X X\n");
        else {
                if (lower == 0)
                    printf("X %d\n",upper);
                if (upper == 0)
                    printf("%d X\n",lower);
                if (lower != 0 && upper != 0)
                    printf("%d %d\n",lower,upper);
            

             }
    }
}

