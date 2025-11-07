#include<bits/stdc++.h>
using namespace std;

bool bin_s(vector<int> &a,int x){
    int l = 0;
    int r = a.size()-1;

    while( l <= r){
        int m = (l+r)/2;

        if(a[m]==x)return true;
        else if(a[m] < x)l = m+1;
        else r = m-1;
    }
    return false;
}


int main(){
    int n,q;
    cin >> n >> q;

    vector<int> a(n);
    for(int i = 0 ; i  < n ;i++)cin >> a[i];

    sort(a.begin(), a.end());

    while(q--){
        int x;
        cin >> x;

        if(bin_s(a,x)){
            int pos = lower_bound(a.begin(),a.end(),x)-a.begin();
            cout << pos + 1 << "\n";
        }else{
            cout << -1 << "\n";
        }
    }


    return 0;
}