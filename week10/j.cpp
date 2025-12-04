#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,x,y,ans = 0;
    cin >> n >> m;
    vector<vector<int> > g(n);
    vector<bool> used(n,0);
    vector<int> children(n,0);
    

    for(int i = 0 ; i < m ; i++){
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
        children[x]++;
    }


    for(int i = 0 ; i < n ;i++){
        if(used[i] == 0){
            queue<int> q;
            q.push(i);

            used[i] = 1;
            ans++;
            while(!q.empty()){
                int y = q.front();
                q.pop();

                for(int to : g[y]){
                    if(used[to] == 0){
                        if(children[y] < children[to])ans++;
                        used[to] = 1;
                        q.push(to);
                    }
                }
            }
        }
    }

    cout << ans;
    return 0;
}