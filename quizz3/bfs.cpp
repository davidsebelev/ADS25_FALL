#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
vector<int> adj[MAXN];
bool visited[MAXN];
int n;


void bfs(int source){
    queue<int> q;
    for(int i = 0 ; i< n ; i++){
        visited[i] = false;
    }

    visited[source] = true;
    q.push(source);

    while(!q.empty()){
        int y = q.front();
        q.pop();

        for(int i = 0 ; i < adj[y].size();i++){
            int u  = adj[y][i];
            if(!visited[u]){
                visited[u] = true;
                q.push(u);
            }
        }
    }
}

void bfs_dist(int source){
    queue<int> q;
    vector<int> d(MAXN);


    for(int i = 0 ; i < n ; i++){
        visited[i] = false;
        d[i] = -1;
    }

    visited[source] = true;
    d[source] = 0;
    q.push(source);

    while(!q.empty()){
        int y = q.front();
        q.pop();

        for(int i = 0 ; i < adj[y].size();i++){
            int u  = adj[y][i];
            if(!visited[u]){
                visited[u] = true;
                d[u] = d[y] + 1;
                q.push(u);
            }
        }
    }
}

void bfs_parent(int source,int targer){
    queue<int> q;
    int parent[MAXN];

    for (int i = 0; i < n; i++) {
        visited[i] = false;
        parent[i] = -1;
    }

    visited[source] = true;
    q.push(source);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if(v == targer){
            break;
        }

        for(int i = 0 ; i < adj[v].size();i++){
            int u = adj[v][i];
            if(!visited[u]){
                visited[u] = true;
                parent[u] = v;
                q.push(u);
            }
        }

        
    }

    if (!visited[targer]) {
        cout << "No path exists" << endl;
        return;
    }

    vector<int> path;
    int current = targer;
    while (current != -1) {
        path.push_back(current);
        current = parent[current];
    }


    reverse(path.begin(), path.end());
    for (int i = 0; i < path.size(); i++) {
        cout << path[i];
        if (i < path.size() - 1)
            cout << " -> ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}