#include<iostream>
#include<vector>
#include<stack>
using namespace std;
//ищем ближний элемент слева
// идем слева направо
// пока стек не пуст и верхушка больше текущего возраста удаляем верхушку
// если стек пуст то вывод -1

int main(){
    int n;
    cin >> n;

    stack<int> st;
    vector<int> res;


    for(int i = 0 ; i < n ;i++){
        int temp;
        int x;
        cin >> x;
// например 
//5
//2 1 5 8 3
        while (!st.empty() && st.top() >= x) {
            st.pop(); // удалили 2 // 
        }

        if(st.empty()){
            res.push_back(-1); // -1 // -1 // 1 // 5 // 1
        }else if(!st.empty() && st.top() <= x){
            res.push_back(st.top()); // 5

        }
        st.push(x); // 2 // 1 //5 // 8
        
}
for(int i = 0; i < res.size();i++){
        cout << res[i] << " ";

}
}