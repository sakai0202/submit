/*������ނ̃I�u�W�F�N�g�𐶐�����Ƃ��͈�̃N���X�Ő������܂��傤�B
//https://techracho.bpsinc.jp/hachi8833/2017_10_02/46064#abstract-factory

Wikipedia :abstract factory�p�^�[���́A�e�[�}�̋��ʂȌʂ̃t�@�N�g���[�̃O���[�v���J�v�Z���������i��񋟂���B���̂Ƃ��A�t�@�N�g���[�̋�̓I�ȃN���X���w�肵�Ȃ��B
�ɂ߂ĕ�����₷�������@https://qiita.com/morimotof/items/67a9e2a8d7e15ea321d2

https://www.xmisao.com/2013/12/11/gof-designpattern-java-abstractfactory.html
    ����̑g�ݍ��킹���v�������I�u�W�F�N�g�Q�����Ȃ������ł���
    ���������I�u�W�F�N�g�̎������B�����邱�Ƃ��ł���

���̗�ł͍쐬���h�A�̎�ނɍ���Ȃ��E�l���ĂԂ��Ƃ͂Ȃ��B
�܂��A�ォ��e�Ղɕʂ̎�ނ̃h�A��ǉ����鎖���o����
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
        cout << "�؂̃h�A" << endl;
    }
};

class IronDoor : public Door {
public:
    void getDescription() override {
        cout << "�S�̃h�A" << endl;
    }
};

class DoorFiting {
public:
    virtual void getDescription() = 0;
};

class IronMan : public DoorFiting {
public:
    void getDescription() {
        cout << "�S�̃h�A������" << endl;
    }
};

class WoodMan : public DoorFiting {
public:
    void getDescription() {
        cout << "�؂̃h�A������" << endl;
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

