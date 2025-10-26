#include<bits/stdc++.h>
using namespace std;


int main(){
    string s;
    cin >> s;
    unordered_map<char,int> f;


    for(int i = 0 ; i < s.length();i++){
        f[s[i]]++;
    }

    vector<char> r;
    for(unordered_map<char,int>::iterator it = f.begin();it!=f.end();it++){
        if(it->second == 1) r.push_back(it->first);
    }
    // for(auto x : f){
    //     if(x.second == 1){
    //         r.push_back(x.first);
    //     }
    // }

    bool ok = false;
    int res = 0;
    for(int i = 0 ; i < s.length();i++){
        for(int j = 0 ; j < r.size() && !ok;j++){
            if(s[i] == r[j]){
                res = i;
                ok = true;
                
                break;
            }
        }
    }

    if(ok) cout << res;
    else cout << -1;
    return 0;
}