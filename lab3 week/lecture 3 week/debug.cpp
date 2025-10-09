#include<iostream>
#include<vector>
using namespace std;


int main(){
    int n,m;
    cin >> n >> m;

    vector<int> a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];

    vector<int> pref(n);
    pref[0] = a[0];
    for(int i = 1; i < n ;i++){
        pref[i] = pref[i-1]+ a[i];
    }

    while(m--){
        int x;
        cin >> x;
    int l = -1;
    int r = n;

    while(l + 1 < r){
        int m = (l + r)/2;
        if(pref[m] >= x){
            r = m;
        }else{
            l = m;
        }
    }
    cout << r + 1 << "\n";     
    }
    return 0;
}