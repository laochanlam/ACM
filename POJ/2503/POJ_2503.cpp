#include<map>
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

int main(){
    map<string,string> mapping;
    string A,B,C;
    int i,j,k;
    while (getline(cin,A))
    {
        if (A.length()==0) break;
        for (i=0;i<A.length();i++)
            if (A[i] == ' ')
            {
                for (j=i+1;j<A.length();j++)
                    B = B + A[j];
                for (k=0;k<i;k++)
                   C = C + A[k];
                break;
            }
        mapping[B] = C;
        B.clear(); C.clear();
    }


    
    while (getline(cin,A))
    {
        if (mapping[A].length()==0) cout<<"eh"<<endl;
        else cout<<mapping[A]<<endl;
    }
}
