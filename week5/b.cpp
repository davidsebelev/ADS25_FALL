#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class MinHeap{
    public:
    vector<ll> a;

    ll parent(ll i){
        return (i-1)/2;
    }

    ll left(ll i){
        return (2*i + 1);
    }

    ll right(ll i){
        return (2*i+2);
    }

    void insert(ll k){
        a.push_back(k);
        int ind = a.size() -1;

        while(ind > 0 and a[ind] > a[parent(ind)]){
            swap(a[ind],a[parent(ind)]);
            ind = parent(ind);
        }
    }

    void heapify(int i){
        if(left(i) > a.size() - 1) return;


        int j = left(i);
        if(right(i) < a.size() and a[right(i)] > a[left(i)]){
            j = right(i);
        }

        if(a[i] < a[j]){
            swap(a[i],a[j]);
            heapify(j);
        }
    }

    ll getMax(){
        return a[0];
    }

    int extractMax() {
        int root_value = getMax();

        // Replace root with last element
        swap(a[0], a[a.size() - 1]);
        a.pop_back();

        // Heapify down from root
        if (a.size() > 0)
            heapify(0);

        return root_value;
    }



     
};



int main(){
    MinHeap *heap = new MinHeap();
    int n;
    ll x;
    cin >> n;
    while (n--)
    {
        cin >> x;
        heap->insert(x);
    }
    //ll m = heap->a.size();
    //for(int i = 0; i < m ;i++) cout << heap->extractMax() << " ";
    //cout << "\n";
    while(heap->a.size() > 1){
        ll y = heap->extractMax();
        ll x = heap->extractMax();
        //cout << x << " " << y << " ";

        ll temp = x;
        if(x == y) continue;

        if(x!=y){
            y = y-x;
            heap->insert(y);
        }
    }
    if(heap->a.size() == 1) cout << heap->a[0];
    else cout << 0;
    
    return 0;
}