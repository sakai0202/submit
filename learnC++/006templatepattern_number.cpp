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
    Wood() : Cuttable() {
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
    virtual void draw(Cuttable hanzai) = 0;
    virtual void cut(Cuttable hanzai) = 0;
    virtual void print(Cuttable hanzai) = 0;

    void createWoodCutPrint() {

        Wood hanzai;

        draw(hanzai);
        cut(hanzai);
        print(hanzai);

        hanzai.tree();
    }
};

class TanakasWoodCutPrint :public WoodCutPrint {
public:
    TanakasWoodCutPrint() {

    }

    void draw(Cuttable hanzai) override {
        cout << "hanzai �Ƀ}�W�b�N���g���đ�D���ȏ��̎q�̊G��`��" << endl;
        cout << hanzai.get_isCutted() << endl;

    }
    void cut(Cuttable hanzai) override {
        hanzai.set_isCutted(true);
        cout << "���������g���čו��܂Œ��J�� hanzai �𒤂�" << endl;
    }
    void print(Cuttable hanzai) override {

        cout << "�ŉ�C���N�Ɣn�����g���č����Ƀv�����g����" << endl;
        cout << hanzai.get_isCutted() << endl;

    }
};

int main() {
    TanakasWoodCutPrint* tanaka = new TanakasWoodCutPrint();
    tanaka->createWoodCutPrint();//�Q�Ƃɂ��Ȃ������̂őS��false�ɁB


