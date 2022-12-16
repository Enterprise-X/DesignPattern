#include "������ģʽ.h"


//��������DxfParser
class DataParser
{
public:
	DataParser() {}
	void Parse() {
		printf("��������\n");
	}
};

//��������PathPlanner
class DataExecer
{
public:
	DataExecer() {}
	void Exec() {
		printf("ִ������\n");
	}
};

//Ŀ�������
class Controller
{
public:
	Controller() {}
	virtual void PathPlanning() = 0;

};
//��������Adapter
class Adapter :public Controller
{
public:
	Adapter() {
		dataParser = new DataParser();
		dataExecer = new DataExecer();
	}
	void PathPlanning() {
		printf("��ʼ��������\n");
		dataParser->Parse();
		dataExecer->Exec();
	}
private:
	DataParser* dataParser;
	DataExecer* dataExecer;
};
/*
Controller
|
Adapter

Adapter.Method()��DxfParser.Method1()&&PathPlanner.Method2()

*/

void ������ģʽ::����()
{
	std::cout << "********************������ģʽ********************" << std::endl;
	Controller* controller = new Adapter();
	controller->PathPlanning();
	std::cout << "**************************************************" << std::endl;
}
