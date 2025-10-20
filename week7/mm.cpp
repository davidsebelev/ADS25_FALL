#include <iostream>
#include <vector>
using namespace std;

void mergesss(vector<int> &a,int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1);
    vector<int> R(n2);

    for(int i = 0 ; i < n1 ;i++) L[i] = a[l+i];
    for(int j = 0 ; j < n2 ;j++) R[j] = a[m+1+j];

    int uk1 = 0;
    int uk2 = 0;
    int k = l;

    while(uk1 < n1 && uk2 < n2){
        if(L[uk1] <= R[uk2]){
            a[k] = L[uk1];
            uk1++;
        }else{
            a[k] = R[uk2];
            uk2++;
        }
        k++;
    }

    while(uk1 < n1){
        a[k] = L[uk1];
        uk1++;
        k++;
    }
    while(uk2 < n2){
        a[k] = R[uk2];
        uk2++;
        k++;
    }
}

void merge_ssort(vector<int> &a,int l, int r){
    if( l < r){
        int m = l + (r - l)/2;
        merge_ssort(a,l,m);
        merge_ssort(a,m+1,r);
        mergesss(a,l,m,r);
    }
}


int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i  = 0 ; i < n ; i++)cin >> a[i];

    merge_ssort(a,0,n-1);
    for(int i = 0 ; i < n ;i++) cout << a[i] << " ";
    return 0;
}