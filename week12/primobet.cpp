#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> g(n);

    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        --a; --b;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }

    vector<int> key(n, INF), used(n, 0);
    key[0] = 0;

    priority_queue<
        pair<int,int>, 
        vector<pair<int,int>>, 
        greater<pair<int,int>>
    > pq;

    pq.push({0, 0}); // (key, vertex)

    ll total = 0;

    while(!pq.empty()){
        auto [w, v] = pq.top();
        pq.pop();

        if(used[v]) continue;      // если уже были здесь → пропускаем
        used[v] = 1;
        total += w;                // добавляем вес ребра в MST

        for(auto [to, weight] : g[v]){
            if(!used[to] && weight < key[to]){
                key[to] = weight;
                pq.push({key[to], to}); // новый кандидат
            }
        }
    }

    cout << total << "\n";
}
