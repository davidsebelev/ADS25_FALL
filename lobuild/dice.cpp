#include<bits/stdc++.h>
using namespace std;

//sum of two oposite sides dice is equal to 7
// 1 and 6
// 2 and 5
// and etc

int dice(int x){
    int d = 7 - x;
    return d;
}

int main(){
    int x;
    cin >> x;

    cout << dice(x) << "\n";
    return 0;
}