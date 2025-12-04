#include <bits/stdc++.h>
using namespace std;

int get_hash(string s){
    int n = s.size();

    int p = 29;
    int p_pow = 1;

    int h = 0;
    for(int i = 0 ; i < n ; i++){
        h+=s[i]*p_pow;
        p_pow*=p;
    }
    return h;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}