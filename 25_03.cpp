/*
    наследование
    class A {
        (protected) int x;
    public:
        void f() { cout << x; }
    };

    class B : public (base: private) A{
    public:
        void f() {
            cout << x; // ERR if x isn't protected
        }
    };

    int main() {
        A a, *pa = &a;
        B b, *pb = &b;
        a = b;
        b = a; // ERR
        pa = pb;
        pb = (B*) pa; // ERR
        pa = (A*) pb;
        a.f(); // func from A
        b.f(); // func from B
        pa = &a;
        pa -> f(); // from A
        pa = &b;
        pa -> f(); // from A!!!
        return 0;
    }


    class B1 {
        int a;
        public:
        B1(int x = 0) : a(x){};
    };

    class B2 {
        int aa;
        public:
        B2(int x = 0) :: aa(x){};
    };

    class D {
        public:
        B1;
        B2 {
            int aaa;
            public: D(int x, int y, int z): aaa(z){}
        };
    };

    // virtual funtions

    class A{
        public:
        virtual void f() { cout << 1; }
    };
    class B : public A {
        public:
        void f() { cout << 2; }
    };
    class C : public B {
        public:
        void f() { cout << 3; }
    };


    int main() {
        A *pa, a;
        B *pb, b;
        C *pc, c;
        A & pr = c;
        pa = &a;
        pa -> f(); // 1
        pa = &b;
        pa -> f(); // 2
        pa = &c;
        pa -> f(); // 3
        pb = &c;
        pb -> f(); // 3
        pr.f(); // 3
    }

    


*/