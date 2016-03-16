#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

double p,q,r,s,t,u;


double formula(double x){
    double mid = p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*pow(x,2) + u;
    return mid;
}


int main(){

    double ans;
    double max = 1.0,min = 0.0,mid = (max + min) / 2;
    long long int count;
    while (scanf("%lf %lf %lf %lf %lf %lf",&p,&q,&r,&s,&t,&u)!=EOF)
    {
        max = 1.0; min = 0.0; count = 0;
        while (1)
        { 
            count ++;
            if (count > 500) 
            {
                printf("No solution\n");
                break;
            }
            //cout<<formula(mid)<<" ";
            mid = (max + min) / 2;
            //cout<<formula(mid)<<" ";
            if (abs(formula(mid)) < 0.0000001) break;
           //cout<<mid<<" ";
            if (formula(mid) < 0)
                max = mid;
            else
                min = mid;
        }
        if (count <= 500)
        printf("%.4lf\n",mid);
    }
}
