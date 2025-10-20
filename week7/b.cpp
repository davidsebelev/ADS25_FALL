#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &a, int l, int m, int r){
    int n1 = m - l +1;
    int n2 = r - m;

    vector<int> L(n1),R(n2);

    for(int i = 0 ; i < n1 ; i++) L[i] = a[l+i];
    for(int j = 0 ; j < n2; j++) R[j] = a[m + j + 1];

    int uk1 = 0;
    int uk2 = 0;
    int k = l;

    while(uk1 < n1 and uk2 < n2){
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

void merge_sort(vector<int> &a, int l, int r){
    if(l >= r)return;
    int m = (l + r)/2;

    merge_sort(a,l,m);
    merge_sort(a,m+1,r);

    merge(a,l,m,r);
}




int main(){
    int n,m;
    cin >> n;
    vector<int> r;

    for(int i = 0 ; i < n ;i++){
        int x;
        cin >> x;
        r.push_back(x);
    }

    cin >> m;

    for(int i = 0 ; i < m ;i++){
        int x;
        cin >> x;
        r.push_back(x);
    }

    merge_sort(r,0,r.size()-1);

    for(int i = 0 ; i < r.size() ;i++) cout << r[i] << " ";


    return 0;
}