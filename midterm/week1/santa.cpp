#include<bits/stdc++.h>
using namespace std;

bool check(vector<int> &a, int m, int f){
    int total = 0;
    for(int i = 0 ; i < a.size();i++){
        total+=(a[i] + m - 1)/m;
    }
    return total <= f;
}

int main(){
    int n,f;
    cin >> n >> f;

    vector<int> a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];

    int l =  -1;

    int r = INT_MIN;
    for(int i = 0 ; i < n ; i++) r = max(r,a[i]);
    


    while(r - l >1){
        int m = (l + r)/2;

        if(check(a,m,f)){
            r = m;
        }else{
            l = m;
        }
    }

    cout << r;
    
    return 0;
}