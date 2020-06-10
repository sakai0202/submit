#include "ChatUser.h"

using namespace std;

ChatUser::ChatUser(string nam, ChatRoomMediator* mediator) {
    name = nam;
    chatmeditator = mediator;
}
void ChatUser::send(string& message) {
    {
        chatmeditator->showMessage(this, message);
    }
}