#include<iostream>
#include<stack>
#include<string>
#include<sstream>
using namespace std;


int main(){
    string line;
    getline(cin, line);

    stringstream ss(line);
    string word1, word2;

    ss >> word1 >> word2;



    stack<char> st1;
    stack<char> st2;

    for(int i = 0 ; i < word1.length();i++){
        if(st1.empty() && word1[i] != '#'){
            st1.push(word1[i]);
        }else if(word1[i] == '#'){
            st1.pop();
        }
        else if(word1[i] != '#'){
            st1.push(word1[i]);
        }
    }
    for(int i = 0 ; i < word2.length();i++){
        if(st2.empty() && word2[i] != '#'){
            st2.push(word2[i]);
        }else if(word2[i] == '#'){
            st2.pop();
        }else if(word2[i] != '#'){
            st2.push(word2[i]);
        }
    }

    while(!st1.empty() && !st2.empty()){
        if(st1.top() == st2.top()){
            st1.pop();
            st2.pop();
        }else{
            cout << "No";
            return 0;
        }
    }


    if(st1.empty() && st2.empty()){
        cout << "Yes";
    }else{
        cout << "No";
    }
}