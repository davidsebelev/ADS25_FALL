#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// первый индекс i где a[i] >=L
int l_search1(vector<int>& a, int l1){
    int l = -1, r = a.size(); //ответ ∈ (l, r]
    while(l + 1 < r){
        int m = (l + r) /2;
        if(a[m] >= l1){ // м уже достаточно справа правее брать нет смысла
            r = m; // сужаем справа
        }else{
            // иначе a[m] < L  точно левее нашего l1
            l = m; // сужаем слева
        }
    }
    return r; // указывает на первый индекс который больше либо равен границе  l1
}
 // первый индекс i где a[i] > R
int r_search1(vector<int>& a, int r1){
    int l = -1, r = a.size(); // ответ ∈ (l, r]

    while(l + 1 < r){
        int m = (l + r) /2;
        if(a[m] > r1){
            r = m; // m слишком большй будем сужать ответ левее или здесь
        }else{
            l = m; // a[m] < r   левее нужного ответа
        }
    }
    return r; // указывает на первый индекс который точно больше r
}




int recount(vector<int>& a, int l, int r){ // 
    int left = l_search1(a,l);
    int right = r_search1(a,r);
    return right - left;
}

// 

int main(){
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    sort(a.begin(),a.end());


    while(q--){
        int l1, r1, l2 , r2;
    cin >> l1 >> r1 >> l2 >> r2;


    int cnt1 = recount(a,l1,r1);
    int cnt2 = recount(a,l2,r2);

    int ans = cnt1 + cnt2;

    int L = max(l1,l2); // 5 
    int R = min(r1,r2); // 6

    if(L <= R ) ans  -=recount(a,L,R);
    cout << ans << endl;
    }
    


    return 0;
}