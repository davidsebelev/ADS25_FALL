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

    int t;
    cin >> t;
    while(t--){
        string s;
        int k;
        cin >> s >> k;

        vector<int> p = pref(s);
        int overload = p[p.size()-1];

        cout << s.size() + (k - 1) * (s.size() - overload) << "\n";
    }
    
    return 0;
}