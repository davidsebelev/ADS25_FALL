#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
vector<vector<int>> a(MAXN);vector<int> visited(MAXN);

void dfs(int v){
    visited[v] = 1;

    for(int i = 0 ; i < a[v].size();i++){
        int u = a[v][i];

        if(visited[u] == 0){
            dfs(u);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}