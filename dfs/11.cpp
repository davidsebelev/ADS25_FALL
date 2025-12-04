#include <bits/stdc++.h>
using namespace std;

vector<int> getCycle(vector<int> &from, int lastV){
    vector<int> cycle = {lastV};
    for(int i = from[lastV]; i != lastV; i = from[i]){
        cycle.push_back(i);
    }
    reverse(cycle.begin(),cycle.end());
    return cycle;

}

void dfs(vector<vector<int>> &g,vector<int> &visited,int v,
vector<int> &from , vector<int> &cycle){
    visited[v] = 1;
    for(int i = 0 ; i < g[v].size();i++){
        int u = g[v][i];
        if(from[v] == u)continue;
        else if(visited[u] == 0){
            from[u] = v;
            dfs(g,visited,u,from,cycle);
            if(!cycle.empty())return;
        }else if(visited[u] == 1){
            from[u] = v;
            cycle = getCycle(from,u);
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
    vector<int> cycle;
    vector<int> from(n,-1);

    for(int i = 0 ; i < m ;i++){
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
    }

    for(int v = 0 ; cycle.empty() && v < n;v++){
        if(!visited[v]){
            dfs(g,visited,v,from,cycle);
        }
    }

    if(!cycle.empty())
        {cout << "YES\n";
        for(int v : cycle){
            cout << v +1 << " ";
        }}
    else cout << "NO";


    return 0;
}