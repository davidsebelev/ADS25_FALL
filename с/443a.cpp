#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin , s);

    set<char> d;
    for(int i = 0 ; i < s.size();i++){
        if(s[i] >= 'a' and s[i] <= 'z'){
            d.insert(s[i]);
        }
    }
    cout << d.size();
    
    return 0;
}