#include <bits/stdc++.h>
using namespace std;
// hashing and rabin karp lecture 8
int get_h(string s){
    int n = s.size();
    int h = 0;

    int p = 29;
    int p_pow = 1;
    for(int i = 0 ; i < n ; i++){
        h += s[i]*p_pow;
        p_pow*=p;
    }
    return h;
}

vector<int> get_hash(string s){
    int n = s.size();
    vector<int> h(n);

    int p = 29;
    int p_pow = 29;

    h[0] = s[0];
    for(int i = 1 ; i < n; i++){
        h[i] = h[i-1] + s[i]*p_pow;
        p_pow*=p;
    }
    return h;
}

void merge(vector<int> &arr,int left,int mid, int right ){
    int n1  = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1),R(n2);

    for(int i = 0 ; i < n1 ; i++){
        L[i] = arr[left+i];
    }
    for(int j = 0 ; j < n2; j++){
        R[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while(i < n1 && j < n2){
        if(L[i]<=R[j]){
            arr[k] = L[i++];
        }else{
            arr[k] = R[j++];
        }
        k++;
    }

    while(i < n1){
        arr[k++] = L[i++];
    }

    while(j < n2){
        arr[k++] = R[j++];
    }
}

void merge_sort(vector<int> &arr, int left , int right){
    if(left < right){
        int middle = left + (right-left)/2;

        merge_sort(arr,left,middle);
        merge_sort(arr,middle+1,right);

        merge(arr,left,middle,right);
    }
}

// best case avereage and worst case time complexity o(nlogn)
//space compelixty always o(n)
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1,s2;
    cin >> s1 >> s2;


    int n = s1.size();
    int m = s2.size();

    vector<int> p(n);
    p[0] = 1;
    for (int i = 1; i < s1.size(); i++)
        p[i] = p[i - 1] * 29;

    vector<int> h = get_hash(s1);
    int h_s2 = get_h(s2);


    
    return 0;
}
// hashing and rabin karp lecture 8
