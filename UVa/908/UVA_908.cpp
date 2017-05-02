#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int s[1000001];

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
    int n,m,k;
    int A,B,cost;
    double distance;
    EDGE edge[1000001];
    int  src,dst,route_counter;
    int c_counter = 0;
    long long int org_cost = 0;

        while ( cin >> n ) {
        org_cost = 0;  
        c_counter++;

        for (int i = 0; i < n-1; i++) {
            cin >> A >> B >> cost;
            org_cost +=cost;
        }
        
        cin >> k;

        memset(s, -1, sizeof(s));
        
        route_counter = 0;

        for (int i = 0; i < k; i++) {
            cin >> A >> B >> cost;
            edge[route_counter].src = A;
            edge[route_counter].dst = B;
            edge[route_counter].dis = cost;
            route_counter++;
        }

        k = 0;
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> A >> B >> cost;
            edge[route_counter].src = A;
            edge[route_counter].dst = B;
            edge[route_counter].dis = cost;
            route_counter++;
         }

        sort(edge,edge+route_counter);

    // for (int i = 0; i < m; i++) 
    //     cout << edge[i].src << " " << edge[i].dst << " " << edge[i].dis << endl;
        if (c_counter != 1) cout << endl;
        bool flag = 0;
        long long int  finalans = 0;
        while (k < route_counter) {
            if ( findS(edge[k].src) != findS(edge[k].dst)) {
                flag = 1;
                finalans += edge[k].dis;
                unionS (edge[k].src, edge[k].dst);
            }
            k++;
        }
        cout << org_cost << endl << finalans << endl;
        }
}