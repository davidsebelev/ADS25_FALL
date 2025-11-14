#include <bits/stdc++.h>
using namespace std;

vector<int> pref(string s){
    int n = s.size();
    vector<int> p(n);

    p[0] = 0;
    for(int i =1 ; i < n;i++){
        int j = p[i-1];
        while(j > 0 && s[i]!=s[j]){
            j = p[j-1];
        }
        if(s[i] == s[j]){
            j++;
        }
        p[i] = j;
    }
    return p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s1,s2;
    cin >> s1 >> s2;

    int m = s2.size();

    string r = s2 + "#" + s1;
    vector<int> rr;
    vector<int> p = pref(r);

    // for(auto i : p) cout << i << " ";
    // cout << "\n";
    int n = s1.size();
    for(int i = 0 ; i < p.size();i++){
        if(p[i] == m && p[i-m+1] == 1){
            rr.push_back(i-m+1-m);
        }
    }

    // for(auto i : p){
    //     if(i >= 1)r.push_back(i);
    // }
    cout << rr.size() << "\n";
    for(auto i : rr)cout << i << " ";

    return 0;
}