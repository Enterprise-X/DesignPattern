#include "���ģʽ������.h"
#include <iostream>

#include "����ģʽ.h"
#include "�򵥹���ģʽ.h"
#include "��������ģʽ.h"
#include "���󹤳�ģʽ.h"
#include "ԭ��ģʽ.h"
#include "������ģʽ.h"

#include "������ģʽ.h"
#include "�Ž���ģʽ.h"
#include "���ģʽ.h"
#include "װ��ģʽ.h"
#include "���ģʽ.h"
#include "��Ԫģʽ.h"
#include "����ģʽ.h"

#include "ְ����ģʽ.h"
#include "����ģʽ.h"
#include "������ģʽ.h"
#include "������ģʽ.h"
#include "�н���ģʽ.h"
#include "����¼ģʽ.h"
#include "�۲���ģʽ.h"
#include "״̬ģʽ.h"
#include "����ģʽ.h"
#include "ģ�巽��ģʽ.h"
#include "������ģʽ.h"

#include "PIMPLģʽ.h"

void ���ģʽ������::����(ö��_���ģʽ ���ģʽ)
{
	���ģʽ����* ģʽ=NULL;
	switch (���ģʽ)
	{

/*������*/
	case ����:
	{
		ģʽ = new ����ģʽ;
	}
		break;
	case �򵥹���:
	{
		ģʽ = new �򵥹���ģʽ;
	}
		break;
	case ��������:
	{
		ģʽ = new ��������ģʽ;
	}
	break;
	case ���󹤳�:
	{
		ģʽ = new ���󹤳�ģʽ;
	}
		break;
	case ԭ��:
	{
		ģʽ =new ԭ��ģʽ;
	}
		break;
	case ������:
	{
		ģʽ =new ������ģʽ;
	}
		break;
/*�ṹ��*/
	case ������:
	{
		ģʽ = new ������ģʽ;
	}
		break;
	case �Ž���:
	{
		ģʽ = new �Ž���ģʽ;
	}
		break;
	case ���:
	{
		ģʽ = new ���ģʽ;
	}
		break;
	case װ��:
	{
		ģʽ = new װ��ģʽ;
	}
		break;
	case ���:
	{
		ģʽ = new	���ģʽ;
	}
		break;
	case ��Ԫ:
	{
		ģʽ = new ��Ԫģʽ;
	}
		break;
	case ����:
	{
		ģʽ = new ����ģʽ;
	}
	break;
/*��Ϊ��*/
	case ְ����:
	{
		ģʽ = new ְ����ģʽ;
	}
		break;
	case ����:
	{
		ģʽ = new ����ģʽ;
	}
	break;
	case ������:
	{
		ģʽ = new ������ģʽ;
	}
		break;
	case ������:
	{
		ģʽ = new ������ģʽ;
	}
		break;
	case �н���:
	{
		ģʽ = new �н���ģʽ;
	}
		break;
	case ����¼:
	{
		ģʽ = new ����¼ģʽ;
	}
		break;
	case �۲���:
	{
		ģʽ = new �۲���ģʽ;
	}
		break;
	case ״̬:
	{
		ģʽ = new ״̬ģʽ;
	}
		break;
	case ����:
	{
		ģʽ = new ����ģʽ;
	}
		break;
	case ģ�巽��:
	{
		ģʽ = new ģ�巽��ģʽ;
	}
		break;
	case ������:
	{
		ģʽ = new ������ģʽ;
	}
		break;
/*������*/
	case PIMPL:
	{
		ģʽ = new PIMPLģʽ;
	}
		break;
	default:
	{
		return;
	}
		break;
	}
	if (ģʽ)
	{
		ģʽ->����();
		delete ģʽ;
		ģʽ = NULL;
	}
}
