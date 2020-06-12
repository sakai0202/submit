#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include <vector>
#include <map>

using namespace::std;

/*FlyWeight�p�^�[��
���̗ގ��I�u�W�F�N�g���ł��邾�����L���������g�p�ʂ��ŏ����ɗ}����I�u�W�F�N�g
���L�ł���f�[�^��intrinsic, ���L�ŋ@���f�[�^��extrinsic �ƌĂсAextrinsic�Ȃ��̂̓��\�b�h���s���Ƀp�����[�^�œn���B
���L�f�[�^�Ƌ��L���Ȃ��f�[�^�𕪂���
https://maku.blog/p/7gmjvza/#11-flyweight-�p�^�[��
�Ƃ�����Ă�����̂̂��������s�ςȂ��̂ɂ̂ݎg���ׂ�
*/


class Character {
private:
    string name; //���L����
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
