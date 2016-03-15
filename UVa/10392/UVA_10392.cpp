#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>

using namespace std;
bool a[1000000];

void prime(){
    int i,j;
    a[0] = false;
    a[1] = false;
    for (i=2;i<sqrt(1000000);i++)
        if (a[i])
            for (j=i+i;j<1000000;j=j+i)
            a[j] = false;       
}


int main(){
    long long int ans,count = 1;
    memset(a,true,sizeof(a));
    prime();
    while (scanf("%lld",&ans) != -1)
    {
        while (ans != 1)
        {

            while (a[count] && ans % count == 0) 
            {
                ans = ans / count;
                printf("    %lld\n",count);
            }
           count++;
            if (count >= 1000000-1)
            {
             
                printf("    %lld\n",ans);
                ans = 1;
            }       
        }
        count = 1;
        printf("\n");
    }
    return 0;
}
