#include "����ģʽ.h"
#include <string>
#include <windows.h>

using namespace std;

// ���������ɫ
class Subject
{
public:
	Subject() {}
	virtual void Method() = 0;
};
// ��ʵ�����ɫ
class RealSubject :public Subject
{
public:
	RealSubject() {}
	void Method() {
		printf("����ҵ�񷽷�\n");
		Sleep(1000);
	}
};
// Log��
class Log
{
public:
	Log() {}
	string GetTime() 
	{
		time_t t = time(NULL);
		char ch[64] = { 0 };
		//��-��-�� ʱ:��:��
		strftime(ch, sizeof(ch) - 1, "%Y-%m-%d %H:%M:%S", localtime(&t));
		return ch;
	}
};

// ������
class Proxy :public Subject
{
public:
	Proxy() 
	{
		realSubject = new RealSubject();
		log = new Log();
	}
	void PreCallMethod() {
		printf("����method()��ʼ���ã�����ʱ��Ϊ%s\n", log->GetTime().c_str());
	}
	void Method() {
		PreCallMethod();
		realSubject->Method();
		PostCallMethod();
	}
	void PostCallMethod() {
		printf("����method()���õ��óɹ�!�������Ϊ%s\n", log->GetTime().c_str());
	}
private:
	RealSubject* realSubject;
	Log* log;
};

/*
Subject��������
|
RealSubject��ʵ����----Proxy������

Proxy.Method()��Proxy.RealSubject.Method()

*/
void ����ģʽ::����()
{
	std::cout << "********************����ģʽ********************" << std::endl;
	Subject* subject;
	subject = new Proxy();
	subject->Method();

	printf("\n");
	std::cout << "**************************************************" << std::endl;
}
