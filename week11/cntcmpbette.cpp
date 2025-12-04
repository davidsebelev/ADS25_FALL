#include <bits/stdc++.h>
using namespace std;

// ищет так же компонеты связности 
// компоненты связности это когда одна вершина свзяана с другой ребром
// кол-во компонент свяностей это количество различных связей по типу
// 0-1-2 этоа одна компонента связности
// 4-5 это уже другая
// суть кода в том что мы нумеруем вершину ее компонентой связности , т.e какая она по счету

void dfs(vector<vector<int>> &g , int v, vector<int> &visited,int compCnt){
    visited[v] = compCnt;
    for(int i = 0 ; i < g[v].size();i++){
        int u = g[v][i];
        if(!visited[u]){
            dfs(g,u,visited,compCnt);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,a,b;
    cin >> n >> m;

    vector<vector<int>> g(n);
    vector<int> visited(n,0);


    for(int i = 0 ; i < m; i++){
        cin  >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int cnt = 0;
    for(int i = 0 ; i < n ; i++){
        if(!visited[i]){
            cnt++;
            dfs(g,i,visited,cnt);
        }
    }

    for(int i : visited)cout << i << " ";


    
    return 0;
}