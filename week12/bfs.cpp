#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;

vector<int> used(MAXN,0);
queue<int> q;
vector<vector<int>> g(MAXN);

void bfs(int v){
    used[v] = 1;
    q.push(v);
    while(!q.empty()){
        int s = q.front();
        q.pop();

        for(int i = 0 ; i < g[s].size();i++){
            int u = g[s][i];
            if(!used[u]){
                used[u] = true;
                q.push(u);
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}