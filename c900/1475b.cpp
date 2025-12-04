#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        if(n < 2020){
            cout << "NO\n";
            continue;
        }
        if(n == 2020 || n == 2021){
            cout << "YES\n";
            continue;
        }

        bool ok = true;
        while(n%2020!=0){
            n = n-2021;
            if(n<2020)ok = false;
            if(n == 2021)break;
        }
        if(!ok)cout << "NO\n";
        else cout << "YES\n";
    }
    
    return 0;
}