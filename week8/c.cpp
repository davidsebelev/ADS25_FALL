#include<bits/stdc++.h>
using namespace std;

const long long modulo = 1e9 +7;


long long get_h(string s){
    long long h = 0;
    long long p = 29;
    long long p_pow = 1;

    for(int i = 0 ; i < s.size();i++){
        h = (h + s[i]*p_pow)%modulo;
        p_pow = (p_pow*p)%modulo;
    }
    return h;
}


vector<long long> arr_h(string s){
    long long n = s.size();
    vector<long long> h(n);

    h[0]=s[0];
    long long p = 29;
    long long p_pow = 29;
    for(int i = 1 ; i < n ;i++){
        h[i] = ( h[i-1] + s[i]*p_pow)%modulo;
        p_pow = (p_pow*p)%modulo;
    }
    return h;
}

int main(){
    string s;
    cin >> s;

    

    vector<long long> h = arr_h(s);

    long long n = s.size();
    vector<long long> covered(n,false);




    vector<long long> p(n);
    p[0] = 1;
    for(int i = 1; i < n;i++){
        p[i] = (p[i-1]*29)%modulo;
    }

    int q;
    cin >> q;
    int t = q;
    while(q--){
        string s2;
        cin >> s2;

        long long m = s2.size();
        long long s2_hash = get_h(s2);

        for(int i = 0; i < n - m + 1; i++){
            int j = i + m -1 ;

            long long hash = h[j];

            if(i > 0){hash = (hash - h[i-1] + modulo)%modulo;}

            if(hash == ((s2_hash*p[i])%modulo + modulo)%modulo){
                for(int k = i ; k < i + m; k++){
                    covered[k]=true;
                }
            }
        }
    }

    bool fl = true;
    for(int i = 0 ; i < covered.size();i++){
        if(covered[i]==false){
            fl = false;
            break;
        }
    }

    if(fl) cout << "YES";
    else cout << "NO";


    return 0;
}