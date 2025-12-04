#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int bfs(vector<vector<int>> &g, vector<int> &type,int s){
    int n = (int)g.size() - 1; 

    vector<int> d(n+1,INF);
    queue<int> q;

    d[s] = 0;
    q.push(s);

    while(!q.empty()){
        int y = q.front();
        q.pop();
        if(type[y] == 1){
            return d[y];
        }

        for(int to : g[y]){
            if(d[to] == INF){
                d[to] = d[y] + 1;
                q.push(to);
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,x,y,a,b,q;
    cin >> n >> m >> q;

    vector<vector<int> > g(n+1);
    for(int i = 0 ; i < m ;i++){
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }


    vector<int> type(n+1,0);
    while(q--){
        cin >> a >> b;

        if(a == 1){
            type[b] = 1;
        }else{
            cout << bfs(g,type,b) << "\n";
        }
    }
    return 0;
}