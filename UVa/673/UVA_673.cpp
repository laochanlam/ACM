
#include<iostream>
#include<stack>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main(){

    int n,i,k = 0;
    int count = 0;
    stack<char> stk;
    FILE *ifp,*ofp;
    char in[1];

    scanf("%d\n",&n);
    while (n > 0)
    {
        scanf("%c",&in[0]);
        
        if ( in[0] != '\n' && k == 0)
        {
            if ( in[0] == '('  ||  in[0] == '[')
                stk.push(in[0]);
            if ( in[0] == ')'  ||  in[0] == ']')
            {
                if (!stk.empty())
                {
                    if (in[0] == ')')
                        if ( stk.top() != '(' ) k++;
                    if (in[0] == ']')
                        if ( stk.top() != '[' ) k++;
                    stk.pop();
                }
                else 
                {
                    k++;
                }
            }
        }
        
        if ( in[0] == '\n' )
        {
            n--;
            if (k !=0 || !stk.empty())
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << "YES" << endl;
            }
            k = 0;
        }

    }



}
