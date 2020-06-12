#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include <vector>

using namespace::std;

/*Decoratorパターン
「装飾者」　飾り枠と中身の同一視　機能を一つ一つかぶせていく
ラップ、個別のオブジェクトへの機能の追加
*/

class Iceccream {
public:
    virtual string getName() = 0;
    virtual string howSweet() = 0;
    virtual ~Iceccream() {};
};

class VanilaIce : public Iceccream {
public:
    string getName() override {
        return "バニラアイス";
    }
    string howSweet() override {
        return "バニラの味";
    }
    ~VanilaIce() {};
};

class GreenTeaIcecream : public Iceccream {
public:
    virtual string getName() override {
        return "抹茶アイス";
    }
    string howSweet() override {
        return "抹茶味";
    }
    ~GreenTeaIcecream() {};
};

//このアイスに機能を追加する
class NutsVanilaIce : public VanilaIce {
public:
    string getName() override {
        return "ナッツ入りバニラアイスクリーム";
    }

    ~NutsVanilaIce() {};
};
//継承を利用した機能の追加は固定的　抹茶にナッツを加えるときまたクラスを追加するのは大変

class NutsToppingIcecream : public Iceccream {
private:
    Iceccream* p_ice = NULL;
public:
    NutsToppingIcecream(Iceccream* ice) {
        p_ice = ice;
    }
    virtual string getName() override {
        string name = "ナッツ";
        if (p_ice) {
            name += p_ice->getName();
            return name;
        }
        else {
            return "error";
        }
    }

    virtual string howSweet() {
        if (p_ice) return p_ice->howSweet();
        else return "error";
    }
};


int main() {
    Iceccream* ice1 = new NutsToppingIcecream(new VanilaIce());
    Iceccream* ice2 = new NutsToppingIcecream(new GreenTeaIcecream());

    cout << ice1->getName() << ice1->howSweet() << endl;
    cout << ice2->getName() << ice2->howSweet() << endl;

    return 0;
}
