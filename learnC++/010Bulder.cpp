#include <iostream>
#include <string.h>
#include <list>
#include <vector>

using namespace::std;

/*
ビルダーパターン
生成手順を共通化する。
↓イメージ(https://maku.blog/p/7gmjvza/ )より
Product* Director::CreateProduct(Builder *builder) {
    builder->CreateStep1();
    builder->CreateStep2();
    builder->CreateStep3();
    return builder->GetProduct();
}
https://www.techscore.com/tech/DesignPattern/Builder.html/
*/

class SaltWater {
public:
    double salt;
    double water;

    SaltWater(double wat, double sal) {
        this->salt = sal;
        this->water = wat;
    }
};


class Builder {
public:
    virtual void addSalt(double saltAmount) = 0;
    virtual void addWater(double waterAmount) = 0;
    virtual SaltWater* getResult() = 0;
};

class SaltWaterBuilder : public Builder {
private:
    SaltWater* saltwater;
public:
    SaltWaterBuilder() {
        saltwater = new SaltWater(0, 0);
    }

    void addSalt(double saltAmount) override {
        saltwater->salt += saltAmount;
    }

    void addWater(double waterAmount) override {
        saltwater->water += waterAmount;
    }

    SaltWater* getResult() override {
        return saltwater;
    }
};

class Director {
private: Builder* builder;
public:
    Director(Builder* build) {
        this->builder = build;
    }

    void constract() {
        builder->addSalt(40);
        builder->addWater(100);

        builder->addSalt(30);
        builder->addWater(200);

    }
};


int main() {

    Builder* builder = new SaltWaterBuilder();
    Director* dir = new Director(builder);

    dir->constract();

    SaltWater* saltWater = (SaltWater*)builder->getResult();

    cout << "salt" << saltWater->salt << "water" << saltWater->water << endl;
}

