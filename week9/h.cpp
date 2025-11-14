#include <bits/stdc++.h>
using namespace std;

vector<int> pref_s(string s){
    int n = s.size();
    vector<int> p(n);

    p[0] = 0;
    for(int i = 1 ; i < n;i++){
        int j = p[i - 1];

        while(j > 0 && s[i]!=s[j]){
            j = p[j-1];
        }

        if(s[i] == s[j])j++;

        p[i] = j;
    }
    return p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int n = s.size();

    vector<int> p = pref_s(s);
    //for(auto i : p)cout << i << " ";

    int cnt = 0;

    for(int i = 1; i < ((n-1) / 2) + 1;i++){
        bool ok = true;
        for (int j = 0; j < i; j++) {
            if (s[j] != s[j + i]) {
                ok = false;
                break;
            }
        }

        if (ok) cnt++;
    }
    cout << cnt;

    
    return 0;
}