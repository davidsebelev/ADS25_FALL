//lower bound первое упоминание 
// upper bound последнее упоминание 


#include<bits/stdc++.h>
using namespace std;


int lb(vector<int>& a, int x){
    int l = 0, r = (int)a.size(); // [l, r)
    while(l < r){
        int m = l + (r - l)/2;
        if(a[m] < x) l = m + 1;
        else         r = m;
    }
    return l; // индекс первого >= x (может быть == a.size())
}


int rb(vector<int>&a , int x ){
    int l = 0;
    int r = a.size();

    while( l < r){
        int m = (l+r)/2;
        if(a[m] <=x) l = m+1;
        else r = m;
    }

    return l;
}



int main(){
    return 0;
}