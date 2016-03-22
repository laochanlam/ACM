#include<cstdio>
#include<iostream>
using namespace std;

int main(){
    long long int a,b,c,d;
    double n;
    long double ab,cd;

    while (scanf("%lld %lld",&a,&b)!=EOF)
    {
        scanf("%lf",&n);
        ab = (long double)a/b;
        c = 0; d = 0;
        while (1)
        {
            d++;
            c =(long long int)(ab * d);
            cd = (long double)c/d;
            while (a*d >= b*c)
                c++;
            cd = (long double)c/d;
            if (cd - ab <= n)
            {
                printf("%lld %lld\n",c,d);
                break;
            }
        }
    }
}
