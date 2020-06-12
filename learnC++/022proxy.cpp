#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include <vector>
#include <map>

using namespace::std;

/*Proxy�p�^�[��
proxy�p�^�[�����g���ƁA����N���X���ʂ̃N���X�̋@�\��\���ł���悤�ɂȂ�܂��B
�ォ��@�\��ǉ����Ă��A���l�ɃN���C�A���g����A�N�Z�X�����邱�Ƃ��o���܂��B
Security��Door*���󂯎����open�̒���door->open()���Ă���̂��|�C���g
https://techracho.bpsinc.jp/hachi8833/2017_10_11/46069#proxy
*/
class Door {
public:
    virtual void open() = 0;
    virtual void close() = 0;
    virtual ~Door() {};
};

class LabDoor : public Door {
public:
    void open() {
        cout << "labdoor open" << endl;
    }
    void close() {
        cout << "labdoor close" << endl;
    }
    ~LabDoor() {};
};

//�����ɃZ�L�����e�B�@�\��ǉ�����

class Security {
    Door* p_door;
public:
    Security(Door* door) {
        p_door = door;
    }

    void open(string pass) {
        if (pass == "password") {
            p_door->open();
        }
        else {
            cout << "pass���Ⴂ�܂�" << endl;
        }
    }

    void close() {
        p_door->close();
    }
};

int main() {
    Door* door = new LabDoor();
    door->open();
    door->close();

    Security* sec = new Security(door);
    sec->open("hoge");
    sec->open("password");
    sec->close();

    return 0;
}