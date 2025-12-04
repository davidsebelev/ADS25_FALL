#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &a, int y, int x, vector<vector<int>> &visited){
    visited[y][x] = 1;

    static vector<int> dy = {-1,0,1,0};
    static vector<int> dx = {0,1,0,-1};

    for(int i = 0 ; i < 4 ; i++){
        int ty = y + dy[i];
        int tx = x + dx[i];

        if(0<= ty && ty < a.size() && 0<=tx && tx < a.size() && a[ty][tx] == 1 && visited[ty][tx]==0){
            dfs(a,ty,tx,visited);
        }
    }

}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    vector<vector<int>> a(n,vector<int>(m));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m;j++){
            cin >> a[i][j];
        }
    }


    vector<vector<int>> visited(n,vector<int> (m));

    int cnt = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m;j++){
            if(a[i][j] == 1 && visited[i][j] == 0){
                cnt++;
                dfs(a,i,j,visited);
            }
        }
    }
    
    cout << cnt;
    return 0;
}