#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n,m,x,y,w;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    vector<vector<pair<int,int>>> g(n);
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> w;
        --x; --y;
        g[x].push_back({y, w});
        g[y].push_back({x, w});
    }

    vector<int> d(n,INF);//минимальная стоимость
    vector<int> p(n,-1);//откуда мы пришли?
    vector<int> u(n,0);//включена ли вершина в мст

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
            int k = g[v][i].first;//сосед
            int l = g[v][i].second;// вес ребра

            if(!u[k] && l < d[k]){
                d[k] = l;
                p[k] = v;
            }
        }
    }

    for(auto i : d)cout << i << " ";


    
    return 0;
}