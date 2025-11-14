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
    int p = 1;
    vector<int> num;
    while(n > 0){
        if(n%10>0)num.push_back(n%10*p);
        n = n/10;
        p = p *10;
    }
    cout << num.size() <<"\n";
    for(auto i : num) cout << i << " ";
    cout << "\n";
    }
   
    return 0;
}