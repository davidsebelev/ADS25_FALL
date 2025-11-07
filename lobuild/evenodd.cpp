//Given a number n, check whether it is even or odd. Return true for even and false for odd.

#include<bits/stdc++.h>
using namespace std;


//naive approach 
bool check(int x){
    if(x%2 == 0)return true;
    else return false;
}

//efficient approach
// bit of odd num is always 1 , even 0
// odd 1 , even 0

// так как последняя цифра четного всегда равна нулю
// берем операцией последнее и так находим


bool evenOdd(int x){
    if((x & 1) == 0) return true;
    else return false;
}

int main(){
    int x;
    cin >> x;

    if(evenOdd(x)) cout << "true";
    else cout << "false";

    return 0;
}