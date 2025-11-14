#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int> > c;

    while(n--){
        int a,b;
        cin >> a >> b;

        c.push_back(make_pair(a,b));    
    }


    int cnt = 0;
    for(int i = 0 ; i < c.size();i++){
        for(int j = i+1 ; j < c.size();j++){
            if(c[i].first == c[j].second)cnt++;
            if(c[i].second == c[j].first)cnt++;
        }
    }

    
    cout << cnt;

    return 0;
}