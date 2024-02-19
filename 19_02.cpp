#include <iostream>
#include <cstring>

using namespace std;

// class A {
//     int a;
// public:
//     explicit A(int x = 0) : a(x) {}
//     ~A(){}
// };

// int main() {
//     A obj1, obj(10), obj3 = A(20); // obj4 = 30 - error
//     return 0;
// }

// конструктор копирования

// class A {
//     int a;
// public:
//     A(const A&v) {
//         a = v.a;
//     }
//     // A(A&v) {} - плохо
//     ~A(){}
// };

// in main: A obj2(10), obj5 = obj2;

// class A {
//     int a;
// public:
//     A(int x) : a(x) {} // нет конструктора по умолчанию
//     ~A(){}
// };

// int main() {
//     A *p1, *p2, *p3;
//     p1 = new A; // error;
//     p2 = new A[100]; // error
//     p3 = new A(100);
//     delete p1;
//     delete[] p2;
// }

// struct s {
//     int x;
//     s(int n) {
//         x = n;
//         cout << "cons";
//     }
//     s(const s & a) {
//         x = a.x;
//         cout << "Copy";
//     }
//     ~s() {
//         cout << "des";
//     }
// };

// s f(s y) {
//     y = s(3);
//     return y;
// }

// int main() {
//     s s(1);
//     f(s);
//     cout << s.x << endl;
//     return 0;
// }

class String {
    char *str;
    int len;
public:
    String (const char* s) {
        str = strdup(s);
        len = strlen(str);
    }
    String (const String & a) {
        str = strdup(a.str);
        len = a.len;
    }
    String (const int l = 1) {
        str = new char[l];
        str[0] = '\0';
    }
    String (String && v) { // конструктор переноса
        str = v.str;
        len = v.len;
        v.str = nullptr;
    }
    ~String() {
        delete[] str;
    }
};

// int main() {
//     String s1, s2("qwerty"), s3 = s2, s4(100);

//     return 0;
// }

// X a;
// X f();
// X & r1 = a;
// X & r2 = f(); err
// X && r1 = f();
// X && r2 = a; err

// задача (ответ)
// 123f34422f344444

int G() { return 1; }
int n;

namespace X {
    int a = 3;
    int G(int y) { return y; }
    int f() { return 4; }
    class A {
        int a;
        public:
        A(int n) { a = n; }
        int G() { return a; }
    };
    namespace Y {int a;
        void G() { a = 8; }
    }
}

namespace Z { int a = 5; }

int main() {
    X::A ob(7), *p = & ob;
    int a, G;
    X::Y::G();
    cout << ob.G() << ' ' << n << ' ' << X::Y::a << ' ';
    using namespace X;
    cout << f() << ' ' << X::a << ' ' << X::G(9);
    using namespace Y;
    cout << Z::a << endl;
}
// 7 0 8 4 3 9 5