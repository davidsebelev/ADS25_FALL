#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n ;i++)cin >> a[i];

    int maxx = INT_MIN;
    int minn = INT_MAX;
    for(int i = 0 ; i < n ;i++){
        maxx = max(maxx,a[i]);
        minn = min(minn,a[i]);
    }


    int cnt = 0;
    int max_i = 0;
    int min_i = 0;


    for(int i = 0 ; i < n ;i++){
        if(a[i] == maxx){
            max_i = i;
        }
        else if(a[i] == minn){
            min_i = i;
        }
    }

    int cnt = 0;
    int i = 0;
        while(max_i != 0){
            swap(a[max_i],a[i]);
            max_i = i;
            cnt++;
            i++;
        }


    cout << cnt;
    cout <<"\n";

    for(auto i : a) cout << i << " ";
    
    
    return 0;
}