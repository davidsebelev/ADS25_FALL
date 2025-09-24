#include<iostream>
#include<vector>
using namespace std;


int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i ++) cin >> a[i];

    double l = 0; // we can
    double r = 1e8; // we cant take

    for(int t = 0 ; t < 100; t++){
        double m = (l + r) / 2;

        int s = 0;
        for(int i = 0 ; i < n ;i++){
            s += (int)(a[i]/ m);// скок от итой веревочки можно получить кусков m
        }
        if(s>=k){
            l = m;
        }else{
            r = m;
        }
    }

    cout << l << " " << r << endl;


    return 0;
}