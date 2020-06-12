
#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include <vector>
#include <map>

using namespace::std;

/*mementoパターン
ロールバック機能　オブジェクトの状態をキャプチャしてスムーズに取り出せるようにする
*/

class Memento {
private:
    int result = -1;
public:
    Memento() : result(-1) {

    }

    Memento(const int& temp) {
        result = temp;
    }

    int getResult() {
        return result;
    }
};

class Calc {
private:
    int temp = 0;
public:
    Calc() : temp(0) {

    }

    void plus(const int& plus) {
        temp += plus;
    }

    Memento* createMemento() {
        return new Memento(temp);
    }

    void getFromMemento(Memento* memento) {
        temp = memento->getResult();
    }

    int getTemp() {
        return temp;
    }
};

int main() {
    map<string, Memento*>* save;
    save = new map<string, Memento*>();

    Calc* calc = new Calc();
    for (int i = 0; i < 10; i++) {
        calc->plus(i);
    }

    save->emplace("save1", calc->createMemento());

    for (int i = 10; i < 20; i++) {
        calc->plus(i);
    }

    save->emplace("save2", calc->createMemento());

    for (int i = 20; i < 30; i++) {
        calc->plus(i);
    }

    save->emplace("save3", calc->createMemento());

    calc->getFromMemento(save->at("save1"));
    cout << calc->getTemp() << endl;
    calc->getFromMemento(save->at("save2"));
    cout << calc->getTemp() << endl;
    calc->getFromMemento(save->at("save3"));
    cout << calc->getTemp() << endl;
    calc->getFromMemento(save->at("save1"));
    cout << calc->getTemp() << endl;
    calc->getFromMemento(save->at("save2"));
    cout << calc->getTemp() << endl;


    //cout << (save->at("save1")) << endl;
    return 0;
}
