#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool compS(const pair<int,pair<int,int>> &a, const pair<int,pair<int,int>> &b){
    return a.second.second < b.second.second;
}

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

    int n, m;
    cin >> n >> m;

    vector<pair<int,pair<int,int>>> edges;
    edges.reserve(m);
    for (int i = 0; i < m; i++) {
        int x, y;
        ll w;
        cin >> x >> y >> w;
        --x; --y;         
        edges.push_back({x,{y,w}});
    }

    sort(edges.begin(), edges.end(),compS);

    DSU dsu(n);
    ll mst_cost = 0;
    int used_edges = 0;

    for(const auto& e : edges){
        if(dsu.unite(e.first,e.second.first)){
            mst_cost += e.second.second;
            used_edges++;

            if(used_edges == n-1){
                break;
            }
        }
    }

    cout << mst_cost;

    
    return 0;
}