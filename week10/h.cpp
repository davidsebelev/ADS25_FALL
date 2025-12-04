#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    vector<vector<int> >  g(n);
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < m; j++){
            int x;
            cin >> x;
            if(x){
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }

    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < m; j++){
            if(g[i][j]){

            }
        }
    }
    
    return 0;
}