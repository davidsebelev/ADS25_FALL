#include <bits/stdc++.h>
using namespace std;

vector<int> pref(string s) {
    int n = s.size();
    vector<int> pi(n);
    pi[0] = 0;

    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];

        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }

        if (s[i] == s[j]) {
            j++;
        }

        pi[i] = j;
    }

    return pi;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    string s_p = s;

    int t;
    cin >> t;

    string r = "";
    vector<string> w;
    vector<int> res;
    while(t--){
        string a;
        cin >> a;
        w.push_back(a);
        s = a + "#" +  s;

        vector<int> p = pref(s);

        cout << s << "\n";
        for(auto i: p){
            cout << i << " ";
        }
        cout << "\n";
        int maxx = INT_MIN;
        for(auto i: p){
            maxx = max(maxx,i);
        }
        res.push_back(maxx);
        s = s_p;
        //cout << "\n";
    }

    // int maxx = INT_MIN;
    // for(int i = 0 ; i < res.size();i++){
    //     maxx = max(maxx,res[i]);
    // }

    // vector<string>f_r;
    // for(int i = 0 ; i < res.size();i++){
    //     if(res[i] == maxx)f_r.push_back(w[i]);
    // }

    // cout << f_r.size() << "\n";

    // for(auto i : f_r)cout << i << "\n";
    //cout << maxx;
    
    return 0;
}