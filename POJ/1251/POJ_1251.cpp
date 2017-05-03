#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
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
    int cost;
    string A,B;

    double distance;
    EDGE edge[100001];
    int  src,dst,route_counter;
    int c_counter = 0;
    int counter;

    long long int org_cost = 0;

    while (1) {
        cin >> n;
        if (n == 0) return 0;
        c_counter++;
        memset(s, -1, sizeof(s));
        
        route_counter = 0;

        for (int i = 0; i < n-1; i++) {
            cin >> A >> counter;
            for (int j = 0; j < counter; j++) {
                cin >> B >> cost;
                edge[route_counter].src = A[0]-'A';
                edge[route_counter].dst = B[0]-'A';
                edge[route_counter].dis = cost;
                route_counter++;
            }
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