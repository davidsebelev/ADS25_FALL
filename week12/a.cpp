#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> left(n + 1);

    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        --a; --b;                       
        left[a].push_back({b, w});     
    }

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    ll total = 0;

    for(int i = 0; i < n - 1; i++) {

        for(auto p : left[i]){
            pq.push({p.second, p.first});   
        }


        while(!pq.empty() && pq.top().second <= i){
            pq.pop();
        }

        if(pq.empty()){
            cout << 0;
            return 0;
        }

        total += pq.top().first;
    }

    cout << total;
    return 0;
}
