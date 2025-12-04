#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

pair<vector<int> , vector<int> > bfs(vector<vector<int > > &graph, int start){
    int n = graph.size();
    vector<int> d(n,INF);
    vector<int> from(n,-1);
    queue<int> q;

    d[start] = 0;
    q.push(start);

    while(!q.empty()){
        int y = q.front();
        q.pop();

        for(int to : graph[y]){
            if(d[to] == INF){
                d[to] = d[y] + 1;
                from[to] = y;
                q.push(to);
            }
        }
    }
    return make_pair(d,from);
}

vector<int> getPath(vector<int> &from, int finish){
    vector<int> path;
    for(int i = finish; i != -1; i = from[i]){
        path.push_back(i);
    }
    reverse(path.begin(),path.end());
    return path;
}
int n,m,x,y;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    vector<vector<int> > g(n);
    for(int i = 0; i < m ;i++){
        cin >> x >> y;


        g[x].push_back(y);
        g[y].push_back(x);
    }
    int start;
    cin >> start;
    auto[dist,from] = bfs(g,start);

    vector<int> path = getPath(from, 3);
    for(auto i : path)cout << i << " ";
    return 0;
}