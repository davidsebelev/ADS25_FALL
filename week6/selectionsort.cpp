#include<bits/stdc++.h>
using namespace std;

void SelectionSort(int a[], int n){
    for(int i = 0 ; i < n - 1; i++){
        int iMin = i;
        for(int j = i + 1 ; j <n ;j++){
            if(a[j] < a[iMin]){
                iMin = j;
            }
        }
        int temp = a[i];
        a[i] = a[iMin];
        a[iMin] = temp;
    }
}

void selection_sort(vector<int> &a, int n){
    for(int i = 0 ; i < n - 1; i++){
        int iMin = i;
        for(int j = i +1 ; j < n ; j++){
            if(a[j] < a[iMin]) iMin = j;
        }
        swap(a[i],a[iMin]);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n ;i++) cin >> a[i];

    selection_sort(a,n);

    for(int i = 0 ; i < n ;i++) cout << a[i] << " ";

    return 0;
}