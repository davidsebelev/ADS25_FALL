#include<iostream>
#include<vector>
using namespace std;

// bool CheckCapacity(int childrenQuantity){

// // }

int main(){
    int n, p;
    cin >> n >> p;

    vector<int> a(n);
    for(int i = 0 ; i < n ;i++) cin >> a[i];
    sort(a.begin(),a.end());

    int l = -1;
    int r = 1e4;
    int cnt = 0;
    while(l + 1 < r){
        int m = (l + r)/ 2;
        for(int i = 0 ; i < n ;i++){
            if(a[i] < m) cnt++;
        }
        if(cnt >=p) r = m;
        else l = m;
    }

    cout << cnt;

    return 0;
}