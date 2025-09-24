//minimum operations to tranform a into b;
#include<iostream>
#include<queue>
using namespace std;

//у нас есть 4 вида операций
// +1 *2 /2 -1

queue< pair<int, int>  > q; // число и количество шагов до него
int used[200000];

int f(int a, int b){
    q.push(make_pair(a, 0)); // закиыдываем первое число которое будем изменять
    used[a] = a; // напмриер индекс 4 равен 4

    while(!q.empty()){
        int x = q.front().first; // 4
        int d = q.front().second; 

        if(b == x){
            return d;
        }

        if(used[x+1] == 0){
            q.push(make_pair(x+1, d+1)); // становится 5  а его счетчик 1
            used[x+1] = x; // 5
        }
        if(used[x * 2] == 0){
            q.push(make_pair(x*2, d + 1)); // 10 2
            used[x * 2 ] = x;// 10
        }
        if(used[x-1] == 0){
            q.push(make_pair(x-1, d+1)); // 9 // 3
            used[x-1] = x;
        }
        if(used[x / 2] == 0){
            q.push(make_pair(x/2, d + 1));
            used[x / 2 ] = x;
        }
        q.pop();
    }
    return 0;
}

int main(){

    int a, b;
    cin >> a >> b;
    cout << f(a,b) << endl;


    vector<int > r;
    r.push_back(b);

    int t = b;// 7
    while(used[t] != t){
        t = used[t]; // 7
        r.push_back(t);
    }
    for (int i = r.size() - 1; i >= 0; i--)
        cout << r[i] << " ";

    return 0;
}