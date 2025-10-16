#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class Minheap{
    public:
    vector<ll> a;


    ll parent(ll i){
        return (i-1)/2;
    }

    ll left(ll i){
        return 2*i + 1;
    }

    ll right(ll i)
    {
        return 2*i + 2;
    }

    void insert(ll k){
        a.push_back(k);
        ll ind = a.size() - 1;


        while(ind >0 && a[ind] < a[parent(ind)]){
            swap(a[ind], a[parent(ind)]);
            ind = parent(ind);
        }
    }

    void heapify(ll i){
        if(left(i) > a.size() - 1) return;

        ll j = left(i);
        if(right(i) < a.size() && a[right(i)] < a[left(i)]) j = right(i);
        if(a[i] > a[j]){
            swap(a[i],a[j]);
            heapify(j);
        }
    }

    ll getMin(){
        return a[0];
    }

    ll extractMin(){
        ll root_val  = getMin();

        swap(a[0],a[a.size()-1]);
        a.pop_back();

        if(a.size() > 0) heapify(0);

        return root_val;

    }

};



int main(){
    Minheap *heap = new Minheap();
    int n;
    ll x;
    cin >> n >> x;
    int temp = n;
    while(n--){
        ll k;
        cin >> k;
        heap->insert(k);
    }

    //for(int i = 0 ; i < temp;i++) cout << heap->extractMin() << " "; 
    ll d_new = 0;
    int cnt = 0;
    while(heap->a.size() > 1){
        ll first = heap->extractMin();
        ll second = heap->extractMin();
        if(first < x){
            cnt++;
            d_new = first + 2*second;
            heap->insert(d_new);
        }else{
            break;
        }
    }

    if(heap->a.size() == 1 and d_new < x) cout << -1;
    else cout << cnt;
    return 0;
}