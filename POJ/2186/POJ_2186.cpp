#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

bool visit[100001];
vector <int> edge[100001];
vector <int> edgerev[100001];
vector <int> order;
vector <int> SCC[100001];
int counter;

void dfs (int in) {
    visit[in] = true;
    for (int i = 0; i < edge[in].size(); i++)
        if (!visit[edge[in][i]]) 
            dfs(edge[in][i]);

order.push_back(in);
}

void revdfs (int in) {
    visit[in] = true;
    for (int i = 0; i < edgerev[in].size(); i++)
        if (!visit[edgerev[in][i]])
            revdfs(edgerev[in][i]);

SCC[counter].push_back(in);
}

int main(){
    int cases;
    int n,m,a,b;
    int select;

    string input;
        
        cin >> n >> m;
        int ans = 0;
        memset (visit, 0, sizeof(visit));

        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            edge[a].push_back(b);
            edgerev[b].push_back(a);
        }
        int finalans = 0;
        
        for (int i = 1; i <= n; i++)
            if (!visit[i]) 
                dfs(i);

        memset (visit, 0, sizeof(visit));
        counter = 0;

        for (int i = n-1; i >= 0; i--)
            if (!visit[order[i]]) {
                revdfs(order[i]);
                counter++;
            }

        int No = 0;
        int flag = 0;
        int sum = 0;
        for (int i = 0; i < counter; i++) {
            No = 0;
            for (int j = 0; j <SCC[i].size(); j++) {
                for (int k = 0; k < edge[SCC[i][j]].size(); k++) {
                    bool Inside = false;
                    for (int r = 0; r < SCC[i].size(); r++) {
                        if ( r != j )
                            if (edge[SCC[i][j]][k] == SCC[i][r])
                                Inside = true;
                    }
                    if (Inside == false)
                        No++;
                }
            }
            if (No == 0) {
                sum = SCC[i].size();
                flag ++;
            }
        }
        if (flag == 1)
            cout << sum ;
        else cout <<"0";

}

