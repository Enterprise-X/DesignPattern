#include "������ģʽ.h"
#include <string>
using namespace std;

#pragma region ��ƷHouse
//��Ʒ��House
class House
{
public:
	House() {}
	void SetFloor(string iFloor) {
		this->floor = iFloor;
	}
	void SetWall(string iWall) {
		this->wall = iWall;
	}
	void SetRoof(string iRoof) {
		this->roof = iRoof;
	}
	//��ӡHouse��Ϣ
	void PrintfHouseInfo() {
		printf("Floor:%s\t\n", this->floor.c_str());
		printf("Wall:%s\t\n", this->wall.c_str());
		printf("Roof:%s\t\n", this->roof.c_str());
	}
private:
	string floor;
	string wall;
	string roof;
};
#pragma endregion

#pragma region ������
//��������AbstractBuilder
class AbstractBuilder
{
public:
	AbstractBuilder() {
		house = new House();
	}
	//���󷽷���
	virtual void BuildFloor() = 0;
	virtual void BuildWall() = 0;
	virtual void BuildRoof() = 0;
	virtual House* GetHouse() = 0;

	House* house;
};

//���彨����ConcreteBuilderA
class ConcreteBuilderA :public AbstractBuilder
{
public:
	ConcreteBuilderA() {
		printf("ConcreteBuilderA\n");
	}
	//����ʵ�ַ���
	void BuildFloor() {
		this->house->SetFloor("Floor_A");
	}
	void BuildWall() {
		this->house->SetWall("Wall_A");
	}
	void BuildRoof() {
		this->house->SetRoof("Roof_A");
	}
	House* GetHouse() {
		return this->house;
	}
};

//���彨����ConcreteBuilderB
class ConcreteBuilderB :public AbstractBuilder
{
public:
	ConcreteBuilderB() {
		printf("ConcreteBuilderB\n");
	}
	//����ʵ�ַ���
	void BuildFloor() {
		this->house->SetFloor("Floor_B");
	}
	void BuildWall() {
		this->house->SetWall("Wall_B");
	}
	void BuildRoof() {
		this->house->SetRoof("Roof_B");
	}
	House* GetHouse() {
		return this->house;
	}
};
#pragma endregion

#pragma region ָ����
//ָ����Director
class Director
{
public:
	Director() {}
	//����ʵ�ַ���
	void SetBuilder(AbstractBuilder* iBuilder) {
		this->builder = iBuilder;
	}
	//��װ��װ���̣����ؽ�����
	House* Construct() {
		builder->BuildFloor();
		builder->BuildWall();
		builder->BuildRoof();
		return builder->GetHouse();
	}
private:
	AbstractBuilder* builder;
};
#pragma endregion
/*
House-������

AbstractBuilder-��������
|
������A-������B

Director-ָ����

new Director
Director��Set��ͬ������
Director�����й���

*/
void ������ģʽ::����()
{
	std::cout << "********************������ģʽ********************\n" << std::endl;

	//��������
	AbstractBuilder* builder;
	//ָ����
	Director* director = new Director();
	//��Ʒ��House
	House* house;

	//ָ�����彨����A
	builder = new ConcreteBuilderA();
	director->SetBuilder(builder);//���ý�����
	house = director->Construct();//ָ����ʹ�ý����߽��н���
	house->PrintfHouseInfo();
	printf("\r\n");
	//ָ�����彨����B
	builder = new ConcreteBuilderB();
	director->SetBuilder(builder);
	house = director->Construct();
	house->PrintfHouseInfo();

	std::cout << "\n************************************************" << std::endl;
}
