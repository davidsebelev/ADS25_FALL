#include<iostream>
#include<vector>
using namespace std;

const int  N = 2e5;



int main(){
    int n, k;
    cin >> n >> k;
    
    int x1[N], y1[N], x2[N], y2[N];

    for(int i = 0 ; i < n ;i++) cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];

    int l = 0;
    int r = 1e9;

    while(l +  1 < r){
        int m = (l + r)/2;
        
        int cnt = 0;
        for(int i = 0 ; i < n ;i++){
            if(x2[i] <= m and y2[i]<= m) cnt++;
        }

        if(cnt>=k) r = m;
        else l = m;
    }

    cout << r;


    return 0;
}