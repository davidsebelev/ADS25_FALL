#include<bits/stdc++.h>
using namespace std;

bool isPower(int x, int y){

    if(x == 1)
       return y == 1;

    long long pow = 1;
    while(pow < y){
        pow *=x;
    }

    return (pow == y);
}

bool logPower(int x , int y){
    int res =  log(y)/log(x);
    return res == floor(res);

}


int main(){
    int x, y;
    cin >> x >> y;

    cout << isPower(x,y);

    return 0;
}