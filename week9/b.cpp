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

    string p;
    int k;
    cin >> p >> k;

    string s;
    cin >> s;

    string res = p + '#' + s;

    vector<int> pref = pref_s(res);
    int cnt = 0;
    for(int i = 0 ; i < pref.size();i++){
        if(pref[i] == p.size())cnt++;
    }

    if(cnt >= k)cout << "YES";
    else cout << "NO";



    
    return 0;
}