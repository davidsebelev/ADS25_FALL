#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class minHeap {
public:
    vector<long long> a;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    void insert(long long k) {
        a.push_back(k);
        int ind = a.size() - 1;

        while (ind > 0 && a[ind] < a[parent(ind)]) {
            swap(a[ind], a[parent(ind)]);
            ind = parent(ind);
        }
    }

    void heapify(int i) {
        if (left(i) >= (int)a.size()) return;

        int j = left(i);
        if (right(i) < (int)a.size() && a[right(i)] < a[left(i)]) {
            j = right(i);
        }

        if (a[i] > a[j]) {
            swap(a[i], a[j]);
            heapify(j);
        }
    }

    long long get_min() {
        return a[0];
    }

    long long extractMin() {
        long long root_val = get_min(); 
        swap(a[0], a[a.size() - 1]);
        a.pop_back();

        if (!a.empty()) {
            heapify(0);
        }
        return root_val;
    }
};



int main(){
    minHeap *heap = new minHeap();
    ll q, k;
    cin >> q >> k;
    ll sum = 0;
    ll m = 0;
    while(q--){
        string word;
        cin >> word;
        if(word == "print"){
            cout << sum << "\n";
        }
        else if(word == "insert" && heap->a.size() < k){
            ll x;
            cin >> x;
            sum+=x;
            heap->insert(x);
            m++;
        }else if(word == "insert" and heap->a.size() == k){
            ll x;
            cin >> x;
            if(x > heap->a[0]){
                ll min = heap->extractMin();
                heap->insert(x);
                sum = sum - min + x;
            }
            
        }
    }
    return 0;
}