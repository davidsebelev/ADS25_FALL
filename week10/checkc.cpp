#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

vector<int> bfs(vector<vector<int>> &g, int start){
    int n = g.size();
    vector<int> d(n,INF);
    queue<int> q;

    d[start] = 0;
    q.push(start);

    while(!q.empty()){
        int y = q.front();
        q.pop();

        for(int to: g[y]){
            if(d[to] == INF){
                d[to] = d[y] + 1;
                q.push(to);
            }
        }
    }
    return d;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m,x,y;
    cin >> n >> m;

    vector<vector<int> > g(n);
    for(int i = 0 ; i < m ; i++){
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    vector<int> d = bfs(g,a);
    for(auto i : d) cout << i << " ";
    return 0;
}