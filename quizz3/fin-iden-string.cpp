#include <bits/stdc++.h>
using namespace std;

int get_hash(string s){
    int h = 0 ; 
    int p = 29;
    int p_pow = 1;
    for(int i = 0 ; i < s.size();i++){
        h += s[i]*p_pow;
        p_pow*=p;
    }
    return h;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> a(n);
    map<int, vector<int> > hash_map;

    for(int i = 0; i < n ; i++){
        cin >> a[i];
        int h = get_hash(a[i]);
        hash_map[h].push_back(i);
    }
    
    for(auto pairs: hash_map){
         vector<int>& indices = pairs.second;
         int sz = indices.size();

         for(int i = 0 ; i < sz ; i++){
            for(int j = i+1; j < sz ; j++){
                if(a[indices[i]] == a[indices[j]]){
                    cout << indices[i] << " " << indices[j] << "\n";
                }
            }
         }
    }
    
    return 0;
}