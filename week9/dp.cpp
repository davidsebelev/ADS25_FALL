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


    vector<string> w;
    vector<int> rrr;


    while(t--){
        string x;
        cin >> x;
        string a ="";
        for(auto j : x)a+=tolower(j);
         //cout << a << "\n";
        w.push_back(x);
        s = a + "#" +  s;

        vector<int> p = pref(s);
        // for(auto i : p )cout << i << " ";
        // cout << "\n";

        //cout << s << "\n";
        int new_max = p[p.size() - 1];
        //cout << new_max << "\n";

        rrr.push_back(new_max);

        s = s_p;
 
    }

    //for(auto i : rrr)cout << i << " ";

    //cout << "\n";
    if(rrr.empty()){
        cout << 0;
        return 0;
    }
    int maxx = INT_MIN;
    for(int i = 0 ; i < rrr.size();i++){
        maxx = max(maxx,rrr[i]);
    }

    //cout << maxx;

    if(maxx == 0){
        cout << 0;
        return 0;
    }


    vector<string>f_r;
    for(int i = 0 ; i < rrr.size();i++){
        if(rrr[i] == maxx)f_r.push_back(w[i]);
    }

    cout << f_r.size() << "\n";

    for(auto i : f_r)cout << i << "\n";
    //cout << maxx;
    
    return 0;
}