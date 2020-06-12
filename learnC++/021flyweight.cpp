#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include <vector>
#include <map>

using namespace::std;

/*FlyWeightパターン
他の類似オブジェクトをできるだけ共有しメモリ使用量を最小限に抑えるオブジェクト
共有できるデータをintrinsic, 共有で機内データをextrinsic と呼び、extrinsicなものはメソッド実行時にパラメータで渡す。
共有データと共有しないデータを分ける
https://maku.blog/p/7gmjvza/#11-flyweight-パターン
とかかれているもののそもそも不変なものにのみ使うべき
*/


class Character {
private:
    string name; //共有部分
public:
    Character(string na) : name(na) {
    }
    ~Character() {};

    void Draw(int x, int y) {
        cout << "character is now x" << x << "y" << y << endl;
    }
};

class CharacterFactory {
    map<string, Character*>* m_chara;

public:
    CharacterFactory() {
        m_chara = new map<string, Character*>;
    }
    ~CharacterFactory() {
        m_chara->clear();
    };

    Character* GetCharacter(string keyname) {
        int check = m_chara->count(keyname);
        //    string keyCheck = m_chara->find(keyname);
        if (check == 0) {
            m_chara->emplace(keyname, new Character("Name:" + keyname));
            cout << "new make" << endl;
            return m_chara->at(keyname);
        }
        else {
            cout << "reuse" << endl;
            return m_chara->at(keyname);
        }
    }
};

int main() {
    CharacterFactory* factory = new CharacterFactory();
    Character* pCH1 = factory->GetCharacter("sakai");
    Character* pCH2 = factory->GetCharacter("sakai");

    pCH1->Draw(1, 2);
    pCH2->Draw(3, 4);
    return 0;
}
