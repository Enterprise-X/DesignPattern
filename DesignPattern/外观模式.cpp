#include "���ģʽ.h"

//��ϵͳ��A
class SubSys_A
{
public:
	SubSys_A() {}
	void SelfCheckA() {
		printf("��������A�Լ졭��\n");
	}
};

//��ϵͳ��B
class SubSys_B
{
public:
	SubSys_B() {}
	void Exec() {
		printf("��������Bִ�С���\n");
	}
};

//��ϵͳ��Ӳ��
class SubSys_C
{
public:
	SubSys_C() {}
	void Read() {
		printf("��������C��ȡ����\n");
	}
};

//��ϵͳ������ϵͳ
class SubSys_D
{
public:
	SubSys_D() {}
	void Load() {
		printf("��������D���ء���\n");
	}
};

//�����
class Facade
{
public:
	Facade() {
		A = new SubSys_A();
		B = new SubSys_B();
		C = new SubSys_C();
		D = new SubSys_D();
	}
	void Run() {
		printf("������������\n");
		A->SelfCheckA();
		B->Exec();
		C->Read();
		D->Load();
		printf("�������!\n");
	}
private:
	SubSys_A* A;
	SubSys_B* B;
	SubSys_C* C;
	SubSys_D* D;
};

void ���ģʽ::����()
{
	std::cout << "********************���ģʽ********************" << std::endl;

	Facade* facade = new Facade();
	facade->Run();

	std::cout << "**************************************************" << std::endl;
}
