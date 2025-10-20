#include<bits/stdc++.h>
using namespace std;

void quick_sort(string &s, int l , int r){
    int i = l;
    int j = r;
    int p = s[(l + r)/2];

    while(i < j){
        while(s[i] < p) i++;

        while(s[j] > p) j--;

        if(i <= j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }

    if(l < j) quick_sort(s,l,j);
    if(i < r) quick_sort(s,i,r);
}


int main(){
    string s;
    cin >> s;


    quick_sort(s,0,s.length()-1);

    for(int i = 0 ; i < s.length();i++) cout << s[i];


    return 0;
}