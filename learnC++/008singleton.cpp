#include <iostream>
#include <string.h>
#include <list>
#include <vector>

using namespace::std;

/*
�V���O���g���p�^�[���ł̓C���X�^���X���\�b�h�ł͂Ȃ�static�𗘗p�����N���X���\�b�h�ɂ�肻�̒P�ꐫ���������܂��B
�R���X�g���N�^��private�ɂ��邱�Ƃɂ�肻�̒P�ꐫ��ۏ؂��܂��B
�����A�̋@�\���W���Ǘ�����ꏊ��񋟂���ړI�Ŏg�p����܂��B
cf.�V���O���g���p�^�[��
https://qiita.com/narumi_/items/b205e59e7fc81695f380
cf.�N���X���\�b�h
https://cpp-lang.sevendays-study.com/day5.html
*/

class RegisterNote {
private:
    int num;
protected:
    static RegisterNote* registerNote;
    RegisterNote() {
        num = 0;
    };
public:
    static RegisterNote* getInstance() {
        return registerNote;
    }
    static void Create();
    static void Destroy();

    void Addnum() { num++; };
    void Subnum() { num--; };
    int Getnum() { return num; };

};

RegisterNote* RegisterNote::registerNote = NULL;

void RegisterNote::Create() {
    if (!registerNote) {
        registerNote = new RegisterNote();
    }
}
void RegisterNote::Destroy() {
    if (!registerNote) {
        delete registerNote;
        registerNote = NULL;
    }
}

int main() {
    RegisterNote::Create();

    RegisterNote::getInstance()->Addnum();
    cout << RegisterNote::getInstance()->Getnum() << endl;
    RegisterNote::getInstance()->Addnum();
    RegisterNote::getInstance()->Addnum();
    RegisterNote::getInstance()->Addnum();

    cout << RegisterNote::getInstance()->Getnum() << endl;
    RegisterNote::Destroy();
}


