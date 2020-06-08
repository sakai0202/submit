#include <iostream>
#include <string.h>
#include <list>
#include <vector>

using namespace::std;

class Cuttable {
private:
    bool isCutted;

public:
    Cuttable() {
        isCutted = false;
    }
    ~Cuttable() {};

    bool get_isCutted() { return isCutted; };
    void set_isCutted(bool newbool) { isCutted = newbool; };
};


class Wood : public Cuttable {
public:
    int num;

    Wood(int ini) : Cuttable() {
        num = ini;
    }
    ~Wood() { cout << "�f�X�g���N�^" << endl; };

    void tree() {
        cout << "tree" << endl;
    }

};

class Fish : public Cuttable {
    void jump() {
        cout << "pichipichi" << endl;
    }
};

class WoodCutPrint {
public:
    virtual void draw(Cuttable* hanzai) = 0;
    virtual void cut(Cuttable* hanzai) = 0;
    virtual void print(Cuttable* hanzai) = 0;

    void createWoodCutPrint() {

        Wood* hanzai = new Wood(100);

        cout << hanzai->num << endl;
        draw(hanzai);
        cut(hanzai);
        print(hanzai);

        cout << hanzai->num << endl;

        hanzai->tree();

    }
};

class TanakasWoodCutPrint :public WoodCutPrint {
public:
    TanakasWoodCutPrint() {

    }

    void draw(Cuttable* hanzai) override {
        cout << "hanzai �Ƀ}�W�b�N���g���đ�D���ȏ��̎q�̊G��`��" << endl;
        cout << hanzai->get_isCutted() << endl;

    }
    void cut(Cuttable* hanzai) override {
        hanzai->set_isCutted(true);
        cout << "���������g���čו��܂Œ��J�� hanzai �𒤂�" << endl;
    }
    void print(Cuttable* hanzai) override {

        cout << "�ŉ�C���N�Ɣn�����g���č����Ƀv�����g����" << endl;
        cout << hanzai->get_isCutted() << endl;
    }
};

int main() {

    TanakasWoodCutPrint* tanaka = new TanakasWoodCutPrint();
    tanaka->createWoodCutPrint();//�Q�Ƃɂ��Ȃ��ƒl���R�s�[����Ȃ� + ����Cuttble���|�C���^�������Ă���ƔߎS�Ȃ��Ƃ�
    
    /*
    int* a;
    a = new int(5);
    cout << *a << endl;
   // delete(a);
    a = new int(20);
    cout << *a << endl;
    */
}




