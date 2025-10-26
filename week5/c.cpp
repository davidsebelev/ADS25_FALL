#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class MaxHeap{
    public:
    vector<ll> a;


    ll parent(ll i){
        return (i-1)/2;
    }
    
    ll left(ll i){
        return 2*i +1;
    }

    ll right(ll i){
        return 2*i + 2;
    }

    ll getMax(){
        return a[0];
    }

    void insert(ll k){
        a.push_back(k);
        ll ind = a.size()-1;

        while(ind > 0 and a[ind] >a[parent(ind)]){
            swap(a[ind],a[parent(ind)]);
            ind = parent(ind);
        }
    }

    void heapify(ll i){
        if(left(i) > a.size()-1) return;

        ll j= left(i);
        if(right(i) < a.size() and a[right(i)] > a[left(i)]) j = right(i);

        if(a[i] < a[j]){
            swap(a[i],a[j]);
            heapify(j);
        }
    }

    ll extractMax(){
        ll root_val = getMax();
        swap(a[0],a[a.size()-1]);
        a.pop_back();
        if(a.size() > 0){
            heapify(0);
        }
        return root_val;
    }
};



int main(){
    MaxHeap *heap = new MaxHeap();
    ll n,x;
    cin >> n >> x;
    while(n--){
        ll k;
        cin >> k;
        heap->insert(k);
    }
    ll sum = 0;
  
    while(x--){
        ll first = heap->extractMax();
        sum+=first;
        heap->insert(first-1);
    }
    cout << sum << " ";
    return 0;
}