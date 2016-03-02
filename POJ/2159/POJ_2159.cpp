#include<string>
#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    string a,b;
    int acount[27] = {0},bcount[27]  = {0};
    int i,flag = 0;

    getline(cin,a);
    getline(cin,b);

    for (i=0;i<a.length();i++)
        acount[a[i]-'A'+1]++;

    for (i=0;i<b.length();i++)
        bcount[b[i]-'A'+1]++;

    sort(acount+1,acount+27); sort(bcount+1,bcount+27);
    for (i=1;i<=26;i++)
    {
        if ( acount[i] != bcount[i])
            flag = 1;
    }

    if (flag == 1) printf("NO");
    else printf("YES");
}
