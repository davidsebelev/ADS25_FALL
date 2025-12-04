#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int bfs(
    vector<string> &a,
    int startY,
    int startX,
    int finishY,
    int finishX,
    vector<vector<pair<int,int>>> &from   // <-- передаём наружу
){
    int h = a.size();
    int w = a[0].size();

    vector<vector<int>> d(h, vector<int>(w, INF));
    deque<pair<int,int>> q;

    d[startY][startX] = 0;
    q.push_back({startY,startX});

    vector<int> dy = {-1,0,1,0};
    vector<int> dx = {0,1,0,-1};

    while(!q.empty()){
        auto [y,x] = q.front();
        q.pop_front();

        for(int i = 0 ; i < 4; i++){
            int ty = y + dy[i];
            int tx = x + dx[i];

            if(0 <= ty && ty < h && 0 <= tx && tx < w){
                // cost = 1 for 'G'
                if(a[ty][tx] == 'G' && d[ty][tx] > d[y][x] + 1){
                    d[ty][tx] = d[y][x] + 1;
                    from[ty][tx] = {y,x};
                    q.push_back({ty,tx});
                }
                // cost = 0 for '#'
                else if(a[ty][tx] == '#' && d[ty][tx] > d[y][x]){
                    d[ty][tx] = d[y][x];
                    from[ty][tx] = {y,x};
                    q.push_back({ty,tx});
                }
            }
        }
    }

    return d[finishY][finishX];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h,w;
    cin >> h >> w;

    vector<string> a(h);
    int startY,startX,finishX,finishY;

    for(int i = 0 ; i < h ; i++){
        cin >> a[i];
        for(int j = 0; j < w ; j++){
            if(a[i][j] == 'S'){
                startY = i;
                startX = j;
            }else if(a[i][j] == 'F'){
                finishY = i;
                finishX = j;
            }
        }
    }

    // from вынесен наружу
    vector<vector<pair<int,int>>> from(h, vector<pair<int,int>>(w, {-1,-1}));

    // запускаем BFS
    int stepCount = bfs(a,startY,startX,finishY,finishX,from);

    if(stepCount == INF){
        cout << "Error";
        return 0;
    }

    // ВОССТАНАВЛИВАЕМ ПУТЬ
    int y = finishY;
    int x = finishX;

    while(!(y == startY && x == startX)){
        a[y][x] = '*';
        auto [py,px] = from[y][x];
        y = py;
        x = px;

        if(py == -1) break; // на всякий случай
    }

    a[startY][startX] = 'S';
    a[finishY][finishX] = 'F';

    cout << stepCount << "\n";

    for(string & row : a){
        cout << row << "\n";
    }

    return 0;
}
