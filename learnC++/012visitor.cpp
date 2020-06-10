#include <iostream>
#include <string.h>
#include <list>
#include <vector>

using namespace::std;

/* ビジターパターン

データ構造と処理の分離がメリット　処理の修正がデータ構造に及ばない
データ構造Homeに変更を加えず、teacherは家庭毎に処理を行える
処理はTeacherで仮想関数を用いて具体的な処理は継承先で書く
今までは新しい動作を加えるたびにHomeを継承して、Homeの中で動作を変えていた

・受け入れる側に処理を追加することなく、処理を追加することができるパターン
鈴木さんちのテストの点数が80以下だったら怒り　のような処理を。
鈴木さん側に書かずに先生側で書ける
wikipedia:
Visitor パターンでは状態を持つことができる。これは、オブジェクトに対して実行されるアクションが以前のアクションに依存するような多くのケースで極めて有用である。

今回
accepter <-<> Home
   ↑　継承      ↑
TanakaHome , SuzukiHome

一般:
visitor
 ↑　継承
 concrete visitor

 element <-<> ObjectStructure
   ↑　継承
conceteElement1 , concleteEkement2

cf.
https://www.techscore.com/tech/DesignPattern/Visitor.html/
https://ja.wikipedia.org/wiki/Visitor_パターン
*/

class TanakaHome;
class SuzukiHome;

class Teacher {
public:
    virtual void visit(TanakaHome* studentHome) = 0;
    virtual void visit(SuzukiHome* studentHome) = 0;
};

class Home {
public:
    virtual void praisedChild() = 0;
    virtual void reprovedChild() = 0;

};
class Acceptor {
public:
    virtual void accept(Teacher* teacher) = 0;
};

class TanakaHome : public Home, public Acceptor {
public:
    void praisedChild() override {
        cout << "excellent" << endl;
    }
    void reprovedChild() override {
        cout << "no no" << endl;
    }
    void accept(Teacher* teacher) override {
        teacher->visit(this);
    }
};
class SuzukiHome : public Home, public Acceptor {
public:
    void praisedChild() override {
        cout << "good" << endl;
    }
    void reprovedChild() override {
        cout << "?" << endl;
    }
    void accept(Teacher* teacher) override {
        teacher->visit(this);
    }
};

class RookieTeacher : public Teacher {
public:
    void visit(TanakaHome* studentHome) {
        studentHome->praisedChild();
    }
    void visit(SuzukiHome* studentHome) {
        studentHome->reprovedChild();
    }
};

int main() {
    SuzukiHome* suzuki = new SuzukiHome();
    TanakaHome* tanaka = new TanakaHome();

    RookieTeacher* tea = new RookieTeacher();
    tea->visit(suzuki);
    tea->visit(tanaka);
}










