#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(vector<int> &a,int m, int h){
    ll total =  0;
    for(int i = 0 ; i < a.size();i++){
        total += (a[i]+m -1)/m;
    }

    return total <= h;
}

int main(){
    int n,h;
    cin >> n >> h;

    vector<int> a(n);
    for(int i = 0 ; i < n ;i++) cin >> a[i];

    ll l = -1;
    ll r = 1e9;

    while(r - l >1){
        ll m = (l + r)/2;

        if(check(a,m,h)){
            r = m;
        }else{
            l = m;
        }
    }

    cout << r;

    return 0;
}