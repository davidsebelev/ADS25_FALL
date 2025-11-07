#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    bool ok = true;
    while(t--){
        int x;
        cin >> x;
        if(x ==1){
            ok = false;
            break;
        }
    }
    if(ok)cout << "EASY";
    else cout << "HARD";
    return 0;
}