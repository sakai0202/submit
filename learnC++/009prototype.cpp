#include <iostream>
#include <string.h>
#include <list>
#include <vector>

using namespace::std;

//�v���g�^�C�v�p�^�[���Ƃ̓N���X����C���X�^���X�𐶐�����̂ł͂Ȃ��A
//�ʂ̃C���X�^���X����R�s�[���ăC���X�^���X�𐶐�����p�^�[���̎�
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
        category = "�q�c�W";
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
    Sheep* s1 = new Sheep("�h���[");
    Sheep* s2 = s1->Clone();
    string newcategory = "�N���[��";
    s2->SetCategory(newcategory);

    cout << s1->GetName() << s1->GetCategory() << endl;
    cout << s2->GetName() << s2->GetCategory() << endl;
}

