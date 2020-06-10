#include <iostream>
#include <string.h>
#include <list>
#include <vector>

using namespace::std;

/* コマンドパターン
コメントアウトはパターンを使わない例　intで呼び分ける実装だと新しい実験を追加するには、
メインも修正し、呼び出される元の実験部分にもelse ifを追加する必要がある
コマンドパターンでは元のビーカークラスを変更せずに、いろいろな実験を追加することが出来る
一般的にはcommandを複数追加できるようにし、Invokerにコマンドをpushして管理したりする
また、executeの中での実行内容はrecieverと呼ばれる部分に記述する
今回
     command <-<> Invoker
        ↑継承
      addsaltcommand , addwatercommand ,など
        ↑作成
       Main
一般的には
                 command <-<> Invoker
                  ↑継承
 Receiver <-<> concrete command
                  ↑作成
                 Client

cf :コマンドパターン
https://www.techscore.com/tech/DesignPattern/Command.html/
*/

class Beaker {
private:
    double salt = 0;
    double water = 0;
    bool melted;
public:
    static const int ADD_SALT;
    static const int ADD_WATER;
    Beaker(double wat, double sal) {
        this->salt = sal;
        this->water = wat;
        this->mix();
    }
    void addSalt(double amount) {
        this->salt += amount;
    }
    void addWater(double water) {
        this->salt += water;
    }
    void mix() {
        if (salt / (salt + water) * 100 < 26.4) {
            melted = true;
        }
        else {
            melted = false;
        }
    }

    double getSalt() {
        return salt;
    }
    double getWater() {
        return water;
    }
    bool isMelted() {
        return melted;
    }
    void Note() {
        cout << "水" << water << endl;
        cout << "食塩" << salt << endl;
        cout << "濃度" << (salt / (water + salt)) * 100 << "%" << endl;
    }

    void experiment(int param) {
        if (param == ADD_SALT) {
            while (isMelted()) {
                this->addSalt(1);
                this->mix();
            }
            Note();
        }
        else if (param == ADD_WATER) {
            while (isMelted()) {
                this->addSalt(1);
                this->mix();
            }
            Note();
        }
    }
};
const int Beaker::ADD_SALT = 1;
const int Beaker::ADD_WATER = 2;

class Command {
protected:
    Beaker* beaker;
public:
    void SetBeaker(Beaker* p_beaker) {
        beaker = p_beaker;
    }
    virtual void execute() = 0;
};

//1gずつ加えるコマンドクラス
class AddSaltCommand : public Command {
public:
    void execute() override {
        while (beaker->isMelted()) {
            beaker->addSalt(1);
            beaker->mix();
        }
        beaker->Note();
    }
};

class AddWaterCommand : public Command {
public:
    void execute() override {
        while (beaker->isMelted()) {
            beaker->addWater(10);
            beaker->mix();
        }
        beaker->Note();
    }
};

class MakeSaltWaterCommand : public Command {
public:
    void execute() override {
        beaker->mix();
        beaker->Note();
    }
};

int main() {
    Command* addSalt = new AddSaltCommand();
    Command* addWater = new AddWaterCommand();
    Command* makeSaltWater = new MakeSaltWaterCommand();

    addSalt->SetBeaker(new Beaker(100, 0));
    addWater->SetBeaker(new Beaker(0, 10));
    makeSaltWater->SetBeaker(new Beaker(90, 10));

    addSalt->execute();
    addWater->execute();
    makeSaltWater->execute();

    /*
    Beaker* beaker = new Beaker(100, 0);
    beaker->experiment(Beaker::ADD_SALT);

    Beaker* beaker2 = new Beaker(0, 10);
    beaker2->experiment(Beaker::ADD_WATER);
    */
}

