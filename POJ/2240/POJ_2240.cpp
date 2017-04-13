#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

double table[1000][1000];

int main(){
    map <string,int> data;
    int n,m;
    string input;
    string source,destination;
    double rate;
    int c_counter = 0;
    while (1) {
        c_counter++;
        cin >> n;
        if ( n == 0 ) return 0;
        for (int i = 0; i < n; i++) {
            cin >> input;
            data[input] = i;
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if ( i == j )
                    table[i][j] = 1;
                else
                    table[i][j] = -99999;

        cin >> m;

        for (int i = 0; i < m; i++) {
            cin >> source >> rate >> destination;
            table[data[source]][data[destination]] = rate;
        }
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    table[i][j] = max (table[i][k] * table[k][j], table[i][j]);

        bool flag = false;
        for (int i = 0; i < n; i++)
            if ( table[i][i] > 1.0 )
                flag = true;

        if ( flag )
            printf("Case %d: Yes\n",c_counter);
        else
            printf("Case %d: No\n",c_counter);
    }
}
