#include<bits/stdc++.h>
using namespace std;

bool check(vector<int> &a, int m , int k){
    int t = 0;
    for(int i = 0 ; i < a.size();i++){
        t += (a[i] + m -1)/m;
    }

    return t<=k;
}


int main(){
    int n,k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0 ; i < n ;i++) cin >> a[i];

    int l = -1;
    int mm = INT_MIN;
    for(int i = 0 ; i < n ;i++){
        mm = max(mm,a[i]);
    }
    int r = mm;

    while(r  - l > 1){
        int m = (l + r)/2;

        if(check(a,m,k)){
            r = m;
        }else{
            l = m;
        }

    }
    cout << r;
    return 0;
}