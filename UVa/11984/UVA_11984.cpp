#include<cstdio>
#include<iostream>
using namespace std;

int main(){
    int i,j,n;
    float a,b;
    scanf("%d",&n);
    for (i=1;i<=n;i++){
        scanf("%f %f",&a,&b);
        a = (a*9/5)+32;
        b = b+a;
        b = (b-32)*5/9;
        printf("Case %d: %.2f\n",i,b);
    }
}
