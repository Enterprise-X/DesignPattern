#include "��Ԫģʽ.h"
#include <map>
using namespace std;

//������Ԫ��
class FlyWeight
{
public:
	FlyWeight() {};
	virtual ~FlyWeight() {};
	//����������Ԫ�๲�еķ���
	virtual void Operation() = 0;

};

//������Ԫ��
class ConcreteFlyWeight : public FlyWeight
{
public:
	ConcreteFlyWeight() {};
	ConcreteFlyWeight(int nId) 
	{
		id = nId;
	}
	~ConcreteFlyWeight() {};
	//������Ԫ��ʵ�����ڳ�����Ԫ���������ķ���
	void Operation()
	{
		printf("I'm ConcreteFlyWeight Id=%d!\n",id);
	}
private:
	int id=0;
};



 //��Ԫ������
class FlyWeightFactory
{
public:
	FlyWeightFactory()
	{

	}
	~FlyWeightFactory()
	{
		for (auto it = m_flyWeights.begin(); it != m_flyWeights.end(); ++it)
			delete it->second;
	}
	//��������������������Ĳ���������Ԫ���е���Ԫ����
	FlyWeight* GetFlyWeight(int key)
	{
		for (auto it = m_flyWeights.begin(); it != m_flyWeights.end(); ++it)
		{
			if (it->first == key)
				return it->second;
		}

		FlyWeight* flyWeight = new ConcreteFlyWeight(key);
		m_flyWeights.insert(pair<int, FlyWeight*>(key, flyWeight));
		return flyWeight;

	}
	int GetFlyWeightCount()
	{
		return m_flyWeights.size();
	}
private: //������Ԫ�����ڴ洢���������Ԫ����
	map<int,FlyWeight*> m_flyWeights;//�ܶ�ʱ��Ϊ������Ч�ʣ�ʹ��hash��֮��Ľṹ������򵥵�ʹ��map��

};



void ��Ԫģʽ::����()
{
	std::cout << "********************��Ԫģʽ********************" << std::endl;
	FlyWeightFactory* factory = new FlyWeightFactory(); //ʵ������Ԫ������
	FlyWeight* flyWeight = factory->GetFlyWeight(0);//ͨ����Ԫ��������Ĺ�������������Ԫ����
	flyWeight->Operation();//������Ԫ����ķ���

    flyWeight = factory->GetFlyWeight(1);//ͨ����Ԫ��������Ĺ�������������Ԫ����
	flyWeight->Operation();//������Ԫ����ķ���

	std::cout << "************************************************" << std::endl;
}
