#include <bits/stdc++.h>
using namespace std;

int has(string s){
    int h = 0;
    int p_pow = 1;
    int p = 29;

    for(int i = 0 ; i <s.size();i++){
        h += s[i]*p_pow;
        p_pow*=p;
    }
    return h;
}


vector<int> pref_h(string s){
    int n = s.size();
    vector<int> h(n);

    h[0]=s[0];
    int p = 29;
    int p_pow = 29;;

    for(int i = 1 ; i  <n ;i++){
        h[i] = h[i-1] + s[i]*p_pow;
        p_pow*=p;
    }
    return h;


}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1,s2;
    cin >> s1 >> s2;


    int n = s1.size();
    int m = s2.size();

    vector<int> p(n);
    p[0] = 1;
    for(int i = 1; i < n ; i++){
        p[i] = p[i-1]*29;
    }

    int ha = has(s2);
    vector<int> h = pref_h(s1);

    for(int i = 0; i < n - m + 1; i++){
        int j = i + m - 1;

        int hash = h[j];
        if(i > 0){
            hash = hash - h[i-1];
        }

        if(hash == ha*p[i]){
            cout << i << " ";
        }


    }



    
    return 0;
}