#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;

char a[30][30][30];
int count[30][30][30] = {0};
int step = -1;

int BPS(int k,int i,int j,int &L,int &R,int &C){
    step++;
    count[k][i][j] = 1;
    if (a[k][i][j] == 'E') return step;
    if (a[k][i][j+1] == '.' && j+1<C && count[k][i][j+1] == 0)  //right
        BPS(k,i,j+1,L,R,C);
    if (a[k][i][j-1] == '.' && j-1>0 && count[k][i][j-1] == 0)  //left
        BPS(k,i,j-1,L,R,C);
    if (a[k][i-1][j] == '.' && i-1>0 && count[k][i-1][j] == 0)  //up
        BPS(k,i-1,j,L,R,C);
    if (a[k][i+1][j] == '.' && i+1<R && count[k][i+1][j] == 0)  //down
        BPS(k,i+1,j,L,R,C);
    if (a[k+1][i][j] == '.' && k+1<L && count[k+1][i][j] == 0)  //3Dup
        BPS(k+1,i,j,L,R,C);
    if (a[k-1][i][j] == '.' && k-1>0 && count[k-1][i][j] == 0)  //3Ddown
        BPS(k-1,i,j,L,R,C);

}

int main(){
    int i,j,k;
    int L,R,C;
    string useless; 
    int count = 0;
    while (1)
    {
        scanf("%d %d %d\n",&L,&R,&C);
        
        if (L == 0 && R == 0 && C == 0) break;
        
        for (k=0;k<L;k++)
        {
            for (i=0;i<R;i++)
                fgets(a[k][i],1024,stdin);
            getline(cin,useless);
        }

        
        for (k=0;k<L;k++)
            for (i=0;i<R;i++)
                 for (j=0;j<C;j++)
                    if (a[k][i][j] == 'S')
                        count = BPS (k,i,j,L,R,C);
    printf("%d",count);
    }
     
}
