#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<int> a(n);
        vector<int> b(n-1);

        for(int i = 0 ; i < n ; i++)cin >> a[i];
        int p = 0;
        for(int i = 0 ; i < n; i++){
            if(a[i] == -1){
                a[i] = p;
            }
        }
        for(int i = 0 ; i <= n - 1; i++){
            b[i] = a[i+1] - a[i];
        }

        int ans  = 0;
        for(auto i : b){
            ans+=i;
        }
        cout << ans;
    }
    
    return 0;
}