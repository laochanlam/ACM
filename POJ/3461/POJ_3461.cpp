#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;


int ans = 0;

void fail(string B,int *pi){
    int len = B.length();
    pi[0] = -1;
    int cur_pos = -1;
    for (int i=1;i<len;++i)
    {
        while (cur_pos >=0 && B[i] != B[cur_pos+1]) cur_pos = pi[cur_pos];
        if (B[i] == B[cur_pos+1]) ++cur_pos;
        pi[i] = cur_pos;
    }

   //  for (int i=0;i<len;++i)
   //     cout<<pi[i]<<' ';
}

void match(string A,string B,int *pi){
    int lenA = A.length();
    int lenB = B.length();
    for (int i=0,cur_pos = -1;i<lenA;++i)
    {
        while (cur_pos>=0 && A[i] != B[cur_pos+1])
            cur_pos=pi[cur_pos];
        if (A[i] == B[cur_pos+1]) ++cur_pos;
        if (cur_pos+1 == lenB)
        {
            cur_pos = pi[cur_pos];
            ans ++;
        }
    }
}

int main(){
    int n;
    int i,j;
    string A,B;
    int pi[1000000];

    scanf("%d\n",&n);
    for (i=0;i<n;i++)
    {
        memset(pi,-1,sizeof(pi));
        getline(cin,A);
        getline(cin,B);
        fail(A,pi); 
        match(B,A,pi);
        cout<<ans<<endl;
        ans = 0;
        A.clear();  B.clear();
    }   
}
