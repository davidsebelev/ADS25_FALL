#include <bits/stdc++.h>
using namespace std;

struct DSU
{
    vector<int> parent,sz;

    DSU(int n) : parent(n),sz(n,1){
        iota(parent.begin(),parent.end(),0);
    }

    int find(int v){
        if(parent[v] == v)return v;
        return parent[v] = find(parent[v]);
    }

    bool unite(int a, int b){
        a = find(a);
        b = find(b);

        if(a == b)return false;
        
        if(sz[a] < sz[b])
            swap(a,b);

        parent[b] = a;
        sz[a] += sz[b];
            
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);

    for(int i = 0; i < m; i++){
        int v, u;
        cin >> v >> u;
        g[v].push_back(u);
        g[u].push_back(v);
    }

    DSU dsu(n);

    vector<int> ans(n);
    vector<bool> active(n + 1, false);

    int components = 0;
    

    for(int v = n; v >= 1; v--){
        active[v] = true;
        components++;

        for(int u : g[v]){
            if(active[u]){
                if(dsu.unite(v, u)){
                    components--;
                }
            }
        }

        ans[v - 1] = components;
    }

    for(int i = 1; i < n; i++){
        cout << ans[i] << endl;
    }
    cout << 0;
    return 0;
}



