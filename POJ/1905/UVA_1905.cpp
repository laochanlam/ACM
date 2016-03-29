#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

int main(){
    double a,b,c,e,d,f,g,h;
    while (~scanf("%lf %lf %lf",&a,&b,&c))
    {
        if(a<0&&b<0&&c<0) break;
        d = 0; 
        e = (1+b*c)*a;
        f = a / 2;
        while (abs(f - d ) > 0.00001)
        {
            h = (f + d)/2;
            g = (a*a/4+h*h) / (2*h);
            if (asin(a/(2*g))*g < e/2) 
                d = h;
            else
                f = h;
        }
        printf("%.3f\n",h);
    }
    return 0;
}
