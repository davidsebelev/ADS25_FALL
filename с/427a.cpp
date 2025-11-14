#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int sum = 0;
    int t_sum = 0;
    while(n--){
        int x;
        cin >> x;
        if(x > 0){
            sum+=x;
        }else if(x == -1){
            if(sum!=0)sum--;
            else t_sum++;
        }
    }
    cout << t_sum;
    
    return 0;
}