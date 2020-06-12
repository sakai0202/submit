#include <iostream>
#include <string.h>
#include <list>
#include <vector>

using namespace::std;

/*
ブリッジパターン
機能を拡張するクラスと実装を拡張するクラスを分ける
機能を追加した際に、また全体の仮想関数をoverrideしなければいけない構造は手間である

PHPのコード↓を書き直した
https://techracho.bpsinc.jp/hachi8833/2017_10_11/46069#bridge

この例だとWEBページのアバウト、キャリアページのほかにページを追加した際にも、


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
        return this->thema->getColor() + "のAboutpage";
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
        return this->thema->getColor() + "のCarrerPage";
    }
};

int main() {
    DarkThema* darkthema = new DarkThema();

    About* about = new About(darkthema);
    Careers* carrer = new Careers(darkthema);

    cout << about->getContent() << endl;
    cout << carrer->getContent() << endl;
}

