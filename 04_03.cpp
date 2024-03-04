/*
перегрузка типов данных (не точно)
1) точность совпадения типов T <-> T& T[] <-> T* typdef T -> const T
2) расшир   bool
            enum
            char - это всё int
            uchar
            short
    float -> double
3) стандартные типы данных ( любой к любому )
4) пользовательские ...
5) ...

1) void f(int*)
2) void f(int)
3) void f(char)
4) void f(long double)
5) void f(uchar)

f(0) - 2, 3, 4, 5
f(15.4) - 3 на 3 этапе
f('a') - 3, 2, 4, 5
*/

// 2.3 a) b) c) устно

// f(0) -> f(int*) or f(char*) - ERROR
// f(nullptr) -> f(int) or f(char *)

/*
void f(void*)
void f(double*)  f("abcd") - ERROR
void f(char*)

1) void f(void*)
2) void f(double*)     f("abcd") - к 3)
3) void f(const char*)

const int ci = 1;
void f(int y) {}
f(ci) - OK


2.2 a)

f (1);
f ('+', '+');
f (2.3);
f (3, “str”);

f(int, int = 0)
f(int, const char *)

struct A {operator int() {return 1;}}
void f(double, char)
void f(double, int)
void f(A, const char *)
void f(int, const char *)

main() {
    A a;
    f(a, 0) - {3} & {2} => пустое множество
    f(a, 'a') - {1, 2} & {1} => {1}
    f('a', 0) = {4} & {2} - пустое множество
    f((char) a, 1.2) - неоднозначтость между {1}, {2}
}


struct B {operator int(){}};

void g(B&, double);
void g(char, const char *);
void g(char, int);

main() {
    B b;
    g(1.5, 0); - 3
    g(b, 2); - нет {1} & {3}
    g(2, b) - 3
}


class A {
  public:
    static int x;
    A(int a = 0) :x(a) {}
    static void print(void) {cout << x;}
};

int A::x = 7; - для всех класов A (глобальная область видимости)

main() {
    A obj1, obj2(5);
    A::print(); // 5
    cout << A:: x << obj2.x // 5 5
}

mutable - любая константная ф-я может изменять это поле

struct A {
    static int x;
    int f (int x) const {}
    static int y;
};

int A::x = 0;
int A::y = 0;

main() {
    const A a;
    a.x = 3;
    cout << a.y << a.x << a.f(1);
}

struct A {
    int n;
    static int k;
    A (const A&a) { n = a.n; }
    static int f() { return k;}
    A(int a = 3) {n = a;} 
};

int A::k = 5;

main() {
    A a = A(1), b;
    cout << A::f() << a.k << b.n << endl; // надо 553

6.7 a)

class A {
    int i;
    public:
    A(int x) { i = x; }
    A(const A & y) { i = y.i; }
    const A f(const A & z) const {
        cout << endl;
        return *this;
    }
};

const A t1( ) {
    const A a = 5;
    return a.f( a );
    }

*/