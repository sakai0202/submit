#include <iostream>
#include <string.h>
#include <list>
#include <vector>

using namespace::std;

/* �r�W�^�[�p�^�[��

�f�[�^�\���Ə����̕����������b�g�@�����̏C�����f�[�^�\���ɋy�΂Ȃ�
�f�[�^�\��Home�ɕύX���������Ateacher�͉ƒ떈�ɏ������s����
������Teacher�ŉ��z�֐���p���ċ�̓I�ȏ����͌p����ŏ���
���܂ł͐V��������������邽�т�Home���p�����āAHome�̒��œ����ς��Ă���

�E�󂯓���鑤�ɏ�����ǉ����邱�ƂȂ��A������ǉ����邱�Ƃ��ł���p�^�[��
��؂��񂿂̃e�X�g�̓_����80�ȉ���������{��@�̂悤�ȏ������B
��؂��񑤂ɏ������ɐ搶���ŏ�����
wikipedia:
Visitor �p�^�[���ł͏�Ԃ������Ƃ��ł���B����́A�I�u�W�F�N�g�ɑ΂��Ď��s�����A�N�V�������ȑO�̃A�N�V�����Ɉˑ�����悤�ȑ����̃P�[�X�ŋɂ߂ėL�p�ł���B

����
accepter <-<> Home
   ���@�p��      ��
TanakaHome , SuzukiHome

���:
visitor
 ���@�p��
 concrete visitor

 element <-<> ObjectStructure
   ���@�p��
conceteElement1 , concleteEkement2

cf.
https://www.techscore.com/tech/DesignPattern/Visitor.html/
https://ja.wikipedia.org/wiki/Visitor_�p�^�[��
*/

class TanakaHome;
class SuzukiHome;

class Teacher {
public:
    virtual void visit(TanakaHome* studentHome) = 0;
    virtual void visit(SuzukiHome* studentHome) = 0;
};

class Home {
public:
    virtual void praisedChild() = 0;
    virtual void reprovedChild() = 0;

};
class Acceptor {
public:
    virtual void accept(Teacher* teacher) = 0;
};

class TanakaHome : public Home, public Acceptor {
public:
    void praisedChild() override {
        cout << "excellent" << endl;
    }
    void reprovedChild() override {
        cout << "no no" << endl;
    }
    void accept(Teacher* teacher) override {
        teacher->visit(this);
    }
};
class SuzukiHome : public Home, public Acceptor {
public:
    void praisedChild() override {
        cout << "good" << endl;
    }
    void reprovedChild() override {
        cout << "?" << endl;
    }
    void accept(Teacher* teacher) override {
        teacher->visit(this);
    }
};

class RookieTeacher : public Teacher {
public:
    void visit(TanakaHome* studentHome) {
        studentHome->praisedChild();
    }
    void visit(SuzukiHome* studentHome) {
        studentHome->reprovedChild();
    }
};

int main() {
    SuzukiHome* suzuki = new SuzukiHome();
    TanakaHome* tanaka = new TanakaHome();

    RookieTeacher* tea = new RookieTeacher();
    tea->visit(suzuki);
    tea->visit(tanaka);
}










