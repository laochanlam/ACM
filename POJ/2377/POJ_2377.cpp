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
    return x.dis > y.dis;
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

        cin >> n >> m;
        c_counter++;
        memset(s, -1, sizeof(s));
        
        route_counter = 0;

        for (int i = 0; i < m; i++) {
            cin >> A >> B >> cost;
            edge[i].src = A;
            edge[i].dst = B;
            edge[i].dis = cost;
        }

        sort(edge,edge+m);

    // for (int i = 0; i < m; i++) 
    //     cout << edge[i].src << " " << edge[i].dst << " " << edge[i].dis << endl;
        
        long long int  finalans = 0;
        long long int k = 0;
        while (k < m) {
            if ( findS(edge[k].src) != findS(edge[k].dst)) {
                finalans += edge[k].dis;
                unionS (edge[k].src, edge[k].dst);
                route_counter++;
            }
            k++;
        }
        if ( route_counter == n-1 )
            cout << finalans;
        else
            cout << "-1";
}