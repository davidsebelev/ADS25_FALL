#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, h;
    cin >> n >> h;

    int sum = 0;
    for(int i = 0 ; i < n ;i++){
        int x;
        cin >> x;

        if(x <= h)sum+=1;
        else sum+=2;
    }
    cout << sum;
}