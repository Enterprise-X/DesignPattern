#pragma once
#include <iostream>

class CImpl;

class CPLMPL
{
public:
	CPLMPL();
	CPLMPL(std::string, double);
	~CPLMPL();
	/*˽�г�ԱΪָ�룬��ֹʹ��C++Ĭ��ǳ����*/
	CPLMPL(const CPLMPL&) = delete;
	CPLMPL& operator=(const CPLMPL&) = delete;
	//�ƶ���������
	CPLMPL(CPLMPL&&);
	CPLMPL& operator=(CPLMPL&&);

	void Display();

private:
	std::unique_ptr<CImpl> pCImpl;

};

