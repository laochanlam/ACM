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
string limit;
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
            dfs(edgerev[in][i]);

    SCC[counter].push_back(in);
}

int main(){
    int cases;
    int n,m,a,b;

    string input;
    cin >> cases;
    for (int k = 0; k < cases; k++) {
        int ans = 0;
        memset (visit, 0, sizeof(visit));
        cin >> n >> m;

        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            edge[a].push_back(b);
            edgerev[b].push_back(a);
        }
            
        
        for (int i = 1; i <= n; i++)
            if (!visit[i]) 
                dfs(i);

        memset (visit, 0, sizeof(visit));
        counter = 0;

        for (int i = n-1; i >= 0; i--)
            if (!visit[order[i]]) {
                dfs(order[i]);
                counter++;
            }

        // for (int i = 1; i <= n; i++) {
        //     for (int j = 0; j < edge[i].size(); j++)
        //         cout << edge[i][j];
        //     cout << endl;
        // }    


        for (int i = 0; i <= n; i++) {
            edge[i].clear();
            edgerev[i].clear();
            order.clear();
            SCC[i].clear();
        }
        cout<<"Case "<<k+1<<": "<<counter<<endl;
    }
}

