#include<cstdlib>
#include<cstdio>
#include<string>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;

int main(){
    string a,b;
    string prt;
    int i,j,k;
    int count[27];
    int count2[27];
    while (getline(cin,a))
    {
        getline(cin,b);
        memset(count,0,sizeof(count));
        memset(count2,0,sizeof(count2));
        //sort(a.begin(),a.end());
        //sort(b.begin(),b.end());
    
        for (i=0;i<a.length();i++)
            count[a[i]-'a'+1]++;
        for (i=0;i<b.length();i++)
            count2[b[i]-'a'+1]++;

        for (i=1;i<27;i++)
            count[i] = min(count[i],count2[i]);

        /*for (i=1;i<27;i++)
            cout<<count[i]<<" ";*/


        for (i=1;i<27;i++)
            if (count[i] > 0)
                for (j=0;j<count[i];j++)
                    printf("%c",i+'a'-1);
        
        cout<<endl;
    
    }
}
