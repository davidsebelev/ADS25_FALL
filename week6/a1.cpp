#include<bits/stdc++.h>
using namespace std;


bool vowelCheck(char a){
    return a == 'e' || a == 'a' || a == 'i' || a == 'o' || a == 'u';
}

void quick_sort(vector<char> &v,int l, int r){
    int i = l;
    int j = r;
    int p = v[(l+r)/2];

    while(i < j){
        while(v[i] < p)i++;

        while(v[j] > p)j--;

        if(i <=j){
            swap(v[i],v[j]);
            i++;
            j--;
        }
    }

    if(l < j) quick_sort(v,l,j);
    if(i < r) quick_sort(v,i,r);
}

void quick_sort2(vector<char> &c,int l, int r){
    int i = l;
    int j = r;
    int p = c[(l+r)/2];

    while(i < j){
        while(c[i] < p)i++;

        while(c[j] > p)j--;

        if(i <=j){
            swap(c[i],c[j]);
            i++;
            j--;
        }
    }

    if(l < j) quick_sort2(c,l,j);
    if(i < r) quick_sort2(c,i,r);
}


int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<char> v;
    vector<char> c;
    for(int i = 0 ;i < n;i++){
        if(vowelCheck(s[i]))v.push_back(s[i]);
        else c.push_back(s[i]);
    }

    if(!v.empty() && !c.empty()){
    int l = 0;
    int r = v.size()-1;
    quick_sort(v,l,r);

    int l2 = 0;
    int r2 = c.size()-1;
    quick_sort2(c,l2,r2);

    for(int i = 0 ; i < v.size();i++) cout << v[i];
    for(int i = 0 ; i < c.size();i++) cout << c[i];
    }else{
        if (!v.empty()){
        int l = 0;
        int r = v.size()-1;
        quick_sort(v,l,r);
        for(int i = 0 ; i < v.size();i++) cout << v[i];
        }else{
        int l2 = 0;
        int r2 = c.size()-1;
        quick_sort2(c,l2,r2);
        for(int i = 0 ; i < c.size();i++) cout << c[i];
        }
    }
    // int l = 0;
    // int r = v.size()-1;
    // quick_sort(v,l,r);

    // int l2 = 0;
    // int r2 = c.size()-1;
    // quick_sort2(c,l2,r2);

    // for(int i = 0 ; i < v.size();i++) cout << v[i];
    // for(int i = 0 ; i < c.size();i++) cout << c[i];


    return 0;
}