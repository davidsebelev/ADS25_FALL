#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

vector<vector<int > >  bfs(
     vector<vector<int> > &a,
     vector<pair<int, int > > &marios
){
    int n = a.size();
    int m = a[0].size();

    vector<vector<int> > d(n,vector<int>(m,INF));
    queue<pair<int,int > > q;

    vector<int> dy = {-1,0,1,0};
    vector<int> dx = {0,1,0,-1};

    for(auto [sy,sx]:marios){
        d[sy][sx] = 0;
        q.push(make_pair(sy,sx));
    }

        while(!q.empty()){
            auto[y,x] = q.front();
            q.pop();

            for(int z = 0; z < dy.size();z++){
                int ty = y + dy[z];
                int tx = x + dx[z];


                if(0 <= ty && ty < n && 0 <= tx && tx < m
                && a[ty][tx] != 0 && d[ty][tx] == INF){
                    d[ty][tx] = d[y][x] + 1;
                    q.push(make_pair(ty,tx));
                }
            }
        }
    return d;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m;
    cin >> n >> m;

    vector<vector<int> > a(n,vector<int> (m));
    int startY,startX,finishY,finishX;

    vector<pair<int,int > > mushrooms_pos;
    vector<pair<int, int > > marios;

    for(int i = 0 ; i < n ;i++){
        for(int j = 0 ; j < m ; j++){
            cin >> a[i][j];
            if(a[i][j] == 2){
                startY = i;
                startX = j;
                marios.push_back(make_pair(startY,startX));
            }else if(a[i][j] == 1){
                finishX = j;
                finishY = i;
                mushrooms_pos.push_back(make_pair(finishY,finishX));
            }
        }
    }

    if(mushrooms_pos.empty()){
        cout << 0;
        return 0;
    }

    if(marios.empty()){
        cout << -1;
        return 0;
    }

    vector<vector<int> > d = bfs(a,marios);
    int ans = 0;
    vector<int> r;
    for(auto [gy,gx]:mushrooms_pos){
        if(d[gy][gx] == INF){
            cout << -1;
            return 0;
        }
        else{
            ans = max(ans, d[gy][gx]);
        }
    }
    cout << ans;

 
    return 0;
}