#include <bits/stdc++.h>
using namespace std;

const int maxN = 100;
int g[maxN][maxN];


vector<int> l[maxN];




int n,m,x,y;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;


    for(int i = 0 ;i < m ;i++){
        cin >> x >> y;

        x--;
        y--;

        l[x].push_back(y);
        l[y].push_back(x);
    }
    //for list adj
    for(int i = 0; i < n ; i++){
        cout << i << " --- ";
        for(int j = 0 ; j < l[i].size();j++){
            cout << l[i][j] << " ";
        }
        cout << "\n";
    }

    //for matrix adj
    // for(int i = 0 ; i < m ; i++){
    //     cin >> x >> y;

    //     x--;
    //     y--;

    //     g[x][y] = 1;
    //     g[y][x] = 1;
    // }

    // for matrix adj
    // for(int i = 0 ; i < n; i++){
    //     for(int j = 0; j < n ; j++){
    //         cout << g[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    
    return 0;
}