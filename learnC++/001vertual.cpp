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
        //オーバーロードされる関数
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

//アニマルを子供に持つブリーダー
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

//既存のアニマルを受け取るブリーダー
class Breder2 {
private:
    Animal* animal;

public:
    Breder2(Animal* anim) {
        animal = anim;
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

    Dog* dog1 = new Dog();
    Breder2* bre2 = new Breder2(dog1);

    bre2->GiveFood(); //Not hungry
    bre2->GiveFood(); //Not hungry
    bre2->Sanpo(); // ->hungryに
    bre2->GiveFood(); //hungryなのでまたたびを食べる
    bre2->GiveFood(); //Not hungty
}
