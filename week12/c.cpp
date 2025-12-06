#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

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

    int n,m,x,y,a,b,c;
    int w = 0;
    string s;
    // n village m roads
    // a 1 city , b second , c kilometrs
    //x big y small 
    cin >> n >> m >> x >> y;

    vector<pair<int,pair<int,int>>> edges;

    for(int i = 0 ; i < m ; i++){
        cin >> s >> a >> b >> c;

        if (s == "both") {
            w = min(c * x, c * y);
            } else if (s == "small") {
            w = c * y;
            } else { // big
                w = c * x;
                }

        edges.pb({w,{a,b}});
    }

    sort(edges.begin(),edges.end());


     DSU dsu(n + 1);
    ll mst_cost = 0;
    int used_edges = 0;

    for(const auto& e : edges){
        if(dsu.unite(e.second.first,e.second.second)){
            mst_cost += e.first;
            used_edges++;

            if(used_edges == n-1){
                break;
            }
        }
    }

    cout << mst_cost;

    
    return 0;
}