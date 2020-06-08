#include <iostream>
#include <string>
using namespace std;

class YumiChanState;
class GoodState;
class BadState;


class YumiChanState {
private:
	string stateName;
public:
	YumiChanState(string name) : stateName(name) {};
	virtual ~YumiChanState();

	virtual void morinigGreet(YumiChan*);
	virtual void goodBye(YumiChan*);

	string GetName() { return stateName }
	//	virtual void angry(YumiChan* yumi);

};

class BadState : public YumiChanState {
public:
	BadState() : YumiChanState("Bad") {};
	virtual ~BadState();

	virtual void moriningGreet(YumiChan* yumi) {
		yumi->SetState(YumiChan::STATE_BAD);
		cout << "makebad" << endl;
	};

	virtual void goodBye(YumiChan* yumi) {
		cout << "makegood" << endl;
		yumi->SetState(YumiChan::STATE_GOOD);
	};
};

class GoodState : public YumiChanState {
public:
	GoodState() : YumiChanState("Good") {};
	virtual ~GoodState();

	virtual void moriningGreet(YumiChan* yumi) {
		yumi->SetState(YumiChan::STATE_BAD);
		cout << "makebad" << endl;
	};

	virtual void goodBye(YumiChan* yumi) {
		cout << "makegood" << endl;
		yumi->SetState(YumiChan::STATE_GOOD);
	};
};

class SleepState : public YumiChanState {
public:
	SleepState() : YumiChanState("Good") {};
	virtual ~SleepState();

	virtual void moriningGreet(YumiChan* yumi) {
		yumi->SetState(YumiChan::STATE_BAD);
		cout << "makebad" << endl;
	};

	virtual void goodBye(YumiChan* yumi) {
		cout << "makegood" << endl;
		yumi->SetState(YumiChan::STATE_GOOD);
	};
};
class YumiChan {
private:
	YumiChanState* m_pState;
public:
	enum State {
		STATE_GOOD,
		STATE_BAD,
		STATE_SLEEP
	};

	YumiChan() : m_pState(new BadState()) {

	}

	~YumiChan() {
		delete m_pState;
	}

	void Angry() {
		m_pState->morinigGreet(this);
	}
	void FeelGood() {
		m_pState->goodBye(this);
	}

	void SetState(State state) {
		cout << "Changeing from" << m_pState->GetName() << "to";
		delete m_pState;

		if (state == STATE_BAD) {
			m_pState = new BadState();
		}

		if (state == STATE_GOOD) {
			m_pState = new GoodState();
		}

		if (state == STATE_SLEEP) {
			m_pState = new SleepState();
		}
	}
};


int main() {

	YumiChan yumi;

	yumi.Angry();
	yumi.FeelGood();

	return 0;
}







