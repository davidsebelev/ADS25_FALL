#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 3;

    vector<int> r;
    while(n--){
        int x;
        cin >> x;
        r.push_back(x);
    }

    sort(r.begin(),r.end());
    int m = r[1];

    int sum = 0;
    for(auto i :r ){
        sum += abs(i - m);
    }

    cout << sum;
    
    return 0;
}