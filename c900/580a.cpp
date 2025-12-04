#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;cin >> n;
    int cnt = 0;

    bitset<32> b(n);

    string s = b.to_string();
    for(auto i : s)
        if(i == '1')cnt++;

    cout << cnt;
    
    return 0;
}