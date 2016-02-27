#include<cstdio>
#include<iostream>
using namespace std;

int main(){
    long long int n,count = 0,a,b;
    long long int flag = 0,qui=0,i;
    long long int max = 0;
    while (scanf("%lld %lld",&a,&b) != EOF)
    {
        if (a>b)
        {
            qui = a;
            a = b;
            b = qui;
            qui = 1;
        }
        for (i=a;i<=b;i++)
        {
            n = i;
            while (1)
            {
                if (n % 2 == 1 && n!=1)
                {
                    n = n * 3 + 1;
                    flag++;
                }
                else if (n % 2 == 0 && n!=1) 
                {
                    n = n / 2;
                    flag++;
                }
                if (n == 1) break;
            }
            flag++;
            if (flag > max)
              max = flag;
        

            flag = 0;
        }
        if (qui == 1){
        printf("%lld %lld %lld\n",b,a,max);}
        else{
        printf("%lld %lld %lld\n",a,b,max);}
        max = 0; qui= 0;
    }
    
}
