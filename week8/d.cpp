#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

ll get_h(string s){
    ll h = 0;
    ll p = 29;
    ll p_pow = 1;

    for(int i = 0 ; i < s.size();i++){
         h = (h + (s[i] - 'a' + 1) * p_pow) % MOD;
        p_pow= (p_pow *p)%MOD;
    }

    return h;
}


vector<ll> st_h(string s){
    ll n = s.size();
    vector<ll> h(n);

    h[0]=s[0];
    ll p = 29;
    ll p_pow = 29;

    h[0] = (s[0] - 'a' + 1) % MOD;

    for(int i = 1 ; i < n ;i++){
        h[i] = (h[i - 1] + (s[i] - 'a' + 1) * p_pow) % MOD;
        p_pow = (p_pow * p) % MOD;
    }
    return h;
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    //создал массив чтобы не считать лишний раз
    vector<ll> p(1e5+10);
    p[0] = 1;
    for(int i = 1 ; i < p.size();i++){
        p[i] = (p[i-1]*29)%MOD;
    }



    while(true){
        // вводится количество паттернов
        int q;
        cin >> q;

        int safe = q;

        if(q == 0)break;

        vector<string> ppp;// создается маасив для паттернов чтобы потом туда зщакинуть из
        while(q--){//кидаем
            string pattern;
            cin >> pattern;
            ppp.push_back(pattern);
        } 


        //дается слово 

        string word;
        cin >> word;
        ll n = word.size();
        vector<ll> h = st_h(word);

        vector<ll> frq(safe,0);
        for(int z = 0 ; z  < ppp.size();z++){
            ll h_t = get_h(ppp[z]);

            ll m = ppp[z].size();

            ll cnt = 0;
            
            for(int i = 0;  i < n - m + 1;i++){
                ll j = i + m - 1;
                ll h_t_j = h[j];
                if(i > 0)h_t_j = (h_t_j -  h[i-1] + MOD)%MOD;
                if(h_t_j == (h_t*p[i])%MOD){
                    cnt++;
                    }
            }
            frq[z] = cnt;
        }
            ll maxx = 0;

            for(ll x : frq){
                maxx = max(x,maxx);
            }

            cout << maxx << "\n";

            for(int i = 0 ; i < safe ; i++){
                if(frq[i] == maxx){cout << ppp[i] << "\n";}
            }
    }
    return 0;
}