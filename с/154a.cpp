#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0 ;i < n ;i++)cin >> a[i];

    int minE = a[0];//100 // 50
    int maxE = a[0];//100
    int cnt = 0;
    for(int i = 1 ; i < n ; i++){
        if(a[i] < minE){
            minE = a[i];
            cnt++;
        }else if(a[i] > maxE){
            maxE = a[i];//50
            cnt++;//1
        }
    }
    cout << cnt;
    return 0;
}