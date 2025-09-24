#include<iostream>
using namespace std;


bool bin_s(vector<int>& a, int x){
    int left = 0;
    int right = a.size() - 1;

    while(left<=right){
        int middle = (left + right) / 2;

        if(a[middle] == x){
            return true;
        }
        if(a[middle] < x){
            left = middle + 1;
        }
        if(a[middle] > x){
            right = middle - 1;
        }
    }
    return false;
}

int main(){
    int n,k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0 ; i < n ;i++) cin >> a[i];

    while(k--){
        int x;
        cin >> x;

        if(bin_s(a,x)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }

    }
}