#include<iostream>
#include<deque>
using namespace std;





int main(){
        deque<int> dq;
    char ch;
    while(cin >> ch){
        if(ch == '+' || ch == '-'){
            int x;
            cin >> x;
            if(ch == '+') dq.push_front(x);
            else dq.push_back(x);
        } else if(ch == '*'){
            if(dq.empty()){
                cout << "error" << endl;
            } else {
                int sum = dq.front() + dq.back();
                cout << sum << endl;
                dq.pop_front();
                if(!dq.empty()) dq.pop_back();
            }
        } else if(ch == '!'){
            return 0;
        }
    }
}


