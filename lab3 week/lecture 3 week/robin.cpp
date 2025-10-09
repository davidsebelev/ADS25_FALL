#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool check(vector<int> &a, int m, int h){
    int sum = 0;
    for(int i = 0 ; i < a.size();i++){
        sum += (m + a[i] - 1)/ m;
    }
    return sum <=h;
}

int main(){
    int n,h;
    cin >> n >> h;

    vector<int> a(n);
    for(int i = 0 ; i < n ;i++) cin >> a[i];
    sort(a.begin(),a.end());

    int l = -1;
    int r = a[n-1];
    while(l + 1 < r){
        int m = (l + r)/2;

        if(check(a,m,h)){
            r = m;
        }else{
            l = m;
        }
    }
    cout << r << "\n";

    return 0;

}