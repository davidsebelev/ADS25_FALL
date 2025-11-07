#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int cnt = 0;
    int prev = 0;
    for(int i = 0  ; i < n ; i++){
        int curr;
        cin >> curr;
        if(i == 0 || curr!=prev){
            cnt++;
        }
        prev = curr;
    }
    cout << cnt;
    return 0;
}