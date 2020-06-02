
#include <iostream>

using namespace std;

class A {
private:
    int num;
public:
    A(int n) {
        num = n;
    }
    void aPrint() {
        cout << num << endl;
    };
};

class B {
private:
    int num2;
public:
    A* a;

    B(int n) {
        num2 = n;
    }
    ~B() {
        delete a;
    }

    void SetAptr(A* temp) {
        a = temp;
    }

    void aPrint() {
        a->aPrint();
    };

    void bPrint() {
        cout << num2 << endl;
    };
};

//A　もととなるクラス
//B Aのポインタを持つクラス
int main() {

    A* a = new A(20);
    B* b = new B(200);

    b->SetAptr(a);

    a->aPrint();
    b->aPrint();
    b->bPrint();

    delete a; //aを解放

    A* a2 = new A(10);

    b->SetAptr(a2);
    a2->aPrint();
    b->aPrint();
    b->bPrint();

    delete b; //bを解放
}