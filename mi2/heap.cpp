#include<bits/stdc++.h>
using namespace std;

class MinHeap{
    public:
    vector<int> a;

    int parent(int i){return (i-1)/2;}
    int left(int i ){return 2*i+1;}
    int right(int i){return 2*i+2;}


    void insert(int k){
        a.push_back(k);
        int ind = a.size()-1;

        while(ind > 0 and a[ind] < a[parent(ind)]){
            swap(a[ind],a[parent(ind)]);
            ind = parent(ind);
        }
    }

    void heapify(int i ){
        if(left(i) > a.size()-1){
            return;
        }

        int j = left(i);
        if(right(i) < a.size() and a[right(i)] < a[left(i)]){
            j = right(i);
        }

        if(a[i] > a[j]){
            swap(a[i],a[j]);
            heapify(j);
        }
    }

    int get_min(){return a[0];}

    int extractMin(){
        int root_val = get_min();

        swap(a[0],a[a.size()-1]);
        a.pop_back();

        if(a.size() > 0){
            heapify(0);
        }
        return root_val;
    }
};

class Maxheap{
    public:
    vector<int> a;

    int parent(int i){
        return (i-1)/2;
    }

    int left(int i){
        return 2*i+1;
    }

    int right(int i){
        return 2*i+2;
    }


    void insert(int k){
        a.push_back(k);
        int ind  = a.size()-1;

        if(ind > 0 and a[ind] > a[parent(ind)]){
            swap(a[ind],a[parent(ind)]);
            ind = parent(ind);
        }
    }

    void heapify(int i){
        if(left(i) > a.size()-1)return;

        int j = left(i);
        if(right(i) < a.size() and a[right(i)] > a[left(i)]){
            j = right(i);
        }

        if(a[i] < a[j]){
            swap(a[i],a[j]);
            heapify(j);
        }
    }
    int get_max(){return a[0];}

    int extractMax(int i){
        int root_Val = get_max();

        swap(a[0],a[a.size()-1]);
        a.pop_back();

        if(a.size() > 0){
            heapify(0);
        }
        return root_Val;
    }
};

// пример заполнение хипа
int main(){
    int n, k;
    cin>> n >> k;
    MinHeap *heap = new MinHeap();
    long long x;

    for(int i = 0 ; i < n ; i++){
        cin >> x;
        heap->insert(x);
    }
    return 0;
}