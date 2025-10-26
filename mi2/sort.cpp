#include<bits/stdc++.h>
using namespace std;

void quick_sort(vector<int> &a ,int l, int r){
    int i = l;
    int j = r;

    int p = a[(l+r)/2];

    while(i<=j){
        while(a[i] < p)i++;
        while(a[j] > p)j--;


        if(i<=j){
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }

    if(i < r)quick_sort(a,i,r);
    if(l < j)quick_sort(a,l,j);
};

void merge(vector<int> &a, int l, int m, int r){
    int n1 = m - l  +1;
    int n2 = r - m;

    vector<int> L(n1),R(n2);

    for(int i = 0 ; i < n1 ;i++)L[i] = a[l+i];
    for(int j = 0 ; j < n2 ;j++)R[j] = a[m+j+1];

    int i = 0;
    int j = 0;
    int k = l;

    while(i < n1 and j < n2){
        if(L[i] <= R[j])a[k++] = L[i++];
        else a[k++] = R[j++];
    }

    while( i < n1){a[k++]=L[i++];}
     while( j < n2){a[k++]=R[j++];}


}


void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        // Find the middle point
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main(){
    return 0;
}