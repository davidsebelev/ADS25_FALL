#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        string new_w = "";
        for(auto i : s)new_w+=toupper(i);

        if(new_w == "YES")cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    
    return 0;
}