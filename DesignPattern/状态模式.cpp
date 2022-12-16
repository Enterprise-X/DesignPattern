#include "״̬ģʽ.h"


#pragma region ״̬������
class Context;
class State { // ����״̬�࣬����һ���ӿ��Է�װ��Context��һ���ض�״̬��ص���Ϊ
public:
	virtual void Handle(Context* c) = 0;
	virtual void GetName() = 0;
	virtual ~State() {}
};
#pragma endregion 

#pragma region ��������
class Context { // ά��һ��ConcreteState�����ʵ�������ʵ������Ϊ��ǰ״̬
private:
	State* state;
public:
	Context(State* s) { state = s; }
	void SwitchState() { // // ��������������������һ״̬
		if (state == NULL) return;
		state->GetName();
		state->Handle(this);
	}
	void SetState(State* s) { state = s; }
	virtual ~Context() {
		if (state != NULL) {
			delete state;
			state = NULL;
		}
	}
};
#pragma endregion 

#pragma region ����״̬��
// ����״̬�࣬ÿһ������ʵ����Context��һ��״̬�����Ϊ
class ConcreteStateA : public State {
public:
	void Handle(Context* c);
	void GetName();
};

class ConcreteStateB : public State {
public:
	void Handle(Context* c);
	void GetName();
};

class ConcreteStateC : public State {
public:
	void Handle(Context* c);
	void GetName();
};

void ConcreteStateA::Handle(Context* c) {
	printf("��ǰ:ConcreteStateA���л�Ϊ:ConcreteStateB\n");
	c->SetState(new ConcreteStateB());
}

void ConcreteStateA::GetName()
{
	printf("��ǰ״̬Ϊ:ConcreteStateA\n");
}

void ConcreteStateB::Handle(Context* c) {
	printf("��ǰ:ConcreteStateB���л�Ϊ:ConcreteStateC\n");
	c->SetState(new ConcreteStateC());
}

void ConcreteStateB::GetName()
{
	printf("��ǰ״̬Ϊ:ConcreteStateB\n");
}

void ConcreteStateC::Handle(Context* c) {
	printf("��ǰ:ConcreteStateC���л�Ϊ:ConcreteStateA\n");
	c->SetState(new ConcreteStateA());
}

void ConcreteStateC::GetName()
{
	printf("��ǰ״̬Ϊ:ConcreteStateC\n");
}

#pragma endregion 

void ״̬ģʽ::����()
{
	std::cout << "********************״̬ģʽ********************" << std::endl;

	State* s = new ConcreteStateA();
	Context* c = new Context(s);
	c->SwitchState();  // ConcreteStateA �л�״̬
	c->SwitchState();  // ConcreteStateB
	c->SwitchState();  // ConcreteStateC
	delete s;
	delete c;

	std::cout << "************************************************" << std::endl;
}
