#include<iostream>
using namespace std;

pair<int, int> near_el(vector<int>& a, int x){
    int l = -1;
    int r = a.size();

    while(l + 1 < r){
        int m = (l+r) / 2;
        if(a[m] <= x){
            l = m;
        }else{
            r = m;
        }
    }

    int left_val = (l >= 0 ? a[l]: INT_MIN);
    int right_val = (r < a.size() ? a[r]: INT_MAX);
    
    return make_pair(left_val, right_val);
}

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];

    int x;
    cin >> x;

    pair<int, int > res = near_el(a,x);

    cout << res.first << " " << res.second << endl;

    return 0;
}