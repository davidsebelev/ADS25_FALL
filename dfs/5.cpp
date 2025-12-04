#include <bits/stdc++.h>
using namespace std;

vector<int> v;
vector<vector<int> > g;

void dfs(int s,int comp){
    v[s] = comp;
    for(int i = 0 ; i < g[s].size();i++){
        int u = g[s][i];
        if(!v[u])dfs(u,comp);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    g.assign(n,{});
    v.assign(n,0);

    for(int i = 0 ; i < m ;i++){
        int x,y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int compcnt = 0;
    for(int i = 0 ; i < n;i++){
        if(!v[i]){
            compcnt++;
            dfs(i,compcnt);
        }
    }
    for(auto i : v)cout << i << " ";

    
    return 0;
}