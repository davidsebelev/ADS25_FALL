#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &a, long long m , int k){
    long long sum = 0;
    int cnt = 1;
    for(int i = 0; i < a.size(); i++){
        if(sum + a[i] > m){
            cnt++;
            sum = a[i];
        } else {
            sum += a[i];
        }
    }
    return cnt <= k;
}

int main(){
    int n, k;
    cin >> n >> k;
    long long mx = LLONG_MIN;
    long long sum = 0;

    vector<int> a(n);
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
        sum += a[i];
        mx = max(mx, (long long)a[i]);
    }

    long long l = mx;
    long long r = sum;

    while(l < r){
        long long m = (l + r) / 2;
        if(check(a, m, k)) r = m;
        else l = m + 1;
    }

    cout << l << endl;
    return 0;
}
