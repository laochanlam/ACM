#include<cstdio>
#include<iostream>
using namespace std;

int poss[7490];
int bit[5] ={1,5,10,25,50};

void table(){
    for(int k=0;k<=7489;k++)
        poss[k]=0;
    poss[0] = 1;
    
    for (int i=0;i<5;i++)
        for (int j=bit[i];j<=7489;j++)
        if (poss[j-bit[i]] >= 1) poss[j] += poss[j-bit[i]];

}


int main(){
    int n,i,j;
    table();
    while (scanf("%d",&n)!=EOF)
    {
        cout<<poss[n]<<endl;

    }
}
