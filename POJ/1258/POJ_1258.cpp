#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int s[100001];

int findS(int p) {
    if (s[p] == -1)
        return p;
    return findS(s[p]);
}

void unionS(int p,int q) {
    p = findS(p);
    q = findS(q);

    if (p != q) 
        s[p] = q;
}


typedef struct {
    int src;
    int dst;
    double dis;
} EDGE;

bool operator < (const EDGE &x, const EDGE &y) {
    return x.dis < y.dis;
}


int main(){
    int cases;
    int n,m;
    int A,B,cost;
    double distance;
    EDGE edge[100001];
    int  src,dst,route_counter;
    int c_counter = 0;
    long long int org_cost = 0;

    while ( cin >> n ) {
        c_counter++;
        memset(s, -1, sizeof(s));
        
        route_counter = 0;

        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++) {
                    cin >> cost;
                    edge[route_counter].src = i;
                    edge[route_counter].dst = j;
                    edge[route_counter].dis = cost;
                    route_counter++;
            }
            

        sort(edge,edge+route_counter);

    // for (int i = 0; i < route_counter; i++) 
    //     cout << edge[i].src << " " << edge[i].dst << " " << edge[i].dis << endl;
        
        long long int  finalans = 0;
        long long int k = 0;
        while (k < route_counter) {
            if ( findS(edge[k].src) != findS(edge[k].dst)) {
                finalans += edge[k].dis;
                unionS (edge[k].src, edge[k].dst);
            }
            k++;
        }
        cout << finalans << endl;
    }
}