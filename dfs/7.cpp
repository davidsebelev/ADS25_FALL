#include <bits/stdc++.h>
using namespace std;

void dfs(vector<string> &a, int y, int x,int comp){
    a[y][x] = 'A' + comp - 1;

    static vector<int> dy = {-1,0,1,0};
    static vector<int> dx = {0,1,0,-1};

    for(int i = 0 ; i < 4 ; i++){
        int ty = y + dy[i];
        int tx = x + dx[i];

        if(0<= ty && ty < (int)a.size() &&
           0<= tx && tx < (int)a[ty].size() &&
           a[ty][tx] == '#')
        {
            dfs(a,ty,tx,comp);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    vector<string > a(n);
    for(int i = 0 ; i < n; i++)cin >> a[i];

    int cnt = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m;j++){
            if(a[i][j] == '#'){
                cnt++;
                dfs(a,i,j,cnt);
            }
        }
    }
    
    for(auto &row : a)cout << row << "\n";
    return 0;
}
