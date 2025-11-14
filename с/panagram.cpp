#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string s;
    cin >> s;

    set<char> d;

    for(int i = 0 ; i < n ;i++){
        d.insert(tolower(s[i]));
    }

    if(d.size() == 26)cout << "YES";

    //cout << d.size();
    //for(auto i : d)cout << i << " ";
    else cout << "NO";
    
    return 0;
}