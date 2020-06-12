#include <iostream>
#include <string.h>
#include <list>
#include <vector>

using namespace::std;

/*
�u���b�W�p�^�[��
�@�\���g������N���X�Ǝ������g������N���X�𕪂���
�@�\��ǉ������ۂɁA�܂��S�̂̉��z�֐���override���Ȃ���΂����Ȃ��\���͎�Ԃł���

PHP�̃R�[�h��������������
https://techracho.bpsinc.jp/hachi8833/2017_10_11/46069#bridge

���̗Ⴞ��WEB�y�[�W�̃A�o�E�g�A�L�����A�y�[�W�̂ق��Ƀy�[�W��ǉ������ۂɂ��A


*/

class Thema {
public:
    virtual string getColor() = 0;
};

class DarkThema : public Thema {
public:
    string getColor() {
        return "Dark Black";
    }
};

class LightThema : public Thema {
public:
    string getColor() {
        return "Off White";
    }
};

class AquaTheme : public Thema {
public:
    string getColor() {
        return "Light blue";
    }
};

class WebPage {
public:
    WebPage(Thema* thema) {};
    virtual string getContent() = 0;
};

class About : public WebPage {

protected:
    Thema* thema;
public:
    About(Thema* them) : WebPage(them) {
        this->thema = them;
    }
    string getContent() override {
        return this->thema->getColor() + "��Aboutpage";
    }
};

class Careers : public WebPage {

protected:
    Thema* thema;
public:
    Careers(Thema* them) :WebPage(them) {
        this->thema = them;
    }
    /*
    explicit Careers(Thema* thema) {
        this->thema = thema;
    }*/


    string getContent() override {
        return this->thema->getColor() + "��CarrerPage";
    }
};

int main() {
    DarkThema* darkthema = new DarkThema();

    About* about = new About(darkthema);
    Careers* carrer = new Careers(darkthema);

    cout << about->getContent() << endl;
    cout << carrer->getContent() << endl;
}

