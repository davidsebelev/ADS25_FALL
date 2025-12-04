#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > matrAdj(int vertexCount,vector<pair<int,int> > &edges){
    vector<vector<int > > g(vertexCount,vector<int>(vertexCount));

    for(auto&[a,b]:edges){
        g[a][b] = 1;
        g[b][a] = 1;
    }

    return g;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    vector<pair<int,int> > edges(m);
    for(auto&[a,b]:edges){
        cin >> a >> b;
        a--;
        b--;
    }


    
    

    
    return 0;
}