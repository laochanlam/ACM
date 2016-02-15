#include <cstdio>
#include<iostream>
using namespace std;

char a[201][201];
int win = 0;

void DFS(int ca,int i,int j,int &n){
    int k,l;
    if (ca == 1) //black
    {
        a[i][j]='.';
    
        if ( i+1<=n-1 )
            if ( a[i+1][j] == 'b' )
                DFS(1,i+1,j,n);

        if ( i+1<=n-1 && j+1<=n-1 )
            if ( a[i+1][j+1] == 'b' )
                DFS(1,i+1,j+1,n);
        
        if ( j+1 <= n-1 )
            if ( a[i][j+1] == 'b' )
                DFS(1,i,j+1,n);

        if  ( j-1 >= 0)
            if (a[i][j-1] == 'b')
                DFS(1,i,j-1,n);
        
        
       // if (i == n-1 )
       // {
        cout<<endl;
        
        for (k=0;k<n;k++)
        {
            cout<<endl;
            for (l=0;l<n;l++)
                cout<<a[k][l];
        }
            if (i == n-1 )
            {
            win = 1; //black
            return ;

            }
     //   }

        
    }

/*    if (ca == 2) //white
    {
        
    }*/
}

int main(){
    int i,j,m,n;
    int count = 0;
    freopen("input.in","rt",stdin);
    
    while (scanf("%d\n",&n))
    {
        if (n == 0) break;
        count++;
        cout<<count<<' ';
        for (i=0;i<n;i++)
            fgets(a[i],9999999,stdin);
        
        for (j=0;j<n;j++)
            if (a[0][j] == 'b')  
                DFS(1,0,j,n);

        if (win == 1)
            cout<<'B';
        win = 0;
        cout<<endl;

/*        for (i=0;i<n;i++)
            if (a[i][0] == 'w')
                DFS(2,i,j,n); */

        
       
    }

}
