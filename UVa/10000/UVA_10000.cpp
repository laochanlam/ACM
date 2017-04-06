#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Path {
    int start;
    int end;
} path[100000];

int dis[100000];

int main(){
    int n;
    int starting_point;
    int path_num;
    int c_counter = 0;
    while ( cin >> n ) {
        c_counter++;
        if ( n == 0 ) return 0;
        path_num = 0;
        cin >> starting_point;
        while(1) {
            cin >> path[path_num].start;
            cin >> path[path_num].end;
            if (path[path_num].start == 0 && path[path_num].end == 0)
                break;
            path_num++;
        }
        // cout << path[0].start << path[0]
            for (int i = 1; i <= n; i++)
                dis[i] = 999999;
            dis[starting_point] = 0;

            for (int i = 1; i <= n-1; i++)
                for (int j = 0; j < path_num; j++) {
                    dis[path[j].end]  = min(dis[path[j].start] - 1, dis[path[j].end]);
                    // cout << "fuck:"<<path[j].end<<endl;
                }
            int longest_path = 0;
            int destination;
            // cout << path_num<<endl;
            // for (int i = 1; i <= n; i++)
            //     cout<<dis[i]<<" ";
            for (int i = n; i >= 1; i--) {
                if (longest_path >= dis[i]) {
                    longest_path = dis[i];
                    destination = i;
                }
            }
            printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",
                   c_counter,starting_point,-longest_path,destination);
    }

}
