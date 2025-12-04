#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct DSU {
    vector<int> parent, rank;
    DSU(int n) : parent(n), rank(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int v) {
        if (parent[v] == v) return v;
        return parent[v] = find(parent[v]); // path compression
    }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;          // already in same set
        if (rank[a] < rank[b]) swap(a, b); // union by rank
        parent[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
        return true;
    }
};

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const { return w < other.w; }
};

int main() {
    int n, m,x,y,w;
    cin >> n >> m;
    vector<Edge> edges;
    edges.reserve(m);
    while(m--){
        cin >> x >> y >> w;
        for(int i = x ; i < y ;i++){
        edges.push_back({i - 1, y - 1, w});
        }
    }

    sort(edges.begin(), edges.end());
    DSU dsu(n);

    ll mst_cost = 0;
    vector<Edge> mst;

    for (auto &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            mst.push_back(e);
            mst_cost += e.w;
        }
        if ((int)mst.size() == n - 1) break;
    }

    cout << mst_cost;
    return 0;
}