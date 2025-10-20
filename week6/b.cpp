#include <bits/stdc++.h>
using namespace std;

void QuickSort(vector<int> &a, int l, int r){
    if (l >= r) return;                  

    int i = l, j = r;
    int p = a[l + (r - l) / 2];            

    while (i <= j) {                      
        while (i <= r && a[i] < p) i++;    
        while (j >= l && a[j] > p) j--;

        if (i <= j) {
            swap(a[i], a[j]);
            i++; j--;
        }
    }

    if (l < j) QuickSort(a, l, j);
    if (i < r) QuickSort(a, i, r);
}

int main(){
    int a, b;
    cin >> a >> b;

    vector<int> x(a), y(b);
    for (int i = 0; i < a; i++) cin >> x[i];
    for (int i = 0; i < b; i++) cin >> y[i];

    if (a > 1) QuickSort(x, 0, a - 1);     
    if (b > 1) QuickSort(y, 0, b - 1);

    int i = 0, j = 0;
    vector<int> r;

    while (i < a && j < b) {
        if (x[i] == y[j]) { r.push_back(x[i]); i++; j++; }
        else if (x[i] < y[j]) i++;
        else j++;
    }

    for (int v : r) cout << v << ' ';
    cout << '\n';
    return 0;
}
