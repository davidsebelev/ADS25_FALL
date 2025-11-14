#include <bits/stdc++.h>
using namespace std;

int get_h(string s){
    int h = 0;

    int p = 29;
    int p_pow = 1;

    for(int i = 0 ; i < s.size();i++){
        h+= s[i]*p_pow;
        p_pow*=p;
    }
    return h;
}

vector<int> arr_h(string s){
    int n = s.size();
    vector<int> h(n);

    h[0] = s[0];
    int p = 29;
    int p_pow = 29;
    for(int i = 1; i < n;i++){
        h[i] = h[i - 1] + s[i]*p_pow;
        p_pow*=p;
    }

    return h;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    string a, b;
    cin >> a >> b;

    vector<int> h = arr_h(a);

    int n = a.size();
    int m = b.size();


    vector<int> p(n);
    p[0] = 1;
    for(int i =  1; i < n; i++){
        p[i] = p[i-1]*29;
    }

    int h_s2 = get_h(b);


    for(int i = 0 ; i < n - m + 1;i++){
        int j = i + m - 1;

        int hash = h[j];

        if(i > 0)hash = hash - h[i-1];

        if(hash == h_s2*p[i])cout << i << " ";

    }


    
    return 0;
}