#include<bits/stdc++.h>
using namespace std;


class MinHeap{
    public:
    vector<int> a;
    int parent(int i){return (i-1)/2;}
    int left(int i){return (2*i + 1);}
    int right(int i){return 2*i + 2;}

    void insert(int k){
        a.push_back(k);
        int ind = a.size() - 1;

        while(ind > 0 && a[ind] < a[parent(ind)]){
            swap(a[ind],a[parent(ind)]);
            ind = parent(ind);
        }
    }

    int get_min(){return a[0];}

    void heapify(int i){
        if(left(i) > a.size() - 1) return;

        int j = left(i);

        if(right(i) < a.size() && a[right(i)] < a[left(i)]){
            j = right(i);
        }

        if(a[i] > a[j]){
            swap(a[i],a[j]);
            heapify(j);
        }
    }

    int ExtractMin(){
        int root_val = get_min();

        swap(a[0],a[a.size()-1]);
        a.pop_back();

        if(a.size() > 1){
            heapify(0);
        }
        return root_val;
    }

};

class maxHeap{
    public:
    vector<int> a;

    int parent(int i){return (i-1)/2;}
    int left(int i){return (2*i + 1);}
    int right(int i){return (2*i + 2);}

    void insert(int k){
        a.push_back(k);
        int ind = a.size() - 1;

        while(ind > 0 && a[ind] < a[parent(ind)]){
            swap(a[ind],a[parent(ind)]);
            ind = parent(ind);
        }
    }

    void heapify(int i){
        if(left(i) > a.size() - 1) return;

        int j = left(i);
        if(right(i) < a.size() && a[right(i)] > a[left(i)]){
            j = right(i);
        }

        if(a[i] < a[j]){
            swap(a[i],a[j]);
            heapify(j);
        }
    }

    int get_max(){return a[0];}

    int ExtractMax(){
        int root_val = get_max();

        swap(a[0],a[a.size()-1]);
        a.pop_back();

        if(a.size() > 1){
            heapify(0);
        }
        return root_val;
    }
};


int main(){
    return 0;
}