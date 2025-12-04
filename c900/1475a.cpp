#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//пока число делится на 2 если оно четное то дели если остаток равен нечетному то выведи yes
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    ll n;
    while(t--){
        cin >> n;
        if(n%2 == 0){
            while(n%2==0){
                n = n /2;
            }
            if(n%2 !=0 && n!=1)cout << "YES\n";
            else cout << "NO\n";
        }else{
            cout << "YES\n";
        }
    }
    
    return 0;
}