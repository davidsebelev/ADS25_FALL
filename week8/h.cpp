#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long unll;

const long long mod1 = 1e9+7;
const long long mod2 = 1e9+9;

const long long p1 = 29;
const long long p2 = 31;

const long long p_pow1 = 29;
const long long p_pow2 = 31;

vector<long long> arr_h (string s,long long p, long long modm, long long p_pow){
    long long n = s.size();
    vector<long long> h(n);

    h[0] = s[0];

    for(int i = 1; i < n;i++){
        h[i] = (h[i-1] + s[i]*p_pow)%modm;
        p_pow = (p_pow*p)%modm;
    }

    return h;
};


pair<ll,ll> double_hash(string s){
        vector<ll> v_h1 = arr_h(s,p1,mod1,p_pow1);
        vector<ll> v_h2 = arr_h(s,p2,mod2,p_pow2);

        return {v_h1.back(),v_h2.back()};
}

unordered_set<unll> get_all_subh(
    const string &s,
    const vector<ll> &h1, const vector<ll> &h2,
    const vector<ll> &p1, const vector<ll> &p2,
    ll mod1, ll mod2,
    unordered_map<unll, string> &hash_to_str
){
    int n = s.size();
    unordered_set<unsigned long long> d;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            ll hash1 = h1[j];
            ll hash2 = h2[j];

            if (i > 0) hash1 = (hash1 - h1[i-1] + mod1) % mod1;
            if (i > 0) hash2 = (hash2 - h2[i-1] + mod2) % mod2;


            unsigned long long combined =
                (static_cast<unsigned long long>(hash1) << 32) ^ hash2;

            d.insert(combined);

            if (!hash_to_str.count(combined)) {
                hash_to_str[combined] = s.substr(i, j - i + 1);
            }
        }
    }
    return d;
}

int main(){

    int k;
    cin >> k;
    vector<string> w(k);
    long long sizeW  = LLONG_MIN;
    for(int i = 0 ; i < k ; i++){
        cin >> w[i];
        sizeW = max(sizeW,(ll)w[i].size());
    }
    ll n = sizeW;
    vector<long long> pp1(n), pp2(n);
    pp1[0] = pp2[0] = 1;

    for (int i = 1; i < n; i++) {
    pp1[i] = (pp1[i-1] * 29) % mod1;
    pp2[i] = (pp2[i-1] * 31) % mod2; 
    }


    vector<unordered_set<unll> > group(k);
    unordered_map<unsigned long long, string> hash_to_str;

    for(int i = 0 ; i < k ; i++){
        vector<ll> h1 = arr_h(w[i],p1,mod1,p_pow1);
        vector<ll> h2 = arr_h(w[i],p2,mod2,p_pow2);


        unordered_set<unll> f = get_all_subh(w[i],h1,h2,pp1,pp2,mod1,mod2,hash_to_str);

        group[i] = f;
    }

    string best = "";
for (int i = 0; i < k; i++) {
    for (int j = i + 1; j < k; j++) {
        for (auto hash : group[i]) {
            if (group[j].count(hash)) {
                string sub = hash_to_str[hash];
                if (sub.size() > best.size())
                    best = sub;
            }
        }
    }
}

cout << best;



    
    


    


    return 0;
}