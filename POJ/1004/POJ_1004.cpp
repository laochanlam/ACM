#include<cstdio>
#include<iostream>
using namespace std;

int main(){
    float a,b = 0;
    int i;
    for (i=0;i<12;i++)
    {
        scanf("%f",&a);
        b = b + a;
    }
	b = b / 12;
    printf("$%.2f",b);

}
