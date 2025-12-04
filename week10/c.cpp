#include <bits/stdc++.h>
using namespace std;

int used[10000];

int bfs(int start,int end){
    queue<pair<int,int> >  q;

    used[start] = start;
    q.push({start,0});

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;

        if(x == end){
            return y;
        }

        

        if (x * 2 < 10000 && used[x*2] == 0){
            q.push({x*2,y+1});
            used[x*2] = x;
        }

        if (x - 1 >= 0 && used[x-1] == 0){
            q.push({x-1,y+1});
            used[x-1] = x;
        }
        q.pop();
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a,b;
    cin >> a >> b;

    vector<int> r;

    cout << bfs(a,b) << "\n";
    //for(auto i : used)cout << i << " ";
    r.push_back(b);
    int t = b;
    while(used[t]!=t){
        t = used[t];
        r.push_back(t);
    }


    for (int i = r.size()-2; i >= 0; i--)
        cout << r[i] << " ";

    
    return 0;
}