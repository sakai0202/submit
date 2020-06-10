#include <iostream>
#include <algorithm>
#include <string.h>
#include <list>
#include <vector>
#include "ChatRoomMediator.h"
#include "ChatUser.h"

using namespace::std;

/*mediator�p�^�[��
�e�I�u�W�F�N�g�������̏�Ԃ��ς�����Ƃ���mediator�ɘA�����Amediator�������𔻒f���Ďw��������
���G�ɗ��ݍ�������������𖞂����Ȃ���ΗL���ɂȂ�Ȃ��{�^���@�Ȃǂɂ��L��
���ݎQ�Ƃ̊֌W�ŕ����t�@�C��
���̃R�[�h��C++�ŏ�����
https://techracho.bpsinc.jp/hachi8833/2017_10_17/46071#mediator
*/

class ChatRoom : public ChatRoomMediator {
public:
    void showMessage(ChatUser* user, string message) override {

        cout << "[" << user->GetName() << "]" << message << endl;
    }
};

int main() {
    ChatRoomMediator* mediator = new ChatRoom();

    ChatUser* stu1 = new ChatUser("�c��", mediator);
    ChatUser* stu2 = new ChatUser("�R�c", mediator);

    string s1 = "����ɂ���";
    string s2 = "����΂��";
    stu1->send(s1);
    stu2->send(s2);
}





