#include<bits/stdc++.h>
using namespace std;

int partion(vector<int> &a, int start, int end){
    int pivot = a[end];
    int Pindex = start;

    for(int i = start ; i < end ; i++){
        if(a[i] <= pivot){
            swap(a[i],a[Pindex]);
            Pindex++;
        }
    }
    swap(a[Pindex],a[end]);
    return Pindex;
}

void QuickSort(vector<int> &a, int start , int end){
    if(start < end){
        int PartionIndex = partion(a,start,end);
        QuickSort(a,start,PartionIndex-1);
        QuickSort(a,PartionIndex + 1,end);
    }
}

void quick_sort(vector<int>& a,int l , int r){
    int p = a[(l + r)/2];
    int i = l;
    int j = r;

    while(i < j){
        while(a[i] < p)i++;

        while(a[i] > p)j--;

        if(i <= j){
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    if(l < j) quick_sort(a,l,j);
    if(i < r) quick_sort(a,i,r);

}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n ; i++) cin >> a[i];

    //QuickSort(a,0,n - 1);
    quick_sort(a,0,n - 1);
    for(int i = 0; i < n ;i++) cout << a[i] << " ";
}