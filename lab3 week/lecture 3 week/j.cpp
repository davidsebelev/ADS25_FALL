#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool delE(vector<int>& a, int cap , int h){
    long long del = 0;
    for(int i = 0 ; i < a.size();i++){
        del += (a[i] + cap - 1)/ cap;
    }
    return del <=h;
}

int main(){
    int n , h;
    cin >> n  >> h;

    vector<int> a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    sort(a.begin(),a.end());

    int l = 1;
    int r = *max_element(a.begin(), a.end());



    while(l< r){
        int m = (l  + r)/2;
        
        if(delE(a,m,h)){
            r = m;
        }else{
            l = m + 1; // чтоб не застрять
        }
    }

    cout << r;
}