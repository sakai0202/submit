#include <iostream>
#include <algorithm>
#include <string.h>
#include <list>
#include <vector>

using namespace::std;

/*�`�F�[���I�u���X�|���V�r���e�B�p�^�[��
���N�G�X�g�̓`���ƓK�؂ȃI�u�W�F�N�g�ł̏���
cf.��C++�ŏ���������
https://techracho.bpsinc.jp/hachi8833/2017_10_17/46071#chain-of-responsibility
*/

class Account {
protected:
    Account* successor;
private:
    float money;
    string accountname;
public:
    Account(const float& mon, string nam) {
        money = mon;
        accountname = nam;
    }


    void setNext(Account* nextAccount) {
        successor = nextAccount;
    }

    bool canPay(const float& amount) {
        return money >= amount;
    }

    void pay(const float& amountToPay) {
        if (this->canPay(amountToPay)) {
            cout << accountname << "�ɂĎx����" << endl;
        }
        else if (this->successor) {
            cout << accountname << "�c���s���B" << this->successor->accountname << "�ɂĎx����������" << endl;
            this->successor->pay(amountToPay);
        }
        else {
            cout << "�ǂ̃A�J�E���g������������܂���" << endl;
        }
    }
};

class Bank : public Account {
public:
    Bank(const float& iniMoney) : Account(iniMoney, "Bank") {
    }
    ~Bank() {};
};

class Paypal : public Account {
public:
    Paypal(const float& iniMoney) : Account(iniMoney, "Paypal") {
    }
    ~Paypal() {};
};

class Bitcoin : public Account {
public:
    Bitcoin(const float& iniMoney) : Account(iniMoney, "BitCoin") {
    }
    ~Bitcoin() {};
};

int main() {
    Account* bank = new Bank(100);
    Account* paypal = new Paypal(200);
    Account* bitcoin = new Bitcoin(300);

    bank->setNext(paypal);
    paypal->setNext(bitcoin);

    bank->pay(259);
}
