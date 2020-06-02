#include <iostream>

using namespace std;

class Animal {
protected:
    bool isHungry;
    string favoriteFood;
public:
    Animal(string foodname) {
        favoriteFood = foodname;
        isHungry = false;
    }

    virtual void ToEat() {
        //�I�[�o�[���[�h�����֐�
    }

    void SetIsHungty(bool judge) {
        isHungry = judge;
    }
    bool GetIsHungty(bool judge) {
        return isHungry;
    }
};

class Dog : public Animal {
public:
    Dog() : Animal("bone") {};

    void ToEat() {
        cout << "wanwan" << endl;

        if (isHungry == true) {
            cout << favoriteFood + "is Eated!" << endl;

        }
        else
            cout << "Not hungry" << endl;
    }
};
class Cat : public Animal {
public:
    Cat() : Animal("matatabi") {};

    void ToEat() {

        cout << "nyan" << endl;

        if (isHungry == true) {
            cout << favoriteFood + "is Eated!" << endl;
        }
        else
            cout << "Not hungry" << endl;
    }
};
class Tiger : public Animal {
public:
    Tiger() : Animal("human") {};
    void ToEat() {

        cout << "ugaaa" << endl;

        if (isHungry == true) {
            cout << "You are eaten!" << endl;
        }
        else
            cout << "Not hungry" << endl;
    }
};

class Breder {
private:
    Animal* animal;

    Cat cat;
    Dog dog;
    Tiger tiger;

public:
    Breder(int animal_pattern) {
        switch (animal_pattern) {
        case 0:
            animal = &dog;
            break;
        case 1:
            animal = &cat;
            break;
        default:
            animal = &tiger;
            break;
        }
    }

    void Sanpo() {
        animal->SetIsHungty(true);
    }
    void GiveFood() {
        animal->ToEat();
        animal->SetIsHungty(false);
    }
};


int main() {

    Breder* bre1 = new Breder(1); // cat
    //�u���[�_�[�N���X�̃������m��
    //�����œ�����cat,dog,tiger�̃������y�уA�j�}���̃|�C���^�̃��������m�ۂ����

    bre1->GiveFood(); //Not hungry
    bre1->GiveFood(); //Not hungry
    bre1->Sanpo(); // ->hungry��
    bre1->GiveFood(); //hungry�Ȃ̂ł܂����т�H�ׂ�
    bre1->GiveFood(); //Not hungty

}