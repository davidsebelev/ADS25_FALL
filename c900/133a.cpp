#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    bool fl = false;
    for(auto i : s){
        if(i == 'H' || i == 'Q' || i == '9')fl = true;
    }
    if(fl)cout << "YES";
    else cout << "NO";
    
    return 0;
}