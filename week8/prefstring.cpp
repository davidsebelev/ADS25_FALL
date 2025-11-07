#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    vector<string> p(s.size());
    p[0] = s[0];
    for(int i = 1 ; i < s.size();i++){
        p[i] = p[i-1] + s[i];
    }

    for(auto i : p) cout << i << " ";
    return 0;
}