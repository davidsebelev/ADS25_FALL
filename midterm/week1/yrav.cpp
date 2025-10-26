#include<bits/stdc++.h>
using namespace std;


int main(){
    double l = 1.0;
    double r = 2.0;
    double eps = 1e-9;// так как у нас в минусовой


    while(r - l > eps){ // поэтому делаем границы уже пока больше епсилона
        double m = (l + r)/2.0;

        if(m * m * m - m - 1 > 0){
            r = m;
        }else{
            l = m;
        }
    }

    cout << r;
    return 0;
}