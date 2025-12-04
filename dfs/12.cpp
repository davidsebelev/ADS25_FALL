#include <bits/stdc++.h>
using namespace std;



void dfs(vector<vector<int>> &g,vector<int> &visited,int v,int color, bool &isBipartite){
    visited[v] = color;
    for(int i = 0 ; i < g[v].size();i++){
        int u = g[v][i];
        if(!visited[u]){
            dfs(g,visited,u,3-color,isBipartite);
        }else if(visited[u] == color){
            isBipartite = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,x,y;
    cin >> n >> m;

    vector<vector<int>> g(n);
    vector<int> visited(n,0);

    for(int i = 0 ; i < m ;i++){
        cin >> x >> y;
        x--;y--;
        g[x].push_back(y);
        g[y].push_back(x);

    }

    bool isBipartite = true;
    for(int i = 0 ; i < n ; i++){
        if(!visited[i]){
            dfs(g,visited,i,1,isBipartite);
        }
    }

    if(isBipartite){
        cout << "YES\n";
        for(auto i : visited)cout << i << " ";
    }else{
        cout << "NO\n";
    }


    
    return 0;
}