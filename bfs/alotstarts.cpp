#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int bfsSF(
    vector<string> &a,
    vector<pair<int, int >> &startCells,
    vector<pair<int,int>> &finishCells
){
    int h = a.size();
    int w = a[0].size();

    vector<vector<int> > d(h,vector<int>(w,INF));
    vector<vector<pair<int, int > > > from(h,vector<pair<int,int> > (w,{-1,-1}));
    queue<pair<int, int > > q;

    for(auto[startY,startX]:startCells){
        d[startY][startX] = 0;
        q.push({startY,startX});
    }

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
    vector<pair<int, int >> startCelss;

    int startY,startX,finishY,finishX;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
        for(int j = 0 ; j < m ; j++){
            if(a[i][j] == 'S'){
                startX = j;
                startY = i;
                startCelss.push_back({startY,startX});
            }else if(a[i][j] == 'F'){
                finishY = i;
                finishX = j;
                finishCelss.push_back({finishY,finishX});

            }
        }
    }


   

    int stepCnt = bfsSF(a,startCelss,finishCelss);
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