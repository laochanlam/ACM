#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

int main(){
    string in;
    int i;
    while (1)
    {
        getline(cin,in,'\n');
        
        
        if (in == "ENDOFINPUT") break;
        
        if (in == "START")
        {
            getline(cin,in,'\n');
            for (i = 0; i < in.length(); i++)
            {
                if (in[i] >='A' && in[i] <= 'Z')
                {
                    in[i] = in[i]+21;
                    if (in[i] >'Z')  in[i] = in [i] - 26;
                }
            cout<<in[i];
            }
        cout<<endl;
        }
        
        in.clear();
    }    
    
    
}
