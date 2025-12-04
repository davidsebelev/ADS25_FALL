#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int bfs(
    vector<string> &a,
    int startY,
    int startX,
    int finishY,
    int finishX
){
    int h = a.size();
    int w = a[0].size();

    vector<vector<int> > d(h,vector<int>(w,INF));
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
    
    int stepCount = bfs(a,startY,startX,finishY,finishX);
    if(stepCount != INF){
        cout << stepCount;
    }else{
        cout << "Error";
    }
    return 0;
}