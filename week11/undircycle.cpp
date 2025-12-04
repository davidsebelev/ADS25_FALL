

// нахождение цикла в undir 
// если мы идем из u -> v && v->u то это окей так как нет направления у ребра
// но если мы идем из вершины в другую и видим след вершину которая не наш родитель но цикл найден


#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &g,vector<int> &visited,int v,bool &hasCycle,int from){
    visited[v] = 1;
    for(int i = 0 ; i < g[v].size();i++){
        int u = g[v][i];

        if(u == from){
            continue;
        }
        else if(!visited[u]){
            dfs(g,visited,u,hasCycle,v);
        }else if(visited[u] == 1){
            hasCycle = true;
        }
    }
    visited[v] = 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    

    int n,m,a,b;
    cin >> n >> m;

    vector<int> visited(n,0);
    vector<vector<int>> g(n);

    for(int i = 0 ; i < m ;i++){
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    bool hasCycle = false;
    for(int i = 0 ; i < n ;i++){
        if(!visited[i]){
            dfs(g,visited,i,hasCycle,-1);
        }
    }

    if(hasCycle)cout << "YES";
    else cout << "NO";
    return 0;
}