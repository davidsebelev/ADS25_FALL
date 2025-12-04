#include <bits/stdc++.h>
using namespace std;

int g[100][100];
queue<int> q;
int u[100];
int d[100];

int n,m,x,y;

void bfs(int x){
    q.push(x);
    u[x] = 1;
    d[x] = 0;
    while(!q.empty()){
        x = q.front();
        for(int y = 0; y < n ; y++){
            if(g[x][y] == 1){
                u[y] = 1;
                d[y] = d[x]+ 1;
            }
        }
        q.pop();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < m ; i++){
        cin >> x >> y;

        x--;
        y--;
        g[x][y] = 1;
        g[y][x] = 1;
    }
    

    bfs(4);
    for(int i = 0 ; i < n ; i++) cout << i << " --- " << d[i] << "\n";
    return 0;
}