#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

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

    int n,x,y;
    cin >> n;
    vector<vector<int> > g(n);
    for(int i = 0; i < n ;i++){
        for(int j = 0 ; j < n ; j++){
            int x;
            cin >> x;
            if(x == 1){
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }

    int start,finish;
    cin >> start >> finish;
    start--;
    finish--;

    //cout << start << " " << finish;


    vector<int> d = bfs(g,start);

    bool fl = true;
    for(int i = 0; i < d.size();i++){
        if(i == finish && d[i] != INF){
            cout << d[i];
            fl = false;
            return 0;
        }
    }

    if(fl)cout << -1;


    
    return 0;
}