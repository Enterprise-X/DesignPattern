#include "ְ����ģʽ.h"
#include <string>
using namespace std;

#pragma region ����
// ������
class SwitchState
{
public:
	SwitchState() {}
	SwitchState(int iId, string iName, double iAuthority) {
		id = iId;
		name = iName;
		authority = iAuthority;
	}
	double GetAuthority() {
		return this->authority;
	}
	void Print() {
		printf("\nID:\t%d\n", id);
		printf("Name:\t%s\n", name.c_str());
		printf("Authority:\t%f\n", authority);
	}
private:
	int id;
	string name;
	double authority;//����Ȩ��
};
#pragma endregion

#pragma region ������
// ��������
class Approver
{
public:
	Approver() {}
	Approver(string iName) {
		SetName(iName);
	}
	// ����ϼ�
	void SetSuperior(Approver* iSuperior) {
		this->superior = iSuperior;
	}
	// ��������
	virtual void HandleRequest(SwitchState*) = 0;

	string GetName() {
		return name;
	}
	void SetName(string iName) {
		name = iName;
	}
protected:
	Approver* superior;
private:
	string name;
};

// ���崦���ߣ�Level_1(Ȩ��1)
class Level_1 :public Approver
{
public:
	Level_1() {}
	Level_1(string iName) {
		SetName(iName);
	}
	// ��������
	void HandleRequest(SwitchState* req) {
		if (req->GetAuthority() < 1) {
			printf("Level_1 %s �����˸�����������Ϣ:", this->GetName().c_str());
			req->Print();
		}
		else {
			printf("Level_1��Ȩ����ת���ϼ�����\n");
			this->superior->HandleRequest(req);
		}
	}
};

// ���崦���ߣ�Level_2(Ȩ��2)
class Level_2 :public Approver
{
public:
	Level_2() {}
	Level_2(string iName) {
		SetName(iName);
	}
	// ��������
	void HandleRequest(SwitchState* req) {
		if (req->GetAuthority() >= 1 && req->GetAuthority() < 2) {
			printf("Level_2 %s �����˸�����������Ϣ:", this->GetName().c_str());
			req->Print();
		}
		else {
			printf("Level_2��Ȩ����ת���ϼ�����\n");
			this->superior->HandleRequest(req);
		}
	}
};
// ���崦���ߣ�Admin(Ȩ��<=3)
class Admin :public Approver
{
public:
	Admin() {}
	Admin(string iName) {
		SetName(iName);
	}
	// ��������
	void HandleRequest(SwitchState* req) {
		if (req->GetAuthority() < 3) {
			printf("Admin %s �����˸�����������Ϣ:", this->GetName().c_str());
			req->Print();
		}
		else {
			printf("Admin��Ȩ����ת���ϼ�����\n");
			this->superior->HandleRequest(req);
		}
	}
};

// ���崦���ߣ�SuperAdmin(����Ȩ��)
class SuperAdmin :public Approver
{
public:
	SuperAdmin() {}
	SuperAdmin(string iName) {
		SetName(iName);
	}
	// ��������
	void HandleRequest(SwitchState* req) 
	{
		printf("SuperAdmin %s �����˸�����������Ϣ:", this->GetName().c_str());
		req->Print();
	}
};
#pragma endregion

void ְ����ģʽ::����()
{
	std::cout << "********************ְ����ģʽ********************" << std::endl;
	// �������ߣ��û����鳤������Ա������
	Approver* user, * teamLeader, * admin, * superAdmin;
	user = new Level_1("�û�");
	teamLeader = new Level_2("�鳤");
	admin = new Admin("����Ա");
	superAdmin = new SuperAdmin("����");

	//�����ϼ�
	user->SetSuperior(teamLeader);
	teamLeader->SetSuperior(admin);
	admin->SetSuperior(superAdmin);

	// ��������
	SwitchState* req1 = new SwitchState(1, "����_0.5", 0.5);
	SwitchState* req2 = new SwitchState(2, "����_1.7", 1.7);
	SwitchState* req3 = new SwitchState(3, "����_2.6", 2.6);
	SwitchState* req4 = new SwitchState(4, "����_3.3", 3.3);

	// ȫ���Ƚ����û�����
	user->HandleRequest(req1); printf("\n");
	user->HandleRequest(req2); printf("\n");
	user->HandleRequest(req3); printf("\n");
	user->HandleRequest(req4);

	std::cout << "************************************************" << std::endl;
}
