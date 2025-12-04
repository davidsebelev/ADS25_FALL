#include <bits/stdc++.h>
using namespace std;

vector<int> pref_s(string s){
    int n = s.size();
    vector<int> p(n);

    p[0] = 0;
    for(int i = 1 ; i < n;i++){
        int j = p[i-1];
        while(j > 0  && s[i]!=s[j]){
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

    vector<char> bad;
    for(auto i : s)bad.push_back(i);

    string pattern = "WUB";

    int n = s.size();
    int m = pattern.size();

    string r = pattern + '#' + s;
    vector<int> p = pref_s(r);

    // for(auto i: p)cout << i << " ";
    //cout << "\n";
    string res = "";
    int start = 0;
    for(int i = 0 ; i < p.size() ;i++){
        if(p[i] == m){
            start = i - m + 1 - m - 1; 
            bad[start + 1] = bad[start + 2] = bad[start] = '#';
        }
    }


    string w = "";
    for(auto i : bad){
        if(i != '#'){
             w += i;
        }else{
            if(!w.empty())cout << w << " ";
            w = "";
        }
        }
        if (!w.empty()) cout << w;

    return 0;
}