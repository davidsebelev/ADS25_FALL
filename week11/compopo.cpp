#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g,g_r;
vector<int> vis;
vector<int> comp,order;

void dfs1(int v){
    vis[v] = 1;
    for(auto to: g[v]){
        if(!vis[to])dfs1(to);
    }
    order.push_back(v);
}

void dfs2(int v ,int c){10
    comp[v] = c;
    for(auto to: g_r[v]){
        if(!comp[to])dfs2(to,c);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,a,b;
    cin >> n >> m;

    g.assign(n,{});
    g_r.assign(n,{});
    vis.assign(n,0);
    comp.assign(n,0);


    for(int i = 0 ; i < m ; i++){
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g_r[b].push_back(a);
    }

    for(int i = 0 ; i < n ; i++){
        if(!vis[i])dfs1(i);
    }

    reverse(order.begin(),order.end());

    int cnt = 0;
    for(int v : order){
        if(!comp[v]){
            cnt++;
            dfs2(v,cnt);
        }
    }

    for(auto i : comp)cout << i << " ";



    
    return 0;
}