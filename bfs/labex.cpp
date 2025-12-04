#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

vector<vector<int> > bfs(
    vector<string> &a,
    int startY,
    int startX,
    int finishY,
    int finishX
){
    int n = a.size();
    int m = a[0].size();

    vector<vector<int> > d(n,vector<int> (m,INF));
    queue<pair<int, int > > q;

    d[startY][startX] = 0;
    q.push(make_pair(startY,startX));

    vector<int> dy = {-1,0,1,0};
    vector<int> dx = {0,1,0,-1};

    while(!q.empty()){
        auto[y,x] = q.front();
        q.pop();

        for(int i = 0 ; i < dy.size();i++){
            int ty = y + dy[i];
            int tx = x + dx[i];

            if(0<= ty && ty < n && 0<=tx && tx < m
            && a[ty][tx] != '#' && d[ty][tx] == INF){
                d[ty][tx] = d[y][x] + 1;
                q.push(make_pair(ty,tx));
            }
        }
    }

    return d;

}
//  чтобы нарисовать сам путь по лабиринту
int bfsPath(
    vector<string> &a,
    int startY,
    int startX,
    int finishY,
    int finishX
){
    int h = a.size();
    int w = a[0].size();

    vector<vector<int> > d(h,vector<int>(w,INF));
    vector<vector<pair<int, int > > > from(h,vector<pair<int,int> > (w,{-1,-1}));
    queue<pair<int, int > > q;

    d[startY][startX] = 0;
    q.push(make_pair(startY,startX));

    vector<int> dy = {-1,0,1,0};
    vector<int> dx = {0,1,0,-1};

    while(!q.empty()){
        auto[y,x] = q.front();
        q.pop();

        if(finishY == y && finishX == x){
            return d[finishY][finishX];
        }

        for(int i = 0 ; i < dy.size();i++){
            int ty = y + dy[i];
            int tx = x + dx[i];

            if(0 <= ty && ty < h && 0 <= tx && tx < w
            && a[ty][tx] != '#' && d[ty][tx]== INF){
                d[ty][tx] = d[y][x] + 1;
                q.push(make_pair(ty,tx));
            }
        }
    }
    return d[finishY][finishX];
}

int bfsS(
    vector<string> &a,
    int startY,
    int startX,
    int finishY,
    int finishX
){
    int h = a.size();
    int w = a[0].size();

    vector<vector<int> > d(h,vector<int>(w,INF));
    vector<vector<pair<int, int > > > from(h,vector<pair<int,int> > (w,{-1,-1}));
    queue<pair<int, int > > q;

    d[startY][startX] = 0;
    q.push(make_pair(startY,startX));

    vector<int> dy = {-1,0,1,0};
    vector<int> dx = {0,1,0,-1};

    while(!q.empty()){
        auto[y,x] = q.front();
        q.pop();


        for(int i = 0 ; i < dy.size();i++){
            int ty = y + dy[i];
            int tx = x + dx[i];

            if(0 <= ty && ty < h && 0 <= tx && tx < w
            && a[ty][tx] != '#' && d[ty][tx]== INF){
                d[ty][tx] = d[y][x] + 1;
                from[ty][tx] = {y,x};
                q.push(make_pair(ty,tx));
            }
        }
    }

    if(d[finishY][finishX] != INF){
        int y = finishY;
        int x = finishX;

        while(y!= -1 && x!= -1){
            a[y][x] = '*';
            auto[py,px] = from[y][x];
            y = py;
            x = px;
        }
    }
    return d[finishY][finishX];
}

// если выходов будет несколько 
// делаем вектор выходов
int bfsSF(
    vector<string> &a,
    int startY,
    int startX,
    vector<pair<int,int>> &finishCells
){
    int h = a.size();
    int w = a[0].size();

    vector<vector<int> > d(h,vector<int>(w,INF));
    vector<vector<pair<int, int > > > from(h,vector<pair<int,int> > (w,{-1,-1}));
    queue<pair<int, int > > q;

    d[startY][startX] = 0;
    q.push(make_pair(startY,startX));

    vector<int> dy = {-1,0,1,0};
    vector<int> dx = {0,1,0,-1};

    while(!q.empty()){
        auto[y,x] = q.front();
        q.pop();


        for(int i = 0 ; i < dy.size();i++){
            int ty = y + dy[i];
            int tx = x + dx[i];

            if(0 <= ty && ty < h && 0 <= tx && tx < w
            && a[ty][tx] != '#' && d[ty][tx]== INF){
                d[ty][tx] = d[y][x] + 1;
                from[ty][tx] = {y,x};
                q.push(make_pair(ty,tx));
            }
        }
    }

    auto[finishY,finishX] = finishCells[0];
    for(auto &[y,x] : finishCells){
        if(d[finishY][finishX] > d[y][x]){
            finishY = y;
            finishX = x;
        }
    }

    if(d[finishY][finishX] != INF){
        int y = finishY;
        int x = finishX;

        while(y!= -1 && x!= -1){
            a[y][x] = '*';
            auto[py,px] = from[y][x];
            y = py;
            x = px;
        }
    }
    return d[finishY][finishX];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;

    vector<string> a(n);
    vector<pair<int, int >> finishCelss;

    int startY,startX,finishY,finishX;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
        for(int j = 0 ; j < m ; j++){
            if(a[i][j] == 'S'){
                startX = j;
                startY = i;
            }else if(a[i][j] == 'F'){
                finishY = i;
                finishX = j;
                finishCelss.push_back({finishY,finishX});

            }
        }
    }

    vector<vector<int > > dist = bfs(a,startY,startX,finishY,finishX);
    //int ans = 0;
    // выведет максимум
    // for(int i = 0 ; i < n ; i++){
    //     for(int j = 0 ; j < m ; j++){
    //         if(dist[i][j] != INF){
    //             ans = max(ans,dist[i][j]);
    //         }
    //     }
    // }


    // для первой функции
    // ans = dist[finishY][finishX];
    // if(ans == INF)cout << -1;
    // else cout << ans;

    int stepCnt = bfsSF(a,startY,startX,finishCelss);
    if(stepCnt != INF){
        cout << stepCnt << "\n";
        for(string & row : a){
            cout << row << "\n";
        }
    }else{
        cout << -1;
    }




    
    return 0;
}