#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t,n;
    cin >> t;
    vector<int> r;
    while(t--){
         int cnt =0;
        cin >> n;
            while(n%6 == 0){
            n = n/6;
            cnt++;
        }
        if(n == 1){
            r.push_back(cnt);
            continue;
            }
        else{
            while(n%6 != 0){
                n = n * 2;
                if(n%6!=0)break;
                n = n /6;
                cnt+=2;
                if(n == 1)break;
            }
            if(n== 1)r.push_back(cnt);
            else r.push_back(-1);
     } 
}
for(auto i : r)cout << i << "\n";
return 0;
}