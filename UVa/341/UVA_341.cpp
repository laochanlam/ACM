#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct Route {
    int end[100];
    int cost[100];
    int numofRoute;
} route[11];

int dis[11];
int pre[11];

void forPrint(int n){
    if ( n == 0)
        return;
    else
        forPrint(pre[n]);

    printf(" %d",n);
}
int main(){
    int n,num;
    int source,destination;
    int c_counter = 0;
    int tracking;
    while (1) {
        cin >> n;
        c_counter++;
        if ( n == 0 ) return 0;
        for (int i = 1; i <= n; i++) {
            dis[i] = 999999;
            pre[i] = 0;
            cin >> route[i].numofRoute;
            for (int j = 0; j < route[i].numofRoute; j++) {
                cin >> route[i].end[j];
                cin >> route[i].cost[j];
            }
        }
        cin >> source >> destination;
        dis[source] = 0;

        for (int i = 0; i < n-1; i++) {
            for (int j = 1; j <= n; j++) {
              for (int k = 0; k < route[j].numofRoute; k++) {
                  if ( (dis[j] + route[j].cost[k]) < dis[route[j].end[k]] ) {
                      dis[route[j].end[k]] = dis[j] + route[j].cost[k];
                      pre[route[j].end[k]] = j;
                  }
              }
            }
        }

        printf("Case %d: Path =",c_counter);
        tracking = destination;
        forPrint(destination);
        printf("; %d second delay\n",dis[destination]);

    }
}
