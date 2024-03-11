// template <class T>

// void swap (T & a, T & b) { // автоматически перегружаемая функция
//     T tmp;
//     tmp = a;
//     a = b;
//     b = tmp;
// }

// // int main() {
// //     int x1 = 10, x2 = 20;
// //     swap(x1, x2);
// //     swap <int>(x1, x2); // вместо Т в классе будет int
// //     // если x1, x2 - long при таком вызове будет ошибка

// //     return 0;
// // }

// template <class T>

// T abs(T a) { // or (const T & a)
//     return (a >= 0) ? a : -a;
// }

// template <class T, int SIZE = 10> // но нельзя исп void, float, double, польз.

// class Stack {
//     T st[SIZE];
//     int top {}
// public:
//     void push(T a) {
//         if (top == SIZE) throw(...);
//         else {
//             st[top++] = a;
//         }
//     }
//     T pop();
// };

// template <class T, int SIZE>
// T Stack<T, SIZE>::pop() {
//     if (top == SIZE) {
//         throw(0);
//     }
//     return st[top--];
// }

//STL
/*
    послед - vector, list, deque, stack, queue
    ассоц. м. - map<key, val>, multimap, set<key>, multiset
    value_type
    size_type
    reference, const_reference
    pointer, const_pointer

    iterator ++
    reverse_iterator ++
    const_iterator
    const_revers_iterator

    1)input ->   ++
    2output ->   --
    3)forward -> !=
    4)bidirectional-> <- list map set; prev and [] (o(n)), +-n, >>=, <<=
    5) random_access vector deque

    при дивжении по контейнеру необходимо всегда сравнивать позицию с end, выход за него фатален

*/

#include <iostream>
#include <vector>
#include <list>

using namespace std;

// int main() {
//     vector<int> v1;
//     vector<long> v2(5);
//     vector<char>v3(10, 'x');
//     int m[] = {5, 6, 7, 8};
//     vector<int>v4(m, m+4);
//     for (int i = 0; i < 10; i++) {
//         v1.push_back(i); // size = 10, capacity = 16, каждый раз удваивается объём выделенной памяти
//     }
//     for (int i = 0; i < v1.size(); ++i) {
//         cout << v1[i] << " ";
//     }
//     cout << endl;
//     vector<int>::iterator p = v1.begin(); // auto p = v1.begin()
//     while (p != v1.end()) {
//         cout << *p++ << " ";
//     }
//     cout << endl;
//     for (int i = v1.size() - 1; i >= 0; i--) {
//         cout << v1[i] << " ";
//     }
//     cout << endl;
//     auto p1 = v1.rbegin();
//     while (p1 != v1.rend()) {
//         cout << *p1++ << ' ';
//     }
//     cout << endl;
//     auto p2 = v1.end();
//     while (p2 != v1.begin()) {
//         cout << *--p2 << ' ';
//     }
//     cout << endl;

//     return 0;
// }


/*
    size_type size()
    bool empty()
    void clear()
    void push_back(val)
    void pop_back()
    reference_back()
    reference_front()
    push_front, pop_front - vector, deque only

    iterator insert(iterator p, val)
    iterator erase(iterator p)


    list, map
    p = p + 3; - error
    advance(p, 3);
    distance(p1, p2);
*/

void f(vector<char> & v) {
    auto p = v.begin() + 1;
    while (p != v.end()) {
        p++;
        if (p != v.end()) {
            p = v.erase(p);
        }
    }
}

void g(list<int> & l) {
    auto p = l.begin();
    while (p != l.end()) {
        p = l.insert(p, *p);
        p++;
        p++;
    }
}