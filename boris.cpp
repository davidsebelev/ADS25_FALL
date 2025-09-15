#include<iostream>
#include<deque>
using namespace std;
// играем в пьянницу ходит всегда борис первый у кого карта больше тот и выйграл
// забирает себе эти две карты всегда в одном порядке 
// 0 бьет 9 
int main(){
    deque<int> f;
    deque<int> s;



    for(int i = 0 ; i < 5 ; i++){
        int x;
        cin >> x;
        f.push_back(x);
    }


    for(int i = 0 ; i < 5 ; i++){
        int y;
        cin >> y;
        s.push_back(y);
    }



for (int step = 1; step <= 1000000; step++) {
    bool boris_wins;
   int a = f.front(); f.pop_front();// boris
   int b = s.front(); s.pop_front(); // nursik

        if (a == 0 && b == 9) {
        boris_wins = true;   // 0 бьёт 9 → Борис победил
    } else if (a == 9 && b == 0) {
        boris_wins = false;  // 0 бьёт 9 → Нурсик победил
    } else if (a > b) {
        boris_wins = true;
    } else {
        boris_wins = false;
    }
    




    if(boris_wins){
        f.push_back(a);
        f.push_back(b);
    }else{
        s.push_back(a);
        s.push_back(b);
    }

    if(f.empty()){
        cout << "Nursik" << " " <<   step;
        return 0;
    }else if(s.empty()){
        cout << "Boris" << " " <<  step;
        return 0;
    }
}
cout << "blin nichya";
return 0;
}