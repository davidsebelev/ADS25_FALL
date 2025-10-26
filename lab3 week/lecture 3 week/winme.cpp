#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main(){


    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n ;i++) cin >> a[i];
    sort(a.begin(),a.end());


    vector<int> pref(n);
    pref[0] = a[0];
    for(int i = 1 ; i < n ; i++){
        pref[i] = pref[i-1] + a[i];
    }


    int q;
    cin >> q;
    while(q--){
        int p;
        cin >> p;

        int l = -1;
        int r = a.size();

        while(l + 1 < r){
            int m = (l+r)/2;
            if(a[m] > p){
                r = m;
            }else{
                l = m;
            }
        }
        cout << r << " " << pref[r-1] << "\n";
    }
    return 0;
}