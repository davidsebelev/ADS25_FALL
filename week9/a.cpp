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

    string a,b;
    cin >> a >> b;
    string res = "";

    int cnt = 1;
    bool fl = false;
    string c = a;
    while(a.size() < b.size()){
        cnt++;
        a+= c;
    }
    res = b + "#" + a;

    vector<int> pref = pref_s(res);
    for(int i = 0 ; i < pref.size();i++){
        if(pref[i] == b.size()){
            cout << cnt;
            return 0;
        }
    }

    string ne_r = "";
    if(!fl){
        a+=c;
        ne_r=  b + "#" + a;
        cnt++;
    }
    vector<int> pref2 = pref_s(ne_r);
    bool f = false;
    for(int i = 0 ; i < pref2.size();i++){
        if(pref2[i] == b.size()){
            f = true;
            break;
        }
    }

    if(!f)cout << -1;
    else cout << cnt;
    return 0;
}