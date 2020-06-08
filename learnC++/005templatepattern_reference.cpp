#include <iostream>
#include <string.h>
#include <list>
#include <vector>

using namespace::std;

class Cuttable {
private:
    bool isCutted;

public:
    Cuttable() {
        isCutted = false;
    }
    ~Cuttable() {};

    bool get_isCutted() { return isCutted; };
    void set_isCutted(bool newbool) { isCutted = newbool; };
};


class Wood : public Cuttable {
public:
    Wood() : Cuttable() {
    }
    ~Wood() { cout << "デストラクタ" << endl; };

    void tree() {
        cout << "tree" << endl;
    }

};

class Fish : public Cuttable {
    void jump() {
        cout << "pichipichi" << endl;
    }
};

class WoodCutPrint {
public:
    virtual void draw(Cuttable& hanzai) = 0;
    virtual void cut(Cuttable& hanzai) = 0;
    virtual void print(Cuttable& hanzai) = 0;

    void createWoodCutPrint() {

        Wood hanzai;

        draw(hanzai);
        cut(hanzai);
        print(hanzai);

        hanzai.tree();
    }
};

class TanakasWoodCutPrint :public WoodCutPrint {
public:
    TanakasWoodCutPrint() {

    }

    void draw(Cuttable& hanzai) override {
        cout << "hanzai にマジックを使って大好きな女の子の絵を描く" << endl;
        cout << hanzai.get_isCutted() << endl;

    }
    void cut(Cuttable& hanzai) override {
        hanzai.set_isCutted(true);
        cout << "彫刻刀を使って細部まで丁寧に hanzai を彫る" << endl;
    }
    void print(Cuttable& hanzai) override {

        cout << "版画インクと馬簾を使って豪快にプリントする" << endl;
        cout << hanzai.get_isCutted() << endl;

    }
};

int main() {
    TanakasWoodCutPrint* tanaka = new TanakasWoodCutPrint();
    tanaka->createWoodCutPrint();
}

