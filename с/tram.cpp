#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int sum = 0;
    int maxSum = INT_MIN;
    while(n--){
        int a,b;
        cin >> a >> b;

        sum += b - a;
        maxSum = max(maxSum,sum);
    }
    cout << maxSum;
    return 0;
}