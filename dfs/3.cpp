#include <bits/stdc++.h>
using namespace std;

vector<int> visited;
vector<vector<int >> g;

void dfs(int start){
    visited[start] = 1;

    for(int i = 0 ; i < g[start].size();i++){
        int u = g[start][i];
        if(!visited[u]){
            dfs(u);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    g.assign(n,{});
    visited.assign(n,0);

    for(int i = 0 ; i < m ;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int s,t;
    cin >> s >> t;
    s--;
    t--;

    dfs(s);

    if(visited[t]){
        cout << "YES" << "\n";
    }else{
        cout << "NO" << "\n";
    }
    
    return 0;
}