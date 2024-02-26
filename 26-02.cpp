#include <iostream>
#include <cstring>

using namespace std;

// class A {
//     int a;
//     public:
//     friend void f (const A & obj) {

//     }
// }


//недьзя перегружать # :: :? . .* sizeof typedef

class C {
    double re, im;
    public:
    C(double x = 0, double y = 0): re(x), im(y){}
    bool operator==(C & obj) { return re == obj.re && im == obj.im;}
    C operator+(const C & a) { // {return C(re + a.re, im + a.im);}
        C tmp;
        tmp.re = re + a.re;
        tmp.im = im + a.im;
        return tmp;
    }
    friend C operator+(const C & a, const C & b) { return C(a.re + b.re, a.im + b.im);}
    C operator-() { return C(-re, -im); }
    C operator++() {
        ++re,
        ++im;
        return *this;
    }
    C operator++(int notused) {
        C tmp(re, im);
        re++;
        im++;
        return tmp;
    }
    C & operator=(const C & obj) {
        re = obj.re;
        im = obj.im;
        return *this;
    }
};



// int main () {
//     C c1(1,2), c2(1), c3;
//     c3 = c1 + c2; // OK
//     c3 = c1 + 10.1; // OK, только если в операторе перегрузки стоит const
//     c3 = 10.1 + c1; // не OK, если нет дружественной функции
// }

// int main() {
//     C a(1,2), b;
//     b = a++;
//     b = ++a;
//     b = ++++a; // b(3,3), a(3,3)
//     b = a++++; // b(1,1), a(2, 2)
//     b = -a;
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

    char & operator[](int i) {
        return str[i];
    }

    friend String operator+(const String & s1, const String & s2) {
        String tmp(s1.len + s2.len - 1);
        strcat(tmp.str, s1.str);
        strcat(tmp.str, s2.str);
        return tmp;
    }

    String & operator=(const String & a) {
        if (this != &a) {
            delete[] str;
            str = new char[len = a.len];
            strcpy(str, a.str);
        }
        return *this;
    }

    char* getstr() {
        return str;
    }

    // void String::swap(String & a) {
    //     ::swap(str, a.str);
    //     ::swap(len, a.len);
    // }

    // String & String::operator=(String & a) {
    //     swap(a);
    //     return *this;
    // }

    friend ostream & operator<<(ostream & s, const String & a) {
        s << a.str;
        s << endl;
        return s;
    }

    ~String() {
        delete[] str;
    }
};

int main() {
    String s1("abcd"), s2("klm"), s3;
    s2[1] = 'A';
    s3 = s1 + s2;
    cout << s3;
}


/*
    operator double() {
        return re;
    }

    main () {
        
    }
*/