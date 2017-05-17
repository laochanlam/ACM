#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int n,m,s,v;
int edge[150][150];

struct COOR {
    float x;
    float y;
};

int llink[150], rlink[150];
bool used[150];

bool DFS(int now) {
    for (int next = 0; next < m; next++) { //Every Route

        // for (int i = 0; i < m; i++)
        //     cout << used[i] << " ";
        // cout << endl;

        if (edge[now][next] == false || used[next])  continue;

        used[next] = true;
        if (rlink[next] == -1 || DFS(rlink[next])) {
            llink[now] = next;
            rlink[next] = now;
            return true;
        }
    }
    return false;
}


int main(){

    COOR gopher[150];
    COOR hole[150];
    int ans;

    while (cin >> n >> m >> s >> v) {
        for (int i = 0; i < n; i++)
            cin >> gopher[i].x >> gopher[i].y;
        for (int i = 0; i < n; i++)
            cin >> hole[i].x >> hole[i].y;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                if ((sqrt(pow(gopher[i].x - hole[j].x, 2) + pow(gopher[i].y - hole[j].y, 2))) / v <= s)
                    edge[i][j] = true;
                else
                    edge[i][j] = false;
            }

        ans = 0;
        memset(llink, -1, sizeof(llink));
        memset(rlink, -1, sizeof(rlink));
        for (int i = 0; i < n; i++) {
            memset(used, false, sizeof(used));
            if ( DFS(i) )
                ans++;
        }
        cout << n - ans << endl;
    }

}