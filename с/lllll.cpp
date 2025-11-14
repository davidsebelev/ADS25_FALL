#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> p = {100,20,10,5,1};

    int cnt = 0;

    cout << n % 100;

    // cout << n%p[0];
    for(int i = 0 ; i < p.size();i++){
        while(n >= p[i]){
            n = n%p[i];
            cnt++;
            //cout << n << " ";
        }
    }
    cout << cnt;
    
    return 0;
}