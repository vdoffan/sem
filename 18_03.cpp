#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <list>
#include <functional>
using namespace std;
/*
    value_type pair(<key>, <val>);
    mapped_type -> val
    map<string, int>;
    map["Ivan"] = 7;
    k = map["New"];
    map["Ivan"] = 10; // только так можно менять ключи
    map<int,int> mp = {{33, 1}, {10,20}, {15,5}, {0, 7}};
    for (auto p = mp.begin(); p != mp.end(); p++) {
        cout << p ->first << p-> second;
    }
    for (auto x: mp) {
        cout << x.first << x.second;
    }
    k = mp.at(10); // out_of_range
    p = mp.find(10); // returns iterator on point with this value
    if (mp == mp.end()) // not found
    mp.insert(make_pair(30, 40)); // if point with key == 30 exists, insert won't work
    mp.insert(pair<int,int>(30, 40)) // same
    mp.emplace(30,40);
    erase(p)
    k = erase(<key>); // deletes point with this key;

    //lambda-function

    int x = 5;
    auto lf1 = [&x]() {
        //some code
        cout << x;
    } lf1();
    auto lf2 = [](int a) {
        cout << a;
    } lf2(x);
    [] [&] [=] - all;

    vector<int> v = {2, 3, 5, 6, 7, 9, 11};
    auto end = remove_if(v.begin(), v.end(), [](int x){return x % 2 == 0});
    v.erace(end, v.end());
*/


// int f1() { return 1; }

// int main() {
//     function<int()>fptr;
//     fptr = f1; fptr();

// }

// complex eval(const vector<string> & args, const complex z) {
//     complex_stack st;
//     map<string, function<void()> > mp
//     { "z", [&st, &z]() {st = st << z;}},
//     {";", [&st]() {st = ~st}};
//     for (const auto &s : args) {
//         if (s[0] != '(') mp[s]();
//         else st = st<<cpmplex(s);
//     }
// }

// template <class T>
// typename T::value_type sum(T & a) {
//     typename T::iterator p = a.end();
//     typename T::value_type s = 0;
//     if (a.size() < 5) {
//         return 0;
//     }
//     int cnt = 0;
//     while (cnt < 5) {
//         p--;
//         s += *p;
//         cnt++;
//     }
//     return s;
// }


// int main() {
//     list<int> st = {1, 3, 10, 15};
//     cout << sum<list<int>>(st) << endl;
//     vector<long> v = {100, 200, 0, 300, 0, 400};
//     cout << sum(v) << endl;
//     return 0;
// }

// template <class T>

// void rever(T b, T e) {
//     if(b == e) return;
//     e--;
//     while (b != e) {
//         typename T::value_type tmp{};
//         tmp = *b;
//         *b = *e;
//         *e = tmp;
//         if (--e == b++) {
//             return;
//         }
//     }
// }

// int main() {
//     list<int> st = {1, 3, 10, 15};
//     vector<long> v = {1, 2, 3};
//     rever(st.begin(), st.end());
//     rever(v.begin(), v.end());
//     for (auto x : v) {
//         cout << x << ' ';
//     }
//     cout << endl;
// }

struct Pred {
    bool operator()(int v) {return v % 3;}
};

template <class T, class P>

void f(T p1, T p2, P c, typename T::value_type n ={}) {
    while (p1 != p2) {
        if (c (*p1)) {
            *p1 = n;
        }
        ++p1;
    }
}
