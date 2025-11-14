#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int p[] = {100,20,10,5,1};


    int cnt = 0;
    for(int i = 0 ; i < 5;i++){
        cnt += n/p[i];
        n%=p[i];
    }

    cout << cnt;
    
    return 0;
}