#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> d;

    // Добавляем элементы
    d.push_back(10);
    d.push_back(20);
    d.push_front(5);
    d.push_back(30);  // итог: [5, 10, 20, 30]

    // Доступ по индексу
    cout << "Элемент с индексом 0: " << d[0] << endl;
    cout << "Элемент с индексом 2: " << d.at(2) << endl;

    // Проход через for
    cout << "Через for: ";
    for (int i = 0; i < d.size(); i++) {
        cout << d[i] << " ";
    }
    cout << endl;

    // Проход через итератор
    cout << "Через итератор: ";
    for (deque<int>::iterator it = d.begin(); it != d.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // Проход через for-each
    cout << "Через for-each: ";
    for (int x : d) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
