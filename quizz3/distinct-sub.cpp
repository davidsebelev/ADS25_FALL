#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> get_h(string s){
    int n = s.size();
    vector<ll> h(n);

    int p = 29;
    int p_pow = 29;

    h[0] = s[0];
    for(int i = 1 ; i < n ; i++){
        h[i] = h[i-1] + s[i]*p_pow;
        p_pow*=p;
    }
    return h;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;
    int n = s.size();

    vector<ll> h = get_h(s);
    vector<int> p(n);
    p[0] = 1;
    for(int i = 1; i < n ; i++){
        p[i] = p[i-1]*29;
    }    

    set<ll> dis_sub;

    for(int i = 0 ;i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            ll hash = h[j];
            if(i > 0)hash = hash - h[i-1];
            dis_sub.insert(hash);
        }
    }

    cout << dis_sub.size();
    return 0;

}