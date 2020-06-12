#include <iostream>
#include <string>

using namespace std;

class Taro {
private:
	string word;

public:
	Taro(const string& newStr) {
		word = newStr;
	}

	~Taro() {};

	void HelloTaro();
	void SayWord() {
		cout << word << endl;
	};
};

void Taro::HelloTaro() {
	cout << "hello" << endl;
};

class LeaderOfSchool {
public:
	void nakayoku() {
		cout << "’‡—Ç‚­" << endl;
	}
};

class newTaro :public Taro, public LeaderOfSchool {
public:
	newTaro(string newStr) : Taro(newStr) {

	}
	~newTaro() {}

	void organizedClass() {
		nakayoku();
		HelloTaro();
	}
};

int main() {
	LeaderOfSchool leader = new newTaro();

	newTaro* ob = new newTaro("hello");
	ob->organizedClass();
	delete(ob);
}