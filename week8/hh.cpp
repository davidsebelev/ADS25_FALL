#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const long long pw1 = 29;
const long long pw2 = 31;

const long long mod1 = 1e9+7;
const long long mod2 = 1e9+9;

pair<vector<ll>,vector<ll> > pref_hash(const string &s, ll mod , ll pw){
    ll n = s.size();
    vector<ll> h(n + 1, 0);
    vector<ll> p(n + 1, 1);

    for(int i = 0 ; i < n ; i++){
        h[i + 1] = (h[i] * pw + s[i]) % mod;
        p[i + 1] = (p[i]*pw)%mod;
    }

    return {h,p};
} 

ll get_sub_interval_hash(vector<ll> &h, vector<ll> &p, int i, int j,ll mod){
    return ((h[j]-h[i] * p[j - i])%mod + mod)%mod;
}

string get_common_substring(
    vector<string> &a,
    int len
){
    if(len == 0)return "";

    unordered_set<ull> common;
    bool fl = true;

    for(const string &s : a){
        auto[h1,p1] = pref_hash(s,mod1,pw1);
        auto[h2,p2] = pref_hash(s,mod2,pw2);

        unordered_set<ull> current;

        for(int i = 0 ; i + len <= (int)s.size();i++){
            ll hsh1 = get_sub_interval_hash(h1,p1,i,i+len,mod1);
            ll hsh2 = get_sub_interval_hash(h2,p2,i,i+len,mod2);

            ull one_hash  = (ull(hsh1) << 32)^hsh2;
            current.insert(one_hash);
        }

        if(fl){
            common = move(current);
            fl = false;
        }else{
            unordered_set<ull> next;
            for(auto h:current){
                if(common.count(h))next.insert(h);
            }
            common = move(next);
            if(common.empty())return "";
        }
    }


    auto[h1,p1] = pref_hash(a[0],mod1,pw1);
    auto[h2,p2] = pref_hash(a[0],mod2,pw2);

    for(int i = 0 ; i + len <= (int)a[0].size();i++){
        ll hsh1 = get_sub_interval_hash(h1,p1,i,i+len,mod1);
        ll hsh2 = get_sub_interval_hash(h2,p2,i,i+len,mod2);

        ull one_hash  = (ull(hsh1) << 32)^hsh2;
        if(common.count(one_hash)){
            return a[0].substr(i,len);
        }
    }
    return "";
    }

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;
    vector<string> a(k);
    for(int i = 0 ; i < k;i++)cin >> a[i];

    int l = 0;
    int r = INT_MAX;

    for(auto  &s:a) r = min(r,(int)s.size());

    int ans_len = 0;
    string ans = "";

    while(l<=r){
        int m = (l + r) /2;

        string res = get_common_substring(a,m);
        if(!res.empty()){
            ans = res;
            ans_len = m;
            l = m +1;
        }else{
            r = m - 1;
        }
    }

    cout << ans;
    return 0;
}