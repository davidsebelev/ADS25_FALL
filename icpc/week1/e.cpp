#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main(){
    int a, b;
    cin >> a >> b;

    vector<bool> p(b + 1, true);
    p[0] = p[1] = false;


    // заполнили от 2 до б
    for(int i = 2 ; i * i <= b ; i++){
       if(p[i]){
            for(int j = i * i ; j <= b; j+=i){
                p[j] = false;
            }
        } 
    }

    for(int i = a ; i <= b;i++){
        if(p[i]) cout << i << " ";
        //cout << p << " ";
    }
    return 0;
}