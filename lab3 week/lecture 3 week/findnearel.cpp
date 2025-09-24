#include<iostream>
using namespace std;

int find_l(vector<int>& a, int x){
    int l = -1;
    int r = a.size();

    while(l + 1<  r){
        int m = (l+r)/2;
        if(a[m] <= x){
            l = m;
        }else{
            r = m;
        }
    }
    return l;
}


int find_r(vector<int>& a, int x){
    int l = -1;
    int r = a.size();

    while(l + 1 <  r){
        int m = (l+r)/2;
        if(a[m] < x){
            l = m;
        }else{
            r = m;
        }
    }
    return r;
}

bool find_el(vector<int>& a, int x){
    int t = find_l(a,x);
    return t>=0 && a[t] == x;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    
    while(k--){
        int x;
        cin >> x;

        //  cout << find_l(a,x) + 1 << endl;
        cout << find_r(a,x)  +1 << endl;

        // if(find_l(a,x)){
        //     cout << "YES" << endl;
        // }else{
        //     cout << "NO" << endl;
        // }
    }
    return 0;
}