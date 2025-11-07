#include<bits/stdc++.h>
using namespace std;

const long long modd = 1e9 + 7;

string get_s(vector<long long>& h){
    int n = h.size();
    string s = "";

    int p = 97;
    int p_pow = 2;

    char f = char((h[0] + 97)%modd);
    s.push_back(f);
    for(int i = 1 ; i < n ;i++){
        s += char((((h[i]-h[i-1])/p_pow) + 97)%modd);
        p_pow= (p_pow*2)%modd;
    }
    return s;
}

int main(){
    int n;
    cin >> n;

    vector<long long> h(n);
    for(int i = 0; i < n ;i++)cin >> h[i];

    string s = get_s(h);
    cout << s;




    return 0;
}