#include<bits/stdc++.h>
#include <unordered_set>

using namespace std;

const long long modulo = 1e9 + 7;
const long long ppp = 47;

long long  get_h(string s){
    long long h = 0;
    long long p = 11;
    long long p_pow = 1;

    for (char c : s) {
        h = (h + (c - ppp) * p_pow) % modulo;
        p_pow = (p_pow * p) % modulo;
    }

    return h;
}

vector<long long> arr_h(string s){
    long long n = s.size();
    long long p = 29;
    long long p_pow = 29;

    vector<long long> h(n);
    h[0]=s[0];

    for(int i = 1; i < n ;i++){
        h[i] = (h[i] - h[i-1] + s[i]*p_pow + modulo)%modulo;
        p_pow = (p_pow*p+modulo)%modulo;
    }
    return h;
}


int main(){
    int n;
    cin >> n;
    int size = 2*n;

    vector<string> s(size);
    unordered_set<string> all;


    for(int i = 0 ; i < size ; i++){
        cin >> s[i];
        all.insert(s[i]);
    }
    vector<pair<string,string> > pai;

    int cnt =0;
    for(int i = 0 ; i < size && cnt < n;i++){
        long long w = get_h(s[i]); // делаем хэш строки 
        string hash  = to_string(w);
        
        if(all.count(hash)){
             cout << "Hash of string \"" << s[i] << "\" is " << hash << "\n";
            cnt++;
        }
    }
}