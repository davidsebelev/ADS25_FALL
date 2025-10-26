// #include<bits/stdc++.h>
// using namespace std;

// class Heap{
//     public:
//     vector<int> a;

//     int parent(int i){
//         return (i-1)/2;
//     }

//     int left(int i){
//         return 2*i + 1;
//     }

//     int right(int i){
//         return 2*i + 2;
//     }

//     int GetMin(){
//         return a[0];
//     }

//     void Insert(int data){
//         a.push_back(data);
//         int index = a.size() - 1;

//         while(index > 0 and a[index] <a[parent(index)]){
//             swap(a[index],a[parent(index)]);
//             index = parent(index);
//         }
//     }

//     void Heapify(int i){
//         if(left(i) > a.size() - 1) return;

//         int j = left(i);
//         if(right(i) < a.size() and a[right(i)] < a[left(i)]){
//             j = right(i);

//             if(a[i] > a[j]){
//                 swap(a[i],a[j]);
//                 Heapify(j);
//             }
//         }
//     }

//     int ExtractMin(){
//         int root_value = GetMin();

//         swap(a[0],a[a.size()- 1]);
//         a.pop_back();

//         if(a.size() > 0){
//             Heapify(0);
//         }
//         return root_value;
//     }
// }

// int main(){
//     return 0;
// }