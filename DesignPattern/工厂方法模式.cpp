#include "��������ģʽ.h"

#pragma region ��Ʒ��
//�����Ʒ��AbstractProduct
class AbstractIntProduct
{
public:
	AbstractIntProduct() {

	}
	virtual ~AbstractIntProduct() {}
	//���󷽷���
	virtual void PrintName() = 0;
	virtual void Play()  = 0;
};
//�����Ʒ��IntA
class IntA :public AbstractIntProduct
{
public:
	IntA() {
		PrintName();
		Play();
	}
	//����ʵ�ַ���
	void PrintName() {
		printf("Get IntA\n");
	}
	void Play() {
		printf("Play IntA\n\n");
	}
};

//�����Ʒ��IntB
class IntB :public AbstractIntProduct
{
public:
	IntB() {
		PrintName();
		Play();
	}
	//����ʵ�ַ���
	void PrintName() {
		printf("Get IntB\n");
	}
	void Play() {
		printf("Play IntB\n\n");
	}
};

//�����Ʒ��IntC
class IntC :public AbstractIntProduct
{
public:
	IntC() {
		PrintName();
		Play();
	}
	//����ʵ�ַ���
	void PrintName() {
		printf("Get IntC\n");
	}
	void Play() {
		printf("Play IntC\n\n");
	}
};
#pragma endregion

#pragma region ������
//���󹤳���
class AbstractFactory
{
public:
	virtual AbstractIntProduct* GetProduct() = 0;
	virtual ~AbstractFactory() {}
};

// ���幤����Int_A
class Factory_IntA :public AbstractFactory
{
public:
	Factory_IntA() {
		printf("Factory_IntA\n");
	}
	AbstractIntProduct* GetProduct() {
		return new IntA();
	}
};

//���幤����Int_B
class Factory_IntB :public AbstractFactory
{
public:
	Factory_IntB() {
		printf("Factory_IntB\n");
	}
	AbstractIntProduct* GetProduct() {
		return new IntB();
	}
};

//���幤����Int_C
class Factory_IntC :public AbstractFactory
{
public:
	Factory_IntC() {
		printf("Factory_IntC\n");
	}
	AbstractIntProduct* GetProduct() {
		return new IntC();
	}
};

#pragma endregion

/*

#�����Ʒ
|
��ƷA-��ƷB-��ƷC


#���󹤳�
|
����A-����B-����C

#ʹ��
new ����A
����A��(����)����ƷA

*/
void ��������ģʽ::����()
{
	std::cout << "********************��������ģʽ********************\n" << std::endl;

	//���幤�������Ͳ�Ʒ�����
	AbstractFactory* fac = nullptr;
	AbstractIntProduct* product = nullptr;

	fac = new Factory_IntA();
	product = fac->GetProduct();
	delete fac;
	fac = nullptr;
	delete product;
	product = nullptr;

	fac = new Factory_IntB();
	product = fac->GetProduct();
	delete fac;
	fac = nullptr;
	delete product;
	product = nullptr;

	fac = new Factory_IntC();
	product = fac->GetProduct();
	delete fac;
	fac = nullptr;
	delete product;
	product = nullptr;

	std::cout << "\n************************************************" << std::endl;
}
