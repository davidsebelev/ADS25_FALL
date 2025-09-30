#include <bits/stdc++.h>
using namespace std;
// начинаем с пустой деки
// кладем карту n в деку 
// двигаемся от n к 1
// каждый шаг берем карту i  и кладем ее в началл
// потом делаем сдвиг влево на i%size значит двигаем хвост несколько раз
// 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; // з
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        deque<int> dq;

        for (int i = n; i >= 1; i--) {
            if (!dq.empty()) {
                int k = i % dq.size();
                while (k--) {
                    dq.push_back(dq.front()); // <-- сдвиг влево
                    dq.pop_front();
                }
            }
            dq.push_front(i);
        }

        while (!dq.empty()) {
            cout << dq.front() << " ";
            dq.pop_front();
        }
        cout << "\n";
    }

    return 0;
}
