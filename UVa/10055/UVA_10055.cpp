
#include<iostream>
#include<cstdio>
using namespace std;

main(){
long long int a,b,ans,count = 0;
     while (scanf("%lld %lld",&a,&b) != EOF){
        if (a>b){
            ans = a-b;
        }
        else{
            ans = b-a;
        }
        printf("%lld\n",ans);
}
}
