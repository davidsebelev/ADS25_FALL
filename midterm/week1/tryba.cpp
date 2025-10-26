#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


bool check(vector<int> &a, ll m, ll v){
    ll total = 0;
    for(int i = 0 ; i < a.size();i++){
        total+=m/a[i];
    }
    return total >= v;
}


int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0 ; i < n ;i++) cin >> a[i];
    sort(a.begin(),a.end());

    ll v;
    cin >> v;


    ll l = -1;
    ll r = 1e18;

    while(r - l > 1){
        ll m = (l + r)/2;
        if(check(a,m,v)){
            r = m;
        }else{
            l = m;
        }
    }

    cout << r;



    return 0;
}