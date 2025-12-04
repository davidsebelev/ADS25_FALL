#include <bits/stdc++.h>
using namespace std;
 
void dfs(vector<vector<int>> &g,int v,vector<int> &visited){
    visited[v] = 1;
    for(int i = 0 ; i < g[v].size();i++){
        int u = g[v][i];
        if(!visited[u]){
            dfs(g,u,visited);
        }
    }
}

int compCount(vector<int> &visited,vector<vector<int>> &g){
    int cnt = 0;
    for(int i = 0 ; i < visited.size();i++){
        if(!visited[i]){
            dfs(g,i,visited);
            cnt++;
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,a,b;
    cin >> n >> m;

    vector<vector<int>> g(n);
    vector<int> visited(n,0);

    for(int i = 0 ; i < m ; i++){
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    cout << compCount(visited,g);

    // 0 1
    // 1 2
    // 4 5я 


    
    return 0;
}