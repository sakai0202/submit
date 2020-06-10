#include <iostream>
#include <algorithm>
#include <string.h>
#include <list>
#include <vector>

using namespace::std;

/*ファサードパターン
処理の窓口　様々なクラスが関連してくる複雑な処理をまとめておく
https://www.techscore.com/tech/DesignPattern/Facade.html/
*/

class Computer {
public:
    void func1() {
        cout << "1" << endl;
    }
    void func2() {
        cout << "2" << endl;
    }
    void func3() {
        cout << "3" << endl;
    }
    void func4() {
        cout << "4" << endl;
    }
    void func5() {
        cout << "5" << endl;
    }
};

class Computer2 {
public:
    void func1() {
        cout << "あ" << endl;
    }
    void func2() {
        cout << "い" << endl;
    }
    void func3() {
        cout << "う" << endl;
    }
    void func4() {
        cout << "え" << endl;
    }
    void func5() {
        cout << "お" << endl;
    }
};

class ComputerFacade {
protected:
    Computer* computer;
    Computer2* computer2;
public:
    ComputerFacade() {
        computer = new Computer();
        computer2 = new Computer2();
    }
    ~ComputerFacade() {
        delete(computer);
        delete(computer2);
    }

    void numShow() {
        computer->func1();
        computer->func2();
        computer->func3();
        computer->func4();
        computer->func5();
    }

    void aiueoShow() {
        computer2->func1();
        computer2->func2();
        computer2->func3();
        computer2->func4();
        computer2->func5();
    }

    void allShow() {

        computer->func1();
        computer->func2();
        computer->func3();
        computer->func4();
        computer->func5();
        computer2->func1();
        computer2->func2();
        computer2->func3();
        computer2->func4();
        computer2->func5();
    }
};

int main() {
    ComputerFacade* facade = new ComputerFacade();

    facade->aiueoShow();
    facade->allShow();
    facade->numShow();

    return 0;
}
