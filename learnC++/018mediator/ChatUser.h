#pragma once
#include <iostream>
#include <string>
#include "ChatRoomMediator.h"

using namespace std;

class ChatRoomMediator;

class ChatUser {
protected:
    string name;
    ChatRoomMediator* chatmeditator;
public:
    ChatUser(string nam, ChatRoomMediator* mediator);

    void send(string& message);

    string GetName() {
        return name;
    }
};
