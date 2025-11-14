#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    set<int> d;

    int n;
    cin >> n;

    for(int i = 0 ; i < 2 ; i++){
        int a;
        cin >> a;
        while(a--){
            int x;
            cin >> x;
            d.insert(x);
        }
    }

    if(n == d.size())cout << "I become the guy.";
    else cout << "Oh, my keyboard!";
    
    return 0;
}