#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,a,b,w;
    ll total = 0;
    cin >> n >> m;

    vector<vector<pair<int,int>>> g(n);
    for(int i = 0 ; i < m ; i++){
        cin >> a >> b >> w;
        a--;b--;
        g[a].push_back({b,w});
        g[b].push_back({a,w});
    }

    vector<int> key(n, INF), parent(n, -1), used(n, 0);

    key[0] = 0;
    for(int i = 0 ; i < n ; i++){
        int v = -1;


        // ищем вершину которая неиспользована 
        for(int j = 0 ; j < n; j++){
            if(!used[j] && (v==-1 || key[j] < key[v])){
                v = j;
            }
        }
        // теперь пишем что она испольщована и проходимся по всем ее соседями и таким образом находим mst
        
        used[v] = 1;
            for(auto[to,w]:g[v]){
                if(!used[to] && w < key[to]){
                    key[to] = w;
                    parent[to] = v;
                }
            }
    }

    

    for(int i = 0 ; i < key.size();i++){
        total+=key[i];
    }
    cout << total;
    
    return 0;
}