#include <bits/stdc++.h>
using namespace std;


vector<int> pref_f(string s){
    int n = s.size();
    vector<int> p(n);

    p[0] = 0;

    for(int i = 1 ; i < n ;i++){
        int j = p[i - 1];

        while (j > 0 && s[i] != s[j]) {
            j = p[j - 1];
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

    string s;
    cin >> s;

    vector<int> p = pref_f(s);
    for(auto i : p)cout << i << " ";
    
    return 0;
}