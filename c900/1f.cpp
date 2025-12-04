#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    string s;
    cin >> s;
    char p = s[0];
    int cnt = 1;
    for(int i = 1 ; i < s.size();i++){
        if(s[i] == p)cnt++;
        else if(s[i] != p){
            p = s[i];
            cnt = 1;
        }

        if(cnt >= 7){
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";

    
    return 0;
}