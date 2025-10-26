#include<iostream>
#include<vector>
using namespace std;

bool check(vector<int> &pref,int m,int k){
    bool ok =0;
    for(int i = 0 ; i + m <= pref.size(); i++){
            if(pref[i+m] - pref[i] >=k){
                ok = 1;
                break;
            }
        }

    return ok;
}

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i =0 ; i < n ; i++)cin >> a[i];

    vector<int> pref(n+1);
    pref[0] = 0;
    for(int i = 1 ; i <= n ;i++) pref[i] = pref[i-1 ] + a[i-1];

    int l = 0;
    int r = n + 1;

    while(l + 1 < r){
        int m = (l+r)/2;
        
        if(check(pref,m,k)){
            r = m;
        }else{
            l = m;
        }  
    }
    if(r == n + 1) cout << 0;
    else cout << r;

}