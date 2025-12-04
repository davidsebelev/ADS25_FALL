#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &g, vector<int> &vis,int v,stack<int> &res){
    vis[v] = 1;
    for(int to: g[v]){
        if(!vis[to]){
            dfs(g,vis,to,res);
        }
    }

    res.push(v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,a,b;
    cin >> n >> m;

    vector<vector<int>> g(n);
    vector<int> vis(n,0);
    stack<int> res;

    for(int i = 0 ; i < m ;i++){
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
    }

    for(int i = 0 ; i < n ; i++){
        if(!vis[i])dfs(g,vis,i,res);
    }

    while(!res.empty()){
        cout << res.top() << " ";
        res.pop();
    }



    
    return 0;
}