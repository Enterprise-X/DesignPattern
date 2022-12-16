#include "����ģʽ.h"

#include <mutex>


#pragma region ������������
namespace ��������
{
class ������������
{
public:
	// ��ȡ��ʵ������
	static ������������*& GetInstance();

	//�ͷŵ�ʵ���������˳�ʱ����
	static void DeleteInstance();

	// ��ӡʵ����ַ
	void Print();

private:
	// ���乹���������Ϊ˽�е�, ��ֹ�ⲿ���������
	������������();
	~������������();

	// ���俽������͸�ֵ�����Ϊ˽�к���, ��ֹ�ⲿ�����͸�ֵ
	������������(const ������������& signal);
	const ������������& operator=(const ������������& signal);

private:
	// Ψһ��ʵ������ָ��
	static ������������* m_SingleInstance;
	static std::mutex m_Mutex;
};

//��ʼ����̬��Ա����
������������* ������������::m_SingleInstance = nullptr;
std::mutex ������������::m_Mutex;

// ע�⣺���ص���ָ�������
������������*& ������������::GetInstance()
{

	//  ����ʹ�������� if �ж����ļ�����Ϊ˫�������ô��ǣ�ֻ���ж�ָ��Ϊ�յ�ʱ��ż�����
	//  ����ÿ�ε��� GetInstance�ķ��������������Ŀ����Ͼ������е��ġ�
	if (m_SingleInstance == nullptr)
	{
		std::unique_lock<std::mutex> lock(m_Mutex); // ����
		if (m_SingleInstance == nullptr)
		{
			m_SingleInstance = new (std::nothrow) ������������();
		}
	}

	return m_SingleInstance;
}

void ������������::DeleteInstance()
{
	std::unique_lock<std::mutex> lock(m_Mutex); // ����
	if (m_SingleInstance)
	{
		delete m_SingleInstance;
		m_SingleInstance = nullptr;
	}
}

void ������������::Print()
{
	std::cout << "������������_�ҵ�ʵ���ڴ��ַ��:" << this << std::endl;
}

������������::������������()
{
	std::cout << "������������_����" << std::endl;
}

������������::~������������()
{
	std::cout << "������������_����" << std::endl;
}

}
#pragma endregion

#pragma region ��̬�ֲ�������������
namespace ��̬�ֲ���������
{
	class ��̬�ֲ�������������
	{

	public:
		// ��ȡ��ʵ������
		static ��̬�ֲ�������������& GetInstance();

		// ��ӡʵ����ַ
		void Print();

	private:
		// ��ֹ�ⲿ����
		��̬�ֲ�������������();

		// ��ֹ�ⲿ����
		~��̬�ֲ�������������();

		// ��ֹ�ⲿ��������
		��̬�ֲ�������������(const ��̬�ֲ�������������& signal) {};

		// ��ֹ�ⲿ��ֵ����
		const ��̬�ֲ�������������& operator=(const ��̬�ֲ�������������& signal) {};
	};
	��̬�ֲ�������������& ��̬�ֲ�������������::GetInstance()
	{
		/**
		 * �ֲ���̬���Եķ�ʽʵ�ֵ�ʵ����
		 * ��̬�ֲ�����ֻ�ڵ�ǰ��������Ч�����������޷����ʡ�
		 * ��̬�ֲ�����ֻ�ڵ�һ�α����õ�ʱ���ʼ����Ҳ�洢�ھ�̬�洢�����������ڴӵ�һ�α���ʼ�������������ֹ��
		 */
		static ��̬�ֲ������������� signal;
		return signal;
	}

	void ��̬�ֲ�������������::Print()
	{
		std::cout << "��̬�ֲ�������������_�ҵ�ʵ���ڴ��ַ��:" << this << std::endl;
	}

	��̬�ֲ�������������::��̬�ֲ�������������()
	{
		std::cout << "��̬�ֲ�������������_����" << std::endl;
	}

	��̬�ֲ�������������::~��̬�ֲ�������������()
	{
		std::cout << "��̬�ֲ�������������_����" << std::endl;
	}


}
#pragma endregion

#pragma region ��������
namespace ����
{
	class ��������
	{
	public:
		// ��ȡ��ʵ��
		static ��������* GetInstance();

		// �ͷŵ�ʵ���������˳�ʱ����
		static void DeleteInstance();

		// ��ӡʵ����ַ
		void Print();

	private:
		// ���乹���������Ϊ˽�е�, ��ֹ�ⲿ���������
		��������();
		~��������();

		// ���俽������͸�ֵ�����Ϊ˽�к���, ��ֹ�ⲿ�����͸�ֵ
		��������(const ��������& signal);
		const ��������& operator=(const ��������& signal);

	private:
		// Ψһ��ʵ������ָ��
		static ��������* g_pSingleton;
	};
	// ����һ���оͳ�ʼ������ʵ�� ��������̰߳�ȫ
	��������* ��������::g_pSingleton = new (std::nothrow) ��������();

	��������* ��������::GetInstance()
	{
		return g_pSingleton;
	}

	void ��������::DeleteInstance()
	{
		if (g_pSingleton)
		{
			delete g_pSingleton;
			g_pSingleton = nullptr;
		}
	}

	void ��������::Print()
	{
		std::cout << "��������_�ҵ�ʵ���ڴ��ַ��:" << this << std::endl;
	}

	��������::��������()
	{
		//xie.y:�˴�����ע�� ��ֹ�ǵ���ģʽ�½��� ��ʾ std::cout << "��������_����" << std::endl;
	}

	��������::~��������()
	{
		std::cout << "��������_����" << std::endl;
	}


}
#pragma endregion

#pragma region ����ָ�뵥��
namespace ����ָ��
{
	class ����ָ�뵥�� {

	public:

		static std::shared_ptr<����ָ�뵥��> GetInstance();

		void Print()
		{
			std::cout << "����ָ�뵥��_�ҵ�ʵ���ڴ��ַ��:" << this << std::endl;
		}

		~����ָ�뵥��() {
			std::cout << "����ָ�뵥��_����" << std::endl;
		}

	private:

		����ָ�뵥��() {
			std::cout << "����ָ�뵥��_����" << std::endl;
		}
	};

	static std::shared_ptr<����ָ�뵥��> singleton = nullptr;
	static std::mutex singletonMutex;

	std::shared_ptr<����ָ�뵥��> ����ָ�뵥��::GetInstance() {
		if (singleton == nullptr) {
			std::unique_lock<std::mutex> lock(singletonMutex);
			if (singleton == nullptr) {
				auto temp = std::shared_ptr<����ָ�뵥��>(new ����ָ�뵥��());
				singleton = temp;
			}
		}
		return singleton;
	}
}
#pragma endregion

#pragma region Call_once����
namespace Call_once
{
	class Call_once���� {
	public:
		static std::shared_ptr<Call_once����> GetSingleton();

		void Print() {
			std::cout << "Call_once����_�ҵ�ʵ���ڴ��ַ��:" << this << std::endl;
		}

		~Call_once����() {
			std::cout << "Call_once����_����" << std::endl;
		}

	private:
		Call_once����() {
			std::cout << "Call_once����_����" << std::endl;
		}
	};

	static std::shared_ptr<Call_once����> singleton = nullptr;
	static std::once_flag singletonFlag;

	std::shared_ptr<Call_once����> Call_once����::GetSingleton() {
		std::call_once(singletonFlag, [&] {
			singleton = std::shared_ptr<Call_once����>(new Call_once����());
			});
		return singleton;
	}

}
#pragma endregion


void ����ģʽ::����()
{
	std::cout << "********************����ģʽ********************\n" << std::endl;

	{
		std::cout << "**********������������(�Ƽ�)**********" << std::endl;
		std::cout << "�Ƽ�ʹ��,���̰߳�ȫ" << std::endl;
		auto instance = ��������::������������::GetInstance();
		instance->Print();
		instance->DeleteInstance();
		std::cout << "******************************\n" << std::endl;
	}


	{
		std::cout << "**********��̬�ֲ�������������**********" << std::endl;
		std::cout << "C++11�̰߳�ȫ" << std::endl;
		��̬�ֲ���������::��̬�ֲ�������������::GetInstance();
		��̬�ֲ���������::��̬�ֲ�������������::GetInstance().Print();
		std::cout << "******************************\n" << std::endl;
	}


	{
		std::cout << "**********��������**********" << std::endl;
		std::cout << "���������̰߳�ȫ" << std::endl;
		auto instance = ����::��������::GetInstance();
		instance->Print();
		instance->DeleteInstance();
		std::cout << "******************************\n" << std::endl;
	}


	{
		std::cout << "**********����ָ�뵥��**********" << std::endl;
		std::cout << "���Ƽ�ʹ��,����ָ�붼���̰߳�ȫ" << std::endl;
		auto instance = ����ָ��::����ָ�뵥��::GetInstance();
		instance->Print();
		std::cout << "******************************\n" << std::endl;
	}


	{
		std::cout << "**********Call_once����**********" << std::endl;
		std::cout << "�����õ�,C++11�̰߳�ȫ" << std::endl;
		auto instance = Call_once::Call_once����::GetSingleton();
		instance->Print();
		std::cout << "******************************\n" << std::endl;
	}

	std::cout << "************************************************" << std::endl;
}
