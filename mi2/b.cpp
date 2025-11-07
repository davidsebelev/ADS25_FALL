#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 1 ; i <= n ; i++) cin >> a[i];

    vector<int> r;
    for(int i = 1 ; i <= n ; i++){
        if(i%2 == 0)r.push_back(a[i]);
    }

    cout << r.size() << "\n";
    for(int i = 0 ; i < r.size();i++){
        cout << r[i] << " ";
    }

    
}