#include "�򵥹���ģʽ.h"
#include <string>
using namespace std;

#pragma region ��Ʒ��
//�����Ʒ��AbstractProduct
class AbstractProduct
{
public:
	AbstractProduct() {

	}
	//���󷽷���
	void PrintName() {};
	void Play() {};
};
//�����Ʒ��A
class ProductA :public AbstractProduct
{
public:
	ProductA() {
		PrintName();
		Play();
	}
	//����ʵ�ַ���
	void PrintName() {
		printf("Get ProductA\n");
	}
	void Play() {
		printf("Play ProductA\n");
	}
};

//�����Ʒ��B
class ProductB :public AbstractProduct
{
public:
	ProductB() {
		PrintName();
		Play();
	}
	//����ʵ�ַ���
	void PrintName() {
		printf("Get ProductB\n");
	}
	void Play() {
		printf("Play ProductB\n");
	}
};

//�����Ʒ��C
class ProductC :public AbstractProduct
{
public:
	ProductC() {
		PrintName();
		Play();
	}
	//����ʵ�ַ���
	void PrintName() {
		printf("Get ProductC\n");
	}
	void Play() {
		printf("Play ProductC\n");
	}
};
#pragma endregion


#pragma region ������
class Factory
{
public:
	AbstractProduct* getProduct(string productName)
	{
		AbstractProduct* pro = NULL;
		if (productName == "ProductA") {
			pro = new ProductA();
		}
		else if (productName == "ProductB") {
			pro = new ProductB();
		}
		else if (productName == "ProductC") {
			pro = new ProductC();
		}
		return pro;
	}
};
#pragma endregion

void �򵥹���ģʽ::����()
{
	std::cout << "********************�򵥹���ģʽ********************\n" << std::endl;

	//���幤�������
	Factory* fac = new Factory();
	AbstractProduct* product = NULL;

	product = fac->getProduct("ProductA");

	product = fac->getProduct("ProductB");

	product = fac->getProduct("ProductC");

	std::cout << "\n************************************************" << std::endl;
}
