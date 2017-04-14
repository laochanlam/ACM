#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

struct PATH {
    int source;
    int destination;
    int cost;
    bool bidirectional;
} path[3000];

int dis[3000];
int main(){
    int cases = 0;
    int path_counter;
    int n,m,w;
    int costs;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        path_counter = 0;
        cin >> n >> m >> w;
        for (int j = 0; j < m ; j++) {
            cin >> path[path_counter].source >> path[path_counter].destination >> path[path_counter].cost;
            path[path_counter].bidirectional = true;
            path_counter++;
        }

        for (int j = 0; j < w; j++) {
          cin >> path[path_counter].source >> path[path_counter].destination >> costs;
          path[path_counter].cost = -costs;
          path[path_counter].bidirectional = false;
          path_counter++;
        }

        dis[1] = 0;
        for (int i = 2; i < n; i++)
            dis[i] = 99999;

        for (int j = 0; j < n-1; j++)
            for (int k = 0; k < path_counter; k++) {
                if (path[k].bidirectional) {
                    dis[path[k].destination] = min (dis[path[k].destination],dis[path[k].source] + path[k].cost);
                    dis[path[k].source] = min (dis[path[k].source],dis[path[k].destination] + path[k].cost);
            } else {
                  dis[path[k].destination] = min (dis[path[k].destination],dis[path[k].source] + path[k].cost);
            }
        }

        int change_value;
        bool change = 0;
        for (int k = 0; k < path_counter; k++) {
            if (path[k].bidirectional) {
                change_value = min (dis[path[k].destination],dis[path[k].source] + path[k].cost);
                if ( change_value != dis[path[k].destination] )
                    change = 1;
                change_value = min (dis[path[k].source],dis[path[k].destination] + path[k].cost);
                if ( change_value != dis[path[k].source] )
                    change = 1;
            } else {
                change_value = min (dis[path[k].destination],dis[path[k].source] + path[k].cost);
                if ( change_value != dis[path[k].destination] )
                    change = 1;
            }
       }

       if (change)
           cout <<"YES"<<endl;
       else
           cout <<"NO"<<endl;
    }
}
