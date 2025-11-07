#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    string s;
    cin >> n >> s;

    int cntA = 0, cntD = 0;
    for(auto c: s){
        if(c == 'A')cntA++;
        else cntD++;
    }

    if(cntA < cntD) cout << "Danik";
    else if(cntA > cntD) cout << "Anton";
    else cout << "Friendship";
    return 0;
}