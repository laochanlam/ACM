#include <cstdio>  
#include <cstdlib>  
#include <iostream>
using namespace std;

int main(){
    int n,i;
    int a,b;
    float ans;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%d %d",&a,&b);
        if (a % 2 != 0 && b % 2 != 0)
        {
            ans = a*b+0.41;
        }
        else
        {
            ans = a * b;
        }
        printf("Scenario #%d:\n%.2f\n\n",i,ans);
    }
}
