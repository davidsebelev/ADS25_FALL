#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    vector<int> c;

    while(t--){
        int n;
        cin >> n;

        int b = n /2 ;

        if((n&1) == 0){
            cout << b - 1 << "\n";
        }else{
            cout << b << "\n";
        }

    }    
    
    return 0;
}