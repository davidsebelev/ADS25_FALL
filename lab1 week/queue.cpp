#include<iostream>
#include<queue>
using namespace std;


int main(){
    queue<int> q;
    q.push(10);
    q.push(12);
    q.push(13);
    q.push(14);


    while(!q.empty()){
        cout << q.back() << endl;
        q.pop();
    }

}