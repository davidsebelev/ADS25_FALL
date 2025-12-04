#include <bits/stdc++.h>
using namespace std;

vector<int> get_h(string s){
    int n = s.size();
    vector<int> h(n);

    int p_pow = 29;
    int p = 29;

    h[0] = s[0];
    for(int i = 1;  i < n ; i++){  
        h[i] = h[i-1] + s[i]*p_pow;
        p_pow*=p;
}
    return h;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}