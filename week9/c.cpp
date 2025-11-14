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

    string s1,s2;
    cin >> s1 >> s2;


    string s = s1 + "#" + s2+s2;

    int n = s1.size();
    int s_i = 0;
    bool fl = false;

    vector<int> p =  pref_s(s);
    for(int i = 0 ; i < p.size();i++){
        if(p[i] == 1 && p[i + n-1] == n){
            s_i = i;
            fl = true;
            break;
        }
    }

    if(fl) cout << s_i - n - 1;
    else cout << -1;
    
    return 0;
}