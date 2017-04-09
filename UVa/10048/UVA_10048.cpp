#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[10001][10001];

int main(){
    int C,S,Q;
    int source,destination;
    int start,end,cost;
    int c_counter = 0;

    while (1) {
        c_counter++;
        cin >> C >> S >> Q;
        if ( C==0 && S==0 && Q==0 ) return 0;
        if (c_counter > 1)
            cout<<endl;
        for (int i = 1; i <= C; i++) {
            for (int j = 1; j <= C; j++)
                a[i][j] = 99999;
            a[i][i] = 0;
        }

        for (int i = 0; i < S; i++) {
                cin >> start >> end >> cost;
                a[start][end] = cost;
                a[end][start] = cost;
            }

        for (int k = 1; k <= C; k++)
            for (int i = 1; i <=C; i++)
                for (int j = 1; j <=C; j++)
                    a[i][j] = min(max(a[i][k],a[k][j]),a[i][j]);

        // for (int i = 1; i <= C; i++) {
        //     for (int j = 1; j <=C; j++)
        //         cout<<a[i][j]<<" ";
        //     cout<<endl;
        // }
        cout<< "Case #"<<c_counter<<endl;
        for (int i = 0; i < Q; i++) {
            cin >> source >> destination;
            if (a[source][destination] != 99999)
                cout <<a[source][destination]<<endl;
            else
                cout <<"no path"<<endl;
        }
    }
}
