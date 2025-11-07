#include<bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
const long long P = 29;


// vector<long long> arr_h(string s){
//     int n = s.size();
//     vector<long long> h(n);

//     h[0]=s[0]%MOD;
//     long long p = 29;
//     long long p_pow = 29;

//     for(int i = 1; i < n ;i++){
//         h[i] = (h[i-1] + s[i]*p_pow)%MOD;
//         p_pow=(p_pow*p)%MOD;
//     }

//     return h;
// }

int main(){
    string s;
    cin >> s;

    int n  = s.size();


    vector<long long> p(n);
    p[0] = 1;
    for(int i = 1 ; i < n ;i++){
        p[i]=(p[i-1]*P)%MOD;
    }

    vector<long long> h(n);
    h[0] = s[0] % MOD;
    for (int i = 1; i < n; i++)
        h[i] = (h[i-1] * P + s[i]) % MOD;


    set<long long> d;


    for(int i = 0 ; i < n; i++){
        for(int j = i ; j < n ;j++){
            long long hash = h[j];

            if(i > 0) hash = ((hash - h[i-1] *p[j-i+1])%MOD + MOD)%MOD;

            

            d.insert(hash);
        }
    }

    cout << d.size();
    return 0;
}