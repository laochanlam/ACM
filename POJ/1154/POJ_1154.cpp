#include<string>
#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;

char a[20][20];
bool visit[26];
int dr[4] = {0,0,1,-1};//right left up down
int dc[4] = {1,-1,0,0};
int ans = 0;
int r,c;

bool detect(){

}

void DFS(int curr,int curc,int dep){
    int i;
    //printf("%d ",a[curr][curc]-'A') ;
    visit[a[curr][curc]-'A'] = false;
    if (dep > ans) ans = dep;
    for (i=0;i<4;i++)
    {
    int newr = curr + dr[i];
    int newc = curc + dc[i];
    if (visit[a[newr][newc]-'A'] == true && newr<r && newr>=0 && newc<c && newc>=0)
        DFS(newr,newc,dep+1);
    }
    visit[a[curr][curc]-'A'] = true;
        
}




int main(){
    int i,j;
    while (scanf("%d %d\n",&r,&c)!=EOF)
    {
        for (i=0;i<r;i++)
            fgets(a[i],1024,stdin);
        memset(visit,true,sizeof(visit));
       /* for (i=0;i<r;i++)
        {
            for (j=0;j<c;j++)
        {
            cout<<a[i][j]<<" ";
        }
            cout<<endl;
        } */

        DFS(0,0,1);
        cout<<ans;
    }
}
