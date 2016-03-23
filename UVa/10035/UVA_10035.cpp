#include<cstdio>
#include<iostream>
using namespace std;

int main(){
    int n,i,j,m;
    int ans,digit;
    while (1){
        scanf("%d %d",&n,&m);
        ans = 0; digit = 0;
    
        if (m == 0 & n == 0) return 0;
        while (m>0 || n>0)
        {
            digit = digit + (m % 10) + (n % 10);
            if (digit > 9) 
            {
                ans++; digit = digit/ 10;
            }
            else
                digit = 0;
            m = m / 10; n = n / 10;
        }   
        if (ans == 0) cout<<"No carry operation."<<endl;
        else if(ans == 1) cout<<"1 carry operation."<<endl;
        else 
            cout<<ans<<" carry operations."<<endl;
    }
}
