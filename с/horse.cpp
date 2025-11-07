#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 4;
    set<int> h;
    while(n--){
        int s;
        cin >> s;
        h.insert(s);
    }

    cout << 4 - h.size();
    return 0;
}