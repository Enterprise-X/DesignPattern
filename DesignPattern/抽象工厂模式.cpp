#include "���󹤳�ģʽ.h"

#pragma region Int�����Ʒ

//�����Ʒ��AbstractInt
class AbstractInt
{
public:
	AbstractInt() {}
	//���󷽷���
	virtual void Play() = 0;
	virtual ~AbstractInt() {}
};
//�����Ʒ��Int_A
class Int_A :public AbstractInt
{
public:
	Int_A() {
		Play();
	}
	//����ʵ�ַ���
	void Play() {
		printf("Play Int_A\n\n");
	}
};

//�����Ʒ��Int_B
class Int_B :public AbstractInt
{
public:
	Int_B() {
		Play();
	}
	//����ʵ�ַ���
	void Play() {
		printf("Play Int_B\n\n");
	}
};
#pragma endregion


#pragma region Double�����Ʒ
//�����Ʒ��AbstractDouble
class AbstractDouble
{
public:
	AbstractDouble() {}
	//���󷽷���
	virtual void Exec() = 0;
	virtual ~AbstractDouble() {}
};
//�����Ʒ��Double_A
class Double_A :public AbstractDouble
{
public:
	Double_A() {
		Exec();
	}
	//����ʵ�ַ���
	void Exec() {
		printf("Exec Double_A\n\n");
	}
};

//�����Ʒ��Double_B
class Double_B :public AbstractDouble
{
public:
	Double_B() {
		Exec();
	}
	//����ʵ�ַ���
	void Exec() {
		printf("Exec Double_B\n\n");
	}
};

#pragma endregion

#pragma region ���󹤳�
//���󹤳���
class AbstractFactory
{
public:
	virtual AbstractInt* GetInt() = 0;
	virtual AbstractDouble* GetDouble() = 0;
	virtual ~AbstractFactory() {}
};
//���幤����Factory_A
class Factory_A :public AbstractFactory
{
public:
	Factory_A() {
		printf("Factory_A\n\n");
	}
	AbstractInt* GetInt() {
		printf("Get IntA\n");
		return new Int_A();
	}
	AbstractDouble* GetDouble() {
		printf("Get DoubleA\n");
		return new Double_A();
	}
};

//���幤����Factory_B
class Factory_B :public AbstractFactory
{
public:
	Factory_B() {
		printf("Factory_B\n\n");
	}
	AbstractInt* GetInt() {
		printf("Get IntB\n");
		return new Int_B();
	}
	AbstractDouble* GetDouble() {
		printf("Get DoubleB\n");
		return new Double_B();
	}
};
#pragma endregion
/*
#�����ƷInt
|
��ƷIntA-��ƷIntB

#�����ƷDouble
|
��ƷDoubleA-��ƷDoubleB


#���󹤳�
|
����A-����B

#ʹ��
new ����A
����A��(����)����ƷIntA
����A��(����)����ƷDoubleA

new ����B
����B��(����)����ƷIntB
����B��(����)����ƷDoubleB

 */
void ���󹤳�ģʽ::����()
{
	std::cout << "********************���󹤳�ģʽ********************\n" << std::endl;

	//���幤�������Ͳ�Ʒ�����
	AbstractFactory* fac = nullptr;
	AbstractInt* _Int = nullptr;
	AbstractDouble* _Double = nullptr;

	//����һ��A���͵Ĺ���,ר������A���Ʒ
	fac = new Factory_A();
	_Int = fac->GetInt();//����Int���͵�A��Ʒ
	_Double = fac->GetDouble();//����Double���͵�A��Ʒ
	delete _Int;
	_Int = nullptr;
	delete _Double;
	_Double = nullptr;
	delete fac;
	fac = nullptr;

	//����һ��B���͵Ĺ���,ר������B���Ʒ
	fac = new Factory_B();
	_Int = fac->GetInt();//����Int���͵�B��Ʒ
	_Double = fac->GetDouble();//����Double���͵�B��Ʒ
	delete _Int;
	_Int = nullptr;
	delete _Double;
	_Double = nullptr;
	delete fac;
	fac = nullptr;

	std::cout << "\n************************************************" << std::endl;
}
