#include <bits/stdc++.h>
using namespace std;


const int INF = 1e9;
int n,m,x,y;

vector<int> bfs(vector<vector<int> > &g,int start){
    int s = g.size();
    queue<int> q;
    vector<int> dist(s,INF);

    dist[start] = 0;
    q.push(start);

    while(!q.empty()){
        int y = q.front();
        q.pop();

        for(int to : g[y]){
            if(dist[to] == INF){
                dist[to] = dist[y] + 1;
                q.push(to);
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    vector<vector<int> > g(n);


    for(int i = 0 ; i < m ;i++){
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
    

    if(d[b]!=INF)cout << "YES";
    else cout << "NO";
    
    return 0;
}