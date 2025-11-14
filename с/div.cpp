#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int a,b;
        cin >> a >> b;
        if(a%b == 0){
            cout << 0 << "\n";
        }else{
            int q = (a + b)%a;
            int m = a%b;
            int r = q - m;

            if(r < 0)cout << b - a << "\n";
            else cout << r << "\n";
        }


        //cout << q - m << "\n";
    }
    
    return 0;
}