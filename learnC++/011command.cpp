#include <iostream>
#include <string.h>
#include <list>
#include <vector>

using namespace::std;

/* �R�}���h�p�^�[��
�R�����g�A�E�g�̓p�^�[�����g��Ȃ���@int�ŌĂѕ�����������ƐV����������ǉ�����ɂ́A
���C�����C�����A�Ăяo����錳�̎��������ɂ�else if��ǉ�����K�v������
�R�}���h�p�^�[���ł͌��̃r�[�J�[�N���X��ύX�����ɁA���낢��Ȏ�����ǉ����邱�Ƃ��o����
��ʓI�ɂ�command�𕡐��ǉ��ł���悤�ɂ��AInvoker�ɃR�}���h��push���ĊǗ������肷��
�܂��Aexecute�̒��ł̎��s���e��reciever�ƌĂ΂�镔���ɋL�q����
����
     command <-<> Invoker
        ���p��
      addsaltcommand , addwatercommand ,�Ȃ�
        ���쐬
       Main
��ʓI�ɂ�
                 command <-<> Invoker
                  ���p��
 Receiver <-<> concrete command
                  ���쐬
                 Client

cf :�R�}���h�p�^�[��
https://www.techscore.com/tech/DesignPattern/Command.html/
*/

class Beaker {
private:
    double salt = 0;
    double water = 0;
    bool melted;
public:
    static const int ADD_SALT;
    static const int ADD_WATER;
    Beaker(double wat, double sal) {
        this->salt = sal;
        this->water = wat;
        this->mix();
    }
    void addSalt(double amount) {
        this->salt += amount;
    }
    void addWater(double water) {
        this->salt += water;
    }
    void mix() {
        if (salt / (salt + water) * 100 < 26.4) {
            melted = true;
        }
        else {
            melted = false;
        }
    }

    double getSalt() {
        return salt;
    }
    double getWater() {
        return water;
    }
    bool isMelted() {
        return melted;
    }
    void Note() {
        cout << "��" << water << endl;
        cout << "�H��" << salt << endl;
        cout << "�Z�x" << (salt / (water + salt)) * 100 << "%" << endl;
    }

    void experiment(int param) {
        if (param == ADD_SALT) {
            while (isMelted()) {
                this->addSalt(1);
                this->mix();
            }
            Note();
        }
        else if (param == ADD_WATER) {
            while (isMelted()) {
                this->addSalt(1);
                this->mix();
            }
            Note();
        }
    }
};
const int Beaker::ADD_SALT = 1;
const int Beaker::ADD_WATER = 2;

class Command {
protected:
    Beaker* beaker;
public:
    void SetBeaker(Beaker* p_beaker) {
        beaker = p_beaker;
    }
    virtual void execute() = 0;
};

//1g��������R�}���h�N���X
class AddSaltCommand : public Command {
public:
    void execute() override {
        while (beaker->isMelted()) {
            beaker->addSalt(1);
            beaker->mix();
        }
        beaker->Note();
    }
};

class AddWaterCommand : public Command {
public:
    void execute() override {
        while (beaker->isMelted()) {
            beaker->addWater(10);
            beaker->mix();
        }
        beaker->Note();
    }
};

class MakeSaltWaterCommand : public Command {
public:
    void execute() override {
        beaker->mix();
        beaker->Note();
    }
};

int main() {
    Command* addSalt = new AddSaltCommand();
    Command* addWater = new AddWaterCommand();
    Command* makeSaltWater = new MakeSaltWaterCommand();

    addSalt->SetBeaker(new Beaker(100, 0));
    addWater->SetBeaker(new Beaker(0, 10));
    makeSaltWater->SetBeaker(new Beaker(90, 10));

    addSalt->execute();
    addWater->execute();
    makeSaltWater->execute();

    /*
    Beaker* beaker = new Beaker(100, 0);
    beaker->experiment(Beaker::ADD_SALT);

    Beaker* beaker2 = new Beaker(0, 10);
    beaker2->experiment(Beaker::ADD_WATER);
    */
}

