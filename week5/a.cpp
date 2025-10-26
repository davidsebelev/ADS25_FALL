#include <bits/stdc++.h>
using namespace std;

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

int main() {
    int n;
    cin >> n;
    minHeap *heap = new minHeap();
    long long x;

    for (int i = 0; i < n; i++) {
        cin >> x;
        heap->insert(x);
    }

    long long sum = 0;
    while (heap->a.size() > 1) {   
        long long first_min = heap->extractMin();
        long long second_min = heap->extractMin();

        long long small_sum = first_min + second_min;

        heap->insert(small_sum);
        sum += small_sum;
    }

    cout << sum << "\n";
    return 0;
}
