#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
using namespace std;


// проходимся по массиву размер н 
// создаем разницу нашего числа и элемента массива и записываем ее
// закидываем каждую разницу в какой нибудь массив резалта 
// если число к котоырое сравниваем положительно то берем наименьшую разницу
// иначе берем наибольшую





int main(){
    int n,k;
    cin >> n;
    vector<int> num;
    while(n--){
        int x;
        cin >> x;
        num.push_back(x);
    }
    vector<int> res; // 2 3 5 1 3 4
    cin >> k;
    for(int i = 0 ; i < num.size();i++){
        int raz = abs(num[i] - k);
        res.push_back(raz);
    }
    int small = res[0]; // 2 // 1
    int count = 0;
    for(int i = 1 ;i < res.size();i++){
        if(small > res[i]){
            small  = res[i];
            count = i; 
        }
    }
    //cout << small  << endl;
    cout << count << endl;
    return 0;
}