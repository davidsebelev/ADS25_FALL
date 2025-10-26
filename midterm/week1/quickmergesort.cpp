#include<bits/stdc++.h>
using namespace std;


void quick_srt(vector<int> &a,int l , int r){
    int i = l;
    int j = r;
    int p = a[(l+r)/2];

    while(i <= j){
        while(a[i] < p)i++;
        while(a[j] > p)j--;


        if(i<=j){
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }

    if(i < r) quick_srt(a,i,r);
    if(l < j) quick_srt(a,l,j);
}


int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n; i++) cin >> a[i];
    quick_srt(a,0,a.size()-1);

    for(int i = 0 ; i < n;i++) cout << a[i] << " ";
    return 0;
}