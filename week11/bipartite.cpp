#include <bits/stdc++.h>
using namespace std;

//bipartite graph в котором соседние вершины не имеют связи то есть только из точки а в б
//допустим у нас две группы {0,1} & {2,3}
// если есть коннект между 0 и 1 || 2 n 3
// то значит не двудольный граф

void dfs(vector<vector<int>> &g,vector<int> &color,int v,int c,bool &isBipa){
    color[v] = c;
    for(int i = 0 ; i < g[v].size();i++){
        int u = g[v][i];
        if(!color[u]){
            dfs(g,color,u,3-c,isBipa);
        }else if(color[u] == c){
             isBipa = false;
        }
    }
}




int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,a,b;
    cin >> n >> m;

    vector<vector<int>> g(n);
    vector<int> color(n,0);

    for(int i = 0 ; i < m ; i++){
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    bool isB = true;
    for(int i = 0 ; i < n ; i++){
        if(!color[i]){
            dfs(g,color,i,1,isB);
        }
    }

    if(isB)cout << "Bipartite";
    else cout << "No";

    return 0;
}