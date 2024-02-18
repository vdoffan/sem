// концепция: C + наследование из smalltalk + классы simula
// осн версия которую мы изучаем 1998

// инкапсуляция, наследование, полиморфизм
// инкапс данные + медоты, кот работают с этими данными
// ATD - абстрактные типы данных, хранятся в private

// статический полиморфизм - перегрузка операций, перегрузка функция
// динамический полиморфизм - разрешается во время исп программы, для этого нужны виртуальные функции
// параметрицеский полиморфизм

/*
#include <stdio.h> == #include <cstdio>
#include <string.h> == #include <cstring>
гл. пр.                std
                       namespace A {int a;
                                    void f() {}
                                    namespace B {
                                        int b;
                                    }
                       };
                       using namespace A; - запрещено
                       int x = A::a;
                       using A::a;
                       A::B::b = 10;
*/

// 1

// namespace N {
//     int f = 2;
//     int g = -2;
// }
// namespace M {
//     int f = 3;
//     int g = -3;
// }

// int f = -5;
// int main() {
//     int f = 1;
//     print(::f, N::f, M::f); -5 2 3
//     using namespace N;
//     print(f, g, M::f); 1 -2 3
//     // если убрать локальную переменную - ошибка в using
//     // если убрать и глобальную и добавить М то using проработает но ошибка при обращении
// }

/*
#include <iostream>
int a = 1; double b = 1.1; char str[] = "abc";
std::cout << a << ' ' << b << ' ' << str << std::endl; // 1 1.1 abc
std::cin >> a >> b >> str; // 10 20 это строка // a = 10, b = 20, str = это
cin.getline(str, 100); - не пишет конец строки
flush skips
std::cin >> std::noskips;
while (std::cin>>c) ...
while((c = std::cin.get()) != EOF)

#include <iomanip>
setw(h) - опр ширину поля для след оператора
setpresision(m);
showpoint;
oct;
hex;
dec;

bool - true / false;
inline - как define но не то же самое
inline double sum(double a; double b) {
    double res; // можно исп локальные переменные
    res = a + b; // проверка типов встроенных параметров
    return res;
}
if, switc, for
*/
#include <iostream>

using namespace std;

//статические поля в структурах
// struct s {
//     char a;
//     double x;
//     static int n; // не принадлежит объекту, в поле видмости только этой структуры
// };

// int s::n = 10;

// main () {
//     s obj1, obj2;
//     obj1.n = 100;
//     cout << obj2.n << endl; // 100
// }

// преобразование типов
/*

int i = 123;
double x;
x = (double) i;
x = double(i); x = static_cast <double>(i)

void f(int a, int b = 2, int c = 3) {
} // параметры по умолчанию пишутся в конце
f(0); // 0 2 3
f(10, 20); // 10 20 3
f(100, 200, 300); // 100 200 300

int *p = new int; // выделяет память И вызывает конструктор
int *p1 = new int(10);
int *p2 = new int[100];
int *p = new A[100]; // bad_alloc // 100 раз вызовет коструктор
        nothrow
delete p1;


int x = 10;
int &y = x; // 2 имени кот указывают на одну память

void f(int x) {
    x += 5;
}
main () {
    int a = 3;
    f(a); // 3
}
void f(int *x) {
    *x += 5;
}
main () {
    int a = 3;
    f(&a); // 8
}

void f(int &x) {
    x += 5;
}
main () {
    int a = 3;
    f(a); // 8
}

int x = 10;
long &y = x; // error
const long &y = x;
long temp = (long)x;
const long &y = temp; // x не меняется, 

char &f (char *f) {
    int i;
    for (i = 0; s[i] && s[i] != ' '; i++);
    return s[i];
}

main() {
    char str[] = "строка '\0' с пробелами"
    f(str) = '\0';
}

void f (char * const & s) { if ...}

main () {
    char str[100] = "...";
    f(str);
    cout << str;
}
 */
// class A {
//     int a; // по умолчаниь private
//     public:
//     void set_a(int x) {a = x;}
//     int get_a(void) {return a;}
// };

// main () {
//     A obj;
//     obj.set_a(20);
//     cout << obj.get_a() << endl;
// }

// class A {
//     int a;
//     public:
//     A(int x = 0) : a(x) {}; //конструктор
//     ~A(){}; // деструктор
// };

// main() {
//     A obj1, obj2(5);
// }
