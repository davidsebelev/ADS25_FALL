#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 1e9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,x,y,w;
    cin >> n >> m;

    vector<vector<pair<int,ll>>> g(n);

    while(m--){
        cin >> x >> y >> w;
        --x; --y;
        for(int i = x ; i < y ;i++){
        g[i].push_back({i + 1, w});
        g[i + 1].push_back({i, w});
        }
    }


    vector<ll> d(n,INF);//минимальная стоимость
    vector<ll> p(n,-1);//откуда мы пришли?
    vector<char> u(n,0);//включена ли вершина в мст

    d[0] = 0;
    for(int i = 0 ; i < n ;i++){
        int v = -1;
        for(int j = 0 ; j < n ;j++){
            if(!u[j]){
                if(v == -1 || d[v] > d[j]){
                    v = j;
                }
            }
        }
        u[v] = 1;

        for(int i = 0 ; i < g[v].size();i++){
            ll k = g[v][i].first;//сосед
            ll l = g[v][i].second;// вес ребра

            if(!u[k] && l < d[k]){
                d[k] = l;
                p[k] = v;
            }
        }
    }
    ll sum = 0;
    for(ll i : d)sum+=i;
    cout << sum;
    
    return 0;
}