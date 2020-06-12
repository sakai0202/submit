/*似た種類のオブジェクトを生成するときは一つのクラスで生成しましょう。
//https://techracho.bpsinc.jp/hachi8833/2017_10_02/46064#abstract-factory

Wikipedia :abstract factoryパターンは、テーマの共通な個別のファクトリーのグループをカプセル化する手段を提供する。このとき、ファクトリーの具体的なクラスを指定しない。
極めて分かりやすい説明　https://qiita.com/morimotof/items/67a9e2a8d7e15ea321d2

https://www.xmisao.com/2013/12/11/gof-designpattern-java-abstractfactory.html
    特定の組み合わせが要求されるオブジェクト群を誤りなく生成できる
    生成されるオブジェクトの実装を隠蔽することができる

この例では作成しドアの種類に合わない職人を呼ぶことはない。
また、後から容易に別の種類のドアを追加する事が出来る
*/

#include <iostream>
#include <string.h>
#include <list>
#include <vector>

using namespace::std;

class Door {
public:
    virtual void getDescription() = 0;
};

class WoodDoor : public Door {
public:
    void getDescription() override {
        cout << "木のドア" << endl;
    }
};

class IronDoor : public Door {
public:
    void getDescription() override {
        cout << "鉄のドア" << endl;
    }
};

class DoorFiting {
public:
    virtual void getDescription() = 0;
};

class IronMan : public DoorFiting {
public:
    void getDescription() {
        cout << "鉄のドアをつける" << endl;
    }
};

class WoodMan : public DoorFiting {
public:
    void getDescription() {
        cout << "木のドアをつける" << endl;
    }
};

class DoorFactory {
public:
    virtual Door* makeDoor() = 0;
    virtual DoorFiting* makeFitting() = 0;
};

class WoodDoorFactory : public DoorFactory {
public:
    Door* makeDoor() override {
        return new WoodDoor();
    }
    DoorFiting* makeFitting() override {
        return new WoodMan();
    }
};

class IronDoorFactory : public DoorFactory {
public:
    Door* makeDoor() override {
        return new IronDoor();
    }
    DoorFiting* makeFitting() override {
        return new IronMan();
    }
};


int main() {
    WoodDoorFactory* woodfac = new WoodDoorFactory();
    Door* door = woodfac->makeDoor();
    DoorFiting* expert = woodfac->makeFitting();

    door->getDescription();
    expert->getDescription();

    IronDoorFactory* ironfac = new IronDoorFactory();
    Door* door2 = ironfac->makeDoor();
    DoorFiting* expert2 = ironfac->makeFitting();

    door2->getDescription();
    expert2->getDescription();
}

