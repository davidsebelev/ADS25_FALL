#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

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

int main(){
    string s;
    cin >> s;

    long long n =s.size();

    vector<ll> h1 = arr_h(s,p1,mod1,p_pow1);
    vector<ll> h2 = arr_h(s,p2,mod2,p_pow2);
    

    vector<long long> p1(n), p2(n);
    p1[0] = p2[0] = 1;

    for (int i = 1; i < n; i++) {
    p1[i] = (p1[i-1] * 29) % mod1;
    p2[i] = (p2[i-1] * 31) % mod2; 
    }

    unordered_set<unsigned long long> d;
    for(int i = 0 ; i < n ;i++){
        for(int j = i ; j < n ;j++){
            ll hash1 = h1[j];
            ll hash2 = h2[j];
            if(i > 0) hash1 = (hash1 - h1[i-1]+mod1)%mod1;
            hash1 = (hash1 * p1[n-1-j])%mod1;
            if(i > 0) hash2 = (hash2 - h2[i-1]+mod2)%mod2;
            hash2 = (hash2 * p2[n-1-j])%mod2;

            unsigned long long combined =
            (static_cast<unsigned long long>(hash1) << 32) ^ hash2;

            d.insert(combined);
        }
    }

    cout << d.size();


    return 0;
}