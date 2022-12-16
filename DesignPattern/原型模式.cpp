#include "ԭ��ģʽ.h"

//WorkModel��
class WorkModel
{
public:
	char* modelName;
	void SetWorkModelName(char* iName) {
		this->modelName = iName;
	}
};

//����ԭ����PrototypeWork
class PrototypeWork
{
public:
	PrototypeWork() {}
	//���п�¡
	virtual PrototypeWork* Clone() = 0;

private:

};

//����ԭ����ConcreteWork
class ConcreteWork :public PrototypeWork
{
public:
	ConcreteWork() {}
	ConcreteWork(char* iName, int iIdNum, char* modelName) {
		this->name = iName;
		this->idNum = iIdNum;
		this->workModel = new WorkModel();
		this->workModel->SetWorkModelName(modelName);
	}

	ConcreteWork* Clone() {
		ConcreteWork* work = new ConcreteWork();
		work->SetName(this->name);
		work->SetIdNum(this->idNum);
		work->workModel = this->workModel;
		return work;
	}

	void SetName(char* iName) {
		this->name = iName;
	}
	void SetIdNum(int iIdNum) {
		this->idNum = iIdNum;
	}
	void setModel(WorkModel* iWorkModel) {
		this->workModel = iWorkModel;
	}
	//��ӡwork��Ϣ
	void PrintWorkInfo() {
		printf("name:%s\t\n", this->name);
		printf("idNum:%d\t\n", this->idNum);
		printf("modelName:%s\t\n", this->workModel->modelName);
	}
private:
	char* name;
	int idNum;
	WorkModel* workModel;
};

void ԭ��ģʽ::����()
{
	std::cout << "********************ԭ��ģʽ********************\n" << std::endl;
	
	{ //ǳ����:��ʹ��Clone�ӿ�
		std::cout << "*******ǳ����*******\n" << std::endl;


		ConcreteWork* XWork = new ConcreteWork("X", 1001, "X_Model");
		printf("\nX����ҵ��\n");
		XWork->PrintWorkInfo();

		printf("\nYֱ�Ӹ�����ҵ����\n");
		ConcreteWork* YWork = XWork;
		printf("\nY����ҵ��\n");
		YWork->PrintWorkInfo();

		//��������Ҫ�޸ĸ����ֺ�ID
		printf("\nY�������޸����ֺ�ID������������\n");
		YWork->SetName("Y");
		YWork->SetIdNum(1002);

		WorkModel* YModel = new WorkModel();
		YModel->SetWorkModelName("Y_Model");
		YWork->setModel(YModel);

		//������Ƿ�Ķ���
		printf("\nX����ҵ��\n");
		XWork->PrintWorkInfo();
		printf("\nY����ҵ��\n");
		YWork->PrintWorkInfo();


		std::cout << "*****************\n" << std::endl;
	}
	{ //���:ʹ�ÿ�¡�ӿ�
		std::cout << "*******���*******\n" << std::endl;


		ConcreteWork* XWork = new ConcreteWork("X", 1001, "X_Model");
		printf("\nX����ҵ��\n");
		XWork->PrintWorkInfo();
		ConcreteWork* YWork = XWork->Clone();//#�ص�
		printf("\nY����ҵ��\n");
		YWork->PrintWorkInfo();
		//��������Ҫ�޸ĸ����ֺ�ID
		printf("\nY�������޸����ֺ�ID������������\n");
		YWork->SetName("Y");
		YWork->SetIdNum(1002);
		WorkModel* YModel = new WorkModel();
		YModel->SetWorkModelName("Y_Model");
		YWork->setModel(YModel);

		//������Ƿ�Ķ���
		printf("\nX����ҵ��\n");
		XWork->PrintWorkInfo();
		printf("\nY����ҵ��\n");
		YWork->PrintWorkInfo();


		std::cout << "*****************\n" << std::endl;
	}
	std::cout << "************************************************" << std::endl;
}
