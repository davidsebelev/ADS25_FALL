#include<iostream>
#include<vector>
using namespace std;


bool check(vector<int>& a, int x){
    int l = 0;
    int r = a.size() - 1;

    while(l <= r){
        int m = (l+r)/2;

        if(a[m] == x){
            return true;
        }
        if(a[m] < x){
            l = m +1 ;
        }else{
            r = m - 1;
        }
    }
    return false;
}

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];

    int x;
    cin >> x;
    if(check(a,x)) cout << "Yes";
    else cout << "No";
    return 0;
}