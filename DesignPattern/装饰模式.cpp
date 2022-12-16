#include "װ��ģʽ.h"

//���󹹼�
class Component
{
public:
	Component() {}
	virtual void Operation() = 0;
};


#pragma region ����
//����ʵ�ֹ�����
class ConcreteComponent :public Component
{
public:
	ConcreteComponent() {}
	void Operation() {
		printf("�����������\n");
	}
};
#pragma endregion

#pragma region װ��

//����װ����
class Decorator :public Component
{
public:
	Decorator() {}
	Decorator(Component* c) {
		this->component = c;
	}
	void Operation() {
		this->component->Operation();
	}
	Component* GetComponent() {
		return this->component;
	}
	void SetComponent(Component* c) {
		this->component = c;
	}
private:
	Component* component;
};

//����װ����:DecoratorA
class DecoratorA :public Decorator
{
public:
	DecoratorA() {}
	DecoratorA(Component* c) {
		this->SetComponent(c);
	}
	void Operation() {
		this->GetComponent()->Operation();
		this->NewBehavior();
	}
	void NewBehavior() {
		printf("����װ����ΪA\n");
	}
};

//����װ����:DecoratorB
class DecoratorB :public Decorator
{
public:
	DecoratorB() {}
	DecoratorB(Component* c) {
		this->SetComponent(c);
	}
	void Operation() {
		this->GetComponent()->Operation();
		this->NewBehavior();
	}
	void NewBehavior() {
		printf("����װ����ΪB\n");
	}
};

//����װ���ࣺDecoratorC
class DecoratorC :public Decorator
{
public:
	DecoratorC() {}
	DecoratorC(Component* c) {
		this->SetComponent(c);
	}
	void Operation() {
		this->GetComponent()->Operation();
		this->NewBehavior();
	}
	void NewBehavior() {
		printf("����װ����ΪC\n");
	}
};

#pragma endregion

/*
Component����
|
|
ConcreteComponent���幹��----Decoratorװ����

Decoratorװ����
|
|
DecoratorA----DecoratorB----DecoratorC

cctCom=new ConcreteComponent
A=DecoratorA(cctCom)
B=DecoratorA(B)
C=DecoratorA(C)
C.opt()��B.opt()��A.opt()��cctCom.opt()
���Խ�����ʽ����
*/
void װ��ģʽ::����()
{
	std::cout << "********************װ��ģʽ********************" << std::endl;

	printf("\n��һ���������\n");
	Component* cctCom1;
	Component* com_A1;
	cctCom1 = new ConcreteComponent();
	com_A1 = new DecoratorA(cctCom1);
	com_A1->Operation();

	printf("\n�ڶ����������\n");
	Component* cctCom2;
	Component* com_A2; 	Component* com_B2;
	cctCom2 = new ConcreteComponent();
	com_A2 = new DecoratorA(cctCom2);
	com_B2 = new DecoratorB(com_A2);
	com_B2->Operation();

	printf("\n�������������\n");
	Component* cctCom3;
	Component* com_A3; 	Component* com_B3; Component* com_C3;
	cctCom3 = new ConcreteComponent();
	com_A3 = new DecoratorA(cctCom3);
	com_B3 = new DecoratorB(com_A3);
	com_C3 = new DecoratorC(com_B3);
	com_C3->Operation();

	printf("\n");
	std::cout << "**************************************************" << std::endl;
}
