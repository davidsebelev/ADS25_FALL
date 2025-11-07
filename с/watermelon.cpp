#include<iostream>
using namespace std;

int main(){
    int w;
    cin >> w;

    if(w < 0){ cout << "NO";return 0;}

    int f = 0;
    int s = 0;

    if((w&1) == 0){
        f = w/2 ;
        s = w - f;
        if((f&1) == 0 && (s&1)==0 && s!=0) cout << "YES";
        else{
            f = f - 1;
            s = s + 1;
            if((f + s == w) && ((f&1) == 0 && ((s & 1) == 0)) && (f != 0 && s!=0)) cout << "YES";
            else cout << "NO";
        }
    }else{cout << "NO";}
    return 0;
}