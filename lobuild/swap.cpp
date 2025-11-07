#include<bits/stdc++.h>
using namespace std;

void swapp(int a, int b){
    int temp = a;
    a = b;
    b = temp;
    cout << a << " " << b;
}


int swRec(int x, int y, int i = 1){
    if(i == 0)return -1;
    i--;
    return swRec(y,x,i);
}


int main(){
    int a, b ;
    cin >> a >> b;
    cout << swRec(a,b);

    return 0;
}