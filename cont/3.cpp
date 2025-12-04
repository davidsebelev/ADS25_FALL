#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    vector<string> res;
    int cnt = 0;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);//ajisai
        vector<int> b(n);//may
        for(int i = 0 ; i < n ; i++)cin >> a[i];
        for(int i = 0 ; i < n ; i++)cin >> b[i];

        for(int i = 0; i < n; i++){
    if(i + 1 == n) continue; 

    if(a[i] != b[i]){
        int x = 0;
        int pos = i + 1;

        if(pos % 2 == 1){ 
            for(int j = i; j < n; j++) x ^= a[j];
        }else{            
            for(int j = i; j < n; j++) x ^= b[j];
        }

        if(x == 0){
            swap(a[i], b[i]);
        }
    }
}
        // for(auto i : a)cout << i << " ";
        // cout << "\n";
        // for(auto j : b)cout << j << " ";
        // cout << "\n";

        int res1,res2;
        res1=res2 = 0;
        for(auto i : a){
            res1^=i;
        }
        for(auto j : b){
            res2^=j;
        }

        if(res1 == res2){
            res.push_back("Tie");
        }else if(res1 > res2){
            res.push_back("Ajisai");
        }else if(res1 < res2){
            res.push_back("Mai");
        }
    }

    for(auto i : res)cout << i << "\n";
    return 0;
}