#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int s[800];

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

struct COOR {
    int x;
    int y;
} coor[800];

int main(){
    int cases;
    int n,m;
    int A,B;
    double distance;
    EDGE edge[640000];
    int  src,dst,route_counter;

    while ( cin >> n ) {
        memset(s, -1, sizeof(s));
        for (int i = 1;i <= n; i++)
            cin >> coor[i].x >> coor[i].y;
        cin >> m;
        for (int i = 0;i < m; i++) {
            cin >> A >> B;
            unionS(A,B);
        }
        route_counter = 0;
        for (int i = 1; i <= n; i++)
           for (int j = i+1; j <= n; j++) {
                distance = sqrt( pow(abs(coor[i].x - coor[j].x),2) + pow(abs(coor[i].y - coor[j].y),2) );
                edge[route_counter].src = i;
                edge[route_counter].dst = j;
                edge[route_counter].dis = distance;
                route_counter++;
         }

        sort(edge,edge+route_counter);

    // for (int i = 0; i < route_counter; i++) 
    //     cout << edge[i].src << " " << edge[i].dst << " " << edge[i].dis << endl;
    
        int k = 0;
        bool flag = 0;
        double finalans = 0;
        while (k < route_counter) {
            if ( findS(edge[k].src) != findS(edge[k].dst)) {
                flag = 1;
                finalans +=edge[k].dis;
                unionS (edge[k].src, edge[k].dst);
            }
            k++;
        }
        printf("%.2lf\n",finalans);
        if (cases)
            cout << endl;


    }
}