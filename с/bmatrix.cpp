#include<bits/stdc++.h>
using namespace std;


// решение чата 
int find(int a[5][5]){
    for(int i = 0 ; i < 5 ; i++){
        for(int j = 0 ; j < 5 ; j++){
            cin >> a[i][j];
        }
    }

    int f = 0;
    int s = 0;


    for(int i = 0 ; i < 5 ; i++){
        for(int j = 0 ; j < 5 ; j++){
            if(a[i][j] == 1){
                f = i;
                s = j;
                break;
            }
    }


    cout << abs(f - 2) + abs(s -2);
}
}

int main(){
    int a[5][5];
    for(int i = 0 ; i < 5 ; i++){
        for(int j = 0 ; j < 5 ; j++){
            cin >> a[i][j];
        }
    }


    int f = 0;
    int s = 0;
    
    for(int i = 0 ; i < 5 ; i++){
        for(int j = 0 ; j < 5 ; j++){
            if(a[i][j] == 1){
                f = i;
                s = j;
                break;
            }
    }
    }
    int cnt = 0;
    while( f != 2){
        if(f < 2){
            f++;
            cnt++;
        }else{
            f--;
            cnt++;
        }
    }

    while(s != 2){
        if(s < 2){
            s++;
            cnt++;
        }else{
            s--;
            cnt++;
        }
    }

    cout << cnt;

    




    return 0;
}