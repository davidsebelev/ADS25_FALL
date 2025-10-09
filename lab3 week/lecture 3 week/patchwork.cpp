#include<iostream>
using namespace std;

int lower_b(vector<int> &a, int l){
    int left = -1;
    int right = a.size();

    while(left + 1 < right){
        int mid = (left + right) / 2;
        if(a[mid] >= l){
            right = mid;
        }else{
            left = mid;
        }
    }
    return right;
}

int upper_b(vector<int> &a, int r){
    int left = -1;
    int right = a.size();

    while(left + 1 < right){
        int mid = (left + right) / 2;
        if(a[mid] > r){
            right = mid;
        }else{
            left = mid;
        }
    }
    return right;
}


int main(){
    int n,q;
    cin >> n >> q;

    vector<int> a(n);
    for(int i = 0 ; i < n ;i++) cin >> a[i];

    while(q--){
        int l1,r1,l2,r2;
        cin >> l1 >> r1 >> l2 >> r2;

        int cnt1 = upper_b(a,r1) - lower_b(a,l1);
        int cnt2 = upper_b(a,r2) - lower_b(a,l2);

        int ans = cnt1+cnt2;

        int L = max(l1,l2); // 5 
        int R = min(r1,r2); // 6

        int cnt3 = upper_b(a,R) - lower_b(a,L);
        if(L <= R) ans =  ans - cnt3;
        cout << ans << "\n";

    }
    return 0;
}