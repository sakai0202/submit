#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <list>
#include <vector>
#include <map>

using namespace::std;

/*interpreterパターン
ミニ言語を作る。スクリプトなどからコードを実行するようにする。
http://marupeke296.com/DP_Interpreter.html
*/

class Context {
    std::vector<string> commands;
    int current_index = 0;
    int max_index = 0;

public:
    //inputscript load
    Context(std::string inputscript) : current_index(0), max_index(0) {
        istringstream ss(inputscript);
        std::string buf;
        while (getline(ss, buf, ',')) {
            commands.push_back(buf);
            max_index++;
        }
    }

    void next() {
        current_index++;
        if (current_index > max_index) cout << "Context error" << endl;
    }

    string getCurrentCommand() {
        return commands[current_index];
    }

};
class Command {
public:
    virtual void execute(Context* con) = 0;
};

class CommandListCommand : public Command {
public:
    void execute(Context* con) {
        while (1) {
            string current_command = con->getCurrentCommand();
            //if (current_command == NULL) cout << "no end" << endl;
            if (current_command == "end") break;
            else if (current_command == "print1") cout << "print1" << endl;
            else if (current_command == "print2") cout << "print2" << endl;
            else if (current_command == "print3") cout << "print3" << endl;
            else cout << "illigal command" << endl;

            con->next();
        }
    }
};


class JobCommand : public Command {
public:
    void execute(Context* con) {
        if (con->getCurrentCommand() != "begin") {
            cout << "illigal command" << endl;
        }

        CommandListCommand* cmdlst = new CommandListCommand();
        con->next();
        cmdlst->execute(con);
    }
};

int main() {
    string script = "begin,print1,print2,print3,hoge,print1,end";
    Context* con = new Context(script);

    JobCommand* job = new JobCommand();
    job->execute(con);

    return 0;
}
