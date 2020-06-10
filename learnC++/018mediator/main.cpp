#include <iostream>
#include <algorithm>
#include <string.h>
#include <list>
#include <vector>
#include "ChatRoomMediator.h"
#include "ChatUser.h"

using namespace::std;

/*mediatorパターン
各オブジェクトが自分の状態が変わったときにmediatorに連絡し、mediatorが条件を判断して指示をする
複雑に絡み合ったある条件を満たさなければ有効にならないボタン　などにも有効
相互参照の関係で複数ファイル
このコードをC++で書いた
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

    ChatUser* stu1 = new ChatUser("田中", mediator);
    ChatUser* stu2 = new ChatUser("山田", mediator);

    string s1 = "こんにちは";
    string s2 = "こんばんは";
    stu1->send(s1);
    stu2->send(s2);
}





