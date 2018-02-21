#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstdbool>
#include <cstring>
using namespace std;

char a[100][100];
bool visit[100][100];
int m, n;

void dfs(int i ,int j) {
    // for (int x = 0; x < n; x++) {
    //     cout << endl;
    //     for (int y = 0; y < m; y++)
    //         cout << visit[x][y];
    // }
    // cout << endl;
    for (int dx = -1; dx <= 1; dx++)
        for (int dy = -1; dy <= 1; dy++) {
            if (!(dx == 0 && dy == 0)) // cannot be itself
                if (dx + i < n && dx + i >= 0 && dy + j < m && dy + j >= 0)
                    if (a[dx + i][dy + j] == '@') 
                        if (!visit[dx + i][dy + j]) {
                            visit[dx + i][dy + j] = 1;
                            dfs(dx + i, dy + j);

                    }
        }
}


int main(){
    char c;
    while (1) {
        int ans = 0;
        cin >> n >> m;
        if ( !n && !m ) return 0;
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++)
                cin >> a[i][j];

        // for (int i = 0; i < n; i++) {
        //     printf("\n");
        //     for (int j = 0; j < m; j++)
        //         cout << a[i][j];
        // }
        memset(visit, 0, sizeof(visit));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (a[i][j] != '*' && !visit[i][j]) {
                    dfs(i, j);
                    ans ++;
                }



        cout << ans << endl;
    }
}