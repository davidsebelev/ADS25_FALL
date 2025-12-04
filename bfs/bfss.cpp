#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;//константа бесконечности

vector<int> bfsC(vector<vector<int> > &graph , int start){
    vector<int> d(graph.size(),INF);
    queue<int> q;

    d[start] = 0;
    q.push(start);

    while(!q.empty()){
        int y = q.front();
        q.pop();

        for(int to: graph[y]){
            if(d[to] == INF){
                d[to] = d[y] + 1;
                q.push(to);
            }
        }
    }
    return d;
}



int n,m,x,y;

//in our case n - vertexcount & m - edgeCount

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    vector<vector<int> > graph(n);

    for(int i = 0 ; i < m ;i++){
        cin >> x >> y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int start;
    cin >> start;

    vector<int> dist = bfsC(graph,start);
    for(auto i : dist){
        if(i!= INF)cout << i << " ";
        
    }


    
    return 0;
}