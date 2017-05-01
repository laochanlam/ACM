#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

bool visit[100];
vector <int> edge[100];
vector <int> edgerev[100];
vector <int> order;
string limit;

void dfs (int in) {
    visit[in] = true;

    for (int i = 0; i < edge[in].size(); i++)
        if (!visit[edge[in][i]]) 
            dfs(edge[in][i]);

    order.push_back(in);
}


int main(){
    int n;
    string input;
    cin >> n;
    getchar();
    getchar();
    for (int k = 0; k < n; k++) {
        int ans = 0;
        getline(cin, limit);
        // cout << limit << endl;
        memset (visit, false, sizeof(visit));
        while (1) {
            getline (cin, input);
            if (input.size() == 0) break;
            // cout << input[0]-'A' << endl;
            edge[input[0]-'A'].push_back(input[1]-'A');   
            edge[input[1]-'A'].push_back(input[0]-'A');  // graph built
        }
        
        for (int i = 0; i <= limit[0]-'A'; i++)
            if (!visit[i]) {
                ans++;
                dfs(i);
            }

        for (int i = 0; i <= limit[0]-'A'; i++) 
            edge[i].clear();

        //     for (int j = 0; j < edge[i].size(); j++)
        //         cout << edge[i][j];
        //     cout << endl;
        // }    

        // cout <<endl << endl;
        // for (int i = 0; i < order.size(); i++) 
        //     cout << order[i] << endl;

        cout << ans << endl;
        if (k != n-1)
            cout <<endl;
    }
}

