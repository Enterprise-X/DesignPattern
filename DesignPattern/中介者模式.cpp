#include "�н���ģʽ.h"
#include <map>
#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif

using namespace std;

class Colleague;

// �н�ӿ� ������
class Mediator {
public:
	virtual void Send(string str, Colleague* colleague) = 0;
};

// ��Ӧ�ӿ� ������
class Colleague {
public:
	virtual void Notify() = 0;

	void SetMediator(Mediator* mediator) {
		mediator_ = mediator;	
	}
	int m_nId = -1;
protected:
	Mediator* mediator_ = nullptr;
};

// ��Ӧ�ӿ�A
class ConcreteColleagueA : public Colleague 
{
	
public:
	ConcreteColleagueA(int id)
	{
		m_nId = id;
	}

	void Send(string str) {
		mediator_->Send(str, this);
	}

	void Notify() {
		cout << "ConcreteColleagueA Get a msg" << endl;
	}
};

// ��Ӧ�ӿ�B
class ConcreteColleagueB : public Colleague {
public:
	ConcreteColleagueB(int id)
	{
		m_nId = id;
	}


	void Send(string str) {
		mediator_->Send(str, this);
	}

	void Notify() {
		cout << "ConcreteColleagueB Get a msg" << endl;
	}
};

// ʵ���н飺A�� send to B�࣬ B�� send to A��
class ConcreteMediator : public Mediator {
public:
	void AddColleague(Colleague* colleague) 
	{
		if (colleague)
		{
			m_mapColleague[colleague->m_nId] = colleague;
		}
	}



	void Send(string str, Colleague* colleague) 
	{
		cout << str << endl;
		m_mapColleague[colleague->m_nId]->Notify();
	}

private:
	map<int, Colleague*> m_mapColleague;

};

/*
Mediator�н������
|
ConcreteMediator ����ʵ���н�


Colleague��Ӧ�ӿڳ�����
|
ConcreteColleagueA��Ӧ�ӿ�A-ConcreteColleagueB��Ӧ�ӿ�B

ConcreteColleague.SetMediator
*/
void �н���ģʽ::����()
{
	std::cout << "********************�н���ģʽ********************" << std::endl;

	ConcreteMediator* mediator = new ConcreteMediator();

	ConcreteColleagueA* colleague_a1 = new ConcreteColleagueA(1);
	ConcreteColleagueA* colleague_a2 = new ConcreteColleagueA(2);
	ConcreteColleagueB* colleague_b1 = new ConcreteColleagueB(3);
	ConcreteColleagueB* colleague_b2 = new ConcreteColleagueB(4);

	colleague_a1->SetMediator(mediator);
	colleague_a2->SetMediator(mediator);
	colleague_b1->SetMediator(mediator);
	colleague_b2->SetMediator(mediator);

	mediator->AddColleague(colleague_a1);
	mediator->AddColleague(colleague_a2);
	mediator->AddColleague(colleague_b1);
	mediator->AddColleague(colleague_b2);

	colleague_a1->Send("a1 , send a msg");
	colleague_a2->Send("a2 , send a msg");
	colleague_b1->Send("b1 , send a msg");
	colleague_b2->Send("b2 , send a msg");

	SAFE_DELETE(colleague_a1);
	SAFE_DELETE(colleague_a2);
	SAFE_DELETE(colleague_b1);
	SAFE_DELETE(colleague_b2);


	std::cout << "************************************************" << std::endl;
}
