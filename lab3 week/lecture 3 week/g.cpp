#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;


bool canDel(vector<int>& a , int cap , int f){
    long long flight  = 0;
    for(int i = 0 ; i < a.size();i++){
        flight += (a[i] + cap - 1) / cap; // ceil
    }
    return flight <= f;
}


int main(){
    int n, f;
    cin >> n >> f;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(),a.end());

    int l = 1;
    int r = *max_element(a.begin(), a.end()); // ищет самый юольшой элемент в а
    //int cap = a[n - 1] /2;
    while(l < r){
        int m = (l + r)/ 2;


        if(canDel(a,m,f)){
            r = m; // если делится то чекаем слева может ееще делится смотреть справа нет смысла
        }else{
            l = m + 1;
        }

        //cout << r << " " << l;
    }

    cout << l;
    return 0;
}