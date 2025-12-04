#include <bits/stdc++.h>
using namespace std;

vector<int> g[100];// вектор хранит соседей вершины графа
int used[100]; // были ли посещены вершины
int d[100]; // хранения расстояние от начальной вершины до каждой другой вершины 
queue<int> q; // нужна для реализации bfs

int n,m,x,y;

void bfs(int v){
    q.push(v);
    used[v] = 1;
    d[v] = 0;

    while(!q.empty()){
        x = q.front();
        q.pop();
        for(int i = 0 ; i < g[x].size();i++){ // берем всех соседей вершины v 
            y = g[x][i]; // вот как раз таки соседи
            if(used[y] == 0){// в очереди еще не была
                q.push(y);
                used[y] = 1;
                d[y] = d[x] + 1; // обновляем расстояние до соседа
            } 
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 0;  i < m ; i++){
        cin >> x >> y;

        x--;
        y--;

        g[x].push_back(y);
        g[y].push_back(x);
    }
    bfs(0);
    for(int i = 0 ; i < n ;i++){
        cout <<  i << " --- " << d[i] << "\n";
    }
    return 0;
}