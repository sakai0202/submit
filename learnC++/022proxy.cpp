#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include <vector>
#include <map>

using namespace::std;

/*Proxyパターン
proxyパターンを使うと、あるクラスが別のクラスの機能を表現できるようになります。
後から機能を追加しても、同様にクライアントからアクセスをすることが出来ます。
SecurityがDoor*を受け取ってopenの中でdoor->open()しているのがポイント
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

//ここにセキュリティ機能を追加する

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
            cout << "passが違います" << endl;
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