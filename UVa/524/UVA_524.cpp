#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int prime[] = {2,3,5,7,11,13,17,19,23,29,31,37,41};
int a[21] = {0};
bool visit[21];
int n;


bool det(int ans);

void backtracking(int count){
    int i,j;
	if (count > n)
    {
    if (det(1+a[count-1]) == true)
	{
		printf("1");
		for (i=2;i<=n;i++)
			printf(" %d",a[i]);
        cout<<endl;
	}
        return;
    }
	
    for (i=2;i<=n;i++)
    	{

		if (det(i + a[count-1]) == true && visit[i] == false)
		{
            visit[i] = true;
			a[count] = i;
			backtracking(count+1);
            visit[i] = false; a[count] = 0;
		}   
	    }
        
}

bool det(int ans){
    int i;
	for (i=0;i<=12;i++)
		if (ans == prime[i]) return true;
	return false;
}


int main(){
	int i,j;
    int cases = 0;
	while (scanf("%d",&n)!=EOF)
	{
        if (cases != 0) cout<<endl;
        cases++;
        printf("Case %d:\n",cases);
		a[1] = 1;
        memset(visit,false,sizeof(visit));
        visit[1] = true;
		backtracking(2);
	}
}
