#include<bits/stdc++.h>
using namespace std;


//for pattern hashing string t for ex
int get_h(string s){
    int h = 0;
    int p = 31;
    int p_pow = 1;

    for(int i = 0; i < s.size();i++){
        h += s[i]*p_pow;
        p_pow*=p;
    }
    return h;
}

//making arr of prefix hashs
vector<int> arr_h(string s){
    int n =s.size();
    vector<int> h(n);

    int p_pow = 31;
    int p = 31;

    h[0] = s[0];
    for(int i = 1 ; i < n ;i++){
        h[i] = h[i-1] + s[i]*p_pow;
        p_pow*=p;
    }
    return h;
}



// disticnt substrings 
//abc 
// a ab abc

int main(){
    string s,t;
    cin >> s >> t;


    int n = s.size();
    int m = t.size();

    int h_t = get_h(t);
    vector<int> h = arr_h(s);

    vector<int> p(n);
    p[0] = 1;
    for(int i = 1 ; i < n ; i++)p[i] = p[i-1]*31;

    for(int i = 0 ; i < n - m + 1;i++){
        int j = i + m  - 1;
        int h_t_j = h[j];

        if(i > 0)h_t_j -=h[i-1];
        if(h_t_j == h_t*p[i])cout << i << " ";
    }
    return 0;
}