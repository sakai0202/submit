#include <iostream>
#include <string.h>
#include <list>
#include <vector>

using namespace::std;

/*
シングルトンパターンではインスタンスメソッドではなくstaticを利用したクラスメソッドによりその単一性を持たせます。
コンストラクタをprivateにすることによりその単一性を保証します。
ある一連の機能を集中管理する場所を提供する目的で使用されます。
cf.シングルトンパターン
https://qiita.com/narumi_/items/b205e59e7fc81695f380
cf.クラスメソッド
https://cpp-lang.sevendays-study.com/day5.html
*/

class RegisterNote {
private:
    int num;
protected:
    static RegisterNote* registerNote;
    RegisterNote() {
        num = 0;
    };
public:
    static RegisterNote* getInstance() {
        return registerNote;
    }
    static void Create();
    static void Destroy();

    void Addnum() { num++; };
    void Subnum() { num--; };
    int Getnum() { return num; };

};

RegisterNote* RegisterNote::registerNote = NULL;

void RegisterNote::Create() {
    if (!registerNote) {
        registerNote = new RegisterNote();
    }
}
void RegisterNote::Destroy() {
    if (!registerNote) {
        delete registerNote;
        registerNote = NULL;
    }
}

int main() {
    RegisterNote::Create();

    RegisterNote::getInstance()->Addnum();
    cout << RegisterNote::getInstance()->Getnum() << endl;
    RegisterNote::getInstance()->Addnum();
    RegisterNote::getInstance()->Addnum();
    RegisterNote::getInstance()->Addnum();

    cout << RegisterNote::getInstance()->Getnum() << endl;
    RegisterNote::Destroy();
}


