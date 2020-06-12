#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include <vector>

using namespace::std;

/*Decorator�p�^�[��
�u�����ҁv�@����g�ƒ��g�̓��ꎋ�@�@�\�������Ԃ��Ă���
���b�v�A�ʂ̃I�u�W�F�N�g�ւ̋@�\�̒ǉ�
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
        return "�o�j���A�C�X";
    }
    string howSweet() override {
        return "�o�j���̖�";
    }
    ~VanilaIce() {};
};

class GreenTeaIcecream : public Iceccream {
public:
    virtual string getName() override {
        return "�����A�C�X";
    }
    string howSweet() override {
        return "������";
    }
    ~GreenTeaIcecream() {};
};

//���̃A�C�X�ɋ@�\��ǉ�����
class NutsVanilaIce : public VanilaIce {
public:
    string getName() override {
        return "�i�b�c����o�j���A�C�X�N���[��";
    }

    ~NutsVanilaIce() {};
};
//�p���𗘗p�����@�\�̒ǉ��͌Œ�I�@�����Ƀi�b�c��������Ƃ��܂��N���X��ǉ�����̂͑��

class NutsToppingIcecream : public Iceccream {
private:
    Iceccream* p_ice = NULL;
public:
    NutsToppingIcecream(Iceccream* ice) {
        p_ice = ice;
    }
    virtual string getName() override {
        string name = "�i�b�c";
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
