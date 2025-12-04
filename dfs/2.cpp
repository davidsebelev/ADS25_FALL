#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > g;
vector<int> visited;

void dfs(int s){
    visited[s] = 1;
    cout << s << " ";

    for(int i = 0 ;i < g[s].size();i++){
        int u = g[s][i];
        if(!visited[u]){
            dfs(u);
        }
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,s;
    cin >> n >> m;

    g.assign(n,{});
    visited.assign(n,0);

    for(int i = 0 ; i < m ;i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    cin >> s;
    s--;
    dfs(s);



    
    return 0;
}