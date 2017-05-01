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
    while ( cin >> n >> m ) {
        if (n==0 && m==0) return 0;
        int ans = 0;
        memset (visit, 0, sizeof(visit));

        for (int i = 0; i < m; i++) {
            cin >> a >> b >> select;
            if (select == 1) {
                edge[a].push_back(b);
                edgerev[b].push_back(a);
            } else {
                edge[a].push_back(b);
                edge[b].push_back(a);
                edgerev[b].push_back(a);
                edgerev[a].push_back(b);
            }
        }
            
        
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


        for (int i = 0; i <= n; i++) {
            edge[i].clear();
            edgerev[i].clear();
            order.clear();
            SCC[i].clear();
        }
        if (counter > 1)
            cout<<"0"<<endl;
        else cout<< counter<<endl;
    }
}

