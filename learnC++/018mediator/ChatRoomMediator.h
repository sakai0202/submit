#pragma once
#include "ChatUser.h"
#include <string>

using namespace std;

class ChatUser;

class ChatRoomMediator {
public:
    virtual void showMessage(ChatUser* user, string message) = 0;
};
