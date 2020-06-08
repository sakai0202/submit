#include <iostream>
#include <string.h>
#include <list>
#include <vector>

using namespace::std;

//プロトタイプパターンとはクラスからインスタンスを生成するのではなく、
//別のインスタンスからコピーしてインスタンスを生成するパターンの事
//http://marupeke296.com/DP_Prototype.html
//https://techracho.bpsinc.jp/hachi8833/2017_10_02/46064#prototype
//https://www.techscore.com/tech/DesignPattern/Prototype.html/

class Sheep {
protected:
    string name;
    string category;
public:
    Sheep(string nam) {
        name = nam;
        category = "ヒツジ";
    }

    Sheep* Clone() {
        Sheep* p = new Sheep(name);
        return p;
    }
    void SetCategory(string& newcat) {
        category = newcat;
    }
    string GetCategory() {
        return category;
    }
    string GetName() {
        return name;
    }
};

int main() {
    Sheep* s1 = new Sheep("ドリー");
    Sheep* s2 = s1->Clone();
    string newcategory = "クローン";
    s2->SetCategory(newcategory);

    cout << s1->GetName() << s1->GetCategory() << endl;
    cout << s2->GetName() << s2->GetCategory() << endl;
}

