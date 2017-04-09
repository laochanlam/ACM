#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Path {
    int start;
    int end;
    int cost;
} path[10001];

int dis[10001];

int main(){
    int C,S,Q;
    int source,destination;
    while (1) {
        cin >> C >> S >> Q;
        if ( C==0 && S==0 && Q==0 ) return 0;
        for (int i = 0; i < S; i++)
            cin >> path[i].start >> path[i].end >> path[i].cost;
        for (int i = 0; i < Q; i++) {
            cin >> source >> destination;
            for (int j = 1; j <= C; j++)
                dis[j] = 99999;
            dis[source] = 0;
            for (int j = 0; j < C-1; j++)
                for (int k = 0; k < S; k++) {
                    dis[path[k].end] =  min ( (dis[path[k].start] + path[k].cost), dis[path[k].end] );
                    dis[path[k].start] =  min ( (dis[path[k].end] + path[k].cost), dis[path[k].start] );
                    // cout<<(dis[path[k].start] + path[k].cost)<<endl;
            for (int j = 1; j <=C; j++)
                cout << dis[j]<<" ";

            cout<<endl;
          }
        }
    }
}
