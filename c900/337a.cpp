#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n,m,mi,ma;
    ma = INT_MIN;
    mi = INT_MAX;
    cin >> n >> m;

    vector<pair<int,int > > p;
    vector<int> r;
    vector<int> a(m);
    for(int i = 0 ; i < m ; i++)cin >> a[i];
    sort(a.begin(),a.end());

    for(int i = 0 ; i + n - 1 < m ;i++){
        ma = INT_MIN;
        mi = INT_MAX;
        for(int j = i ; j < i + n ; j++){
             ma = max(ma,a[j]);
             mi = min(mi,a[j]);
        }
        p.push_back({ma,mi});
    }


    for(auto &[a,b]:p)r.push_back(a-b);
    sort(r.begin(),r.end());
    cout << r[0];



    
    return 0;
}