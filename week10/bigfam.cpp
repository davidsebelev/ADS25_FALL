#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    vector<bool> used(n,false);
    vector<int> parent(n,-1);
    vector<int> children_cnt(n,0);
    vector<int> used_bfs(n,false);
    cin >> n >> m;

    vector<vector<int> > g(n);
    int x, y;

    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }


    vector<int> roots;
    for(int i = 0 ; i < n ;i++){
        if(used[i] == 0){
            queue<int> q;
            q.push(i);
            used[i] = true;

            int mn = i; //min vaelue vertex

            while(!q.empty()){
                int y = q.front(); q.pop();
                mn = min(mn,y);

                for (int to : g[y]) {
                    if (!used[to]) {
                        used[to] = true;
                        q.push(to);
                    }
                }

                roots.push_back(mn);
            
            }
        }
    }

    for(int i : roots){
        queue<int> q;
        q.push(i);

        used_bfs[i] = true;
        parent[i] = -1;

        while(!q.empty()){
            int v = q.front(); q.pop();

             for (int to : g[v]) {
                if (!used_bfs[to]) {
                    used_bfs[to] = true;

                    parent[to] = v;        // родитель
                    children_cnt[v]++;     // v → ребёнок to

                    q.push(to);
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0 ; i < n ;i++){
        if(parent[i] == -1)ans++;
        else{
            int p = parent[i];
            if(children_cnt[i] > children_cnt[p]){
                ans++;
            }
        }
    }

    cout << ans;

    return 0;
}