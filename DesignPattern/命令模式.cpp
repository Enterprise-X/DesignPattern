#include "����ģʽ.h"
#include <vector>

// ���������� Command
class Command
{
public:
	Command() {}
	// ��������ӿڣ���������
	virtual void Exec() = 0;
private:
	Command* m_Command;
};
// ���������
class CommandQueue
{
public:
	CommandQueue() {
	}
	void AddCommand(Command* cmd) {
		m_CommandQueue.push_back(cmd);
	}
	void ExecCmd() {
		for (int i = 0; i < m_CommandQueue.size(); i++)
		{
			m_CommandQueue[i]->Exec();
		}
	}
private:
	std::vector<Command*>m_CommandQueue;

};
// ������
class CmdUser
{
public:
	CmdUser() {}
	// ע�����������������
	void SetCommandQueue(CommandQueue* cmdQueue) {
		this->cmdQueue = cmdQueue;
	}
	// ��������
	void SendCmd() {
		printf("��ʼִ������:\n");
		cmdQueue->ExecCmd();
	}
private:
	CommandQueue* cmdQueue;
};

//�������ʵ����
// ���������� X_Command
class X_Command :public Command
{
public:
	X_Command() 
	{

	}
	// ʵ��execute()
	void Exec() {
		if (m_State) 
		{
			printf("ִ��X����:True\n");
			m_State = false;
		}
		else 
		{
			printf("ִ��X����:False\n");
			m_State = true;
		}
	}
private:
	bool m_State = false;
};

// ���������� Y_Command
class Y_Command :public Command
{
public:
	Y_Command() 
	{
	}
	// ʵ��execute()
	void Exec() 
	{
		printf("ִ��Y����:%d\n", m_nCount);
		m_nCount++;
		if (m_nCount > 3)
		{
			m_nCount = 0;
		}
	}
private:
	int m_nCount=0;
};


void ����ģʽ::����()
{
	std::cout << "********************����ģʽ********************" << std::endl;
	CmdUser cmdUser;
	CommandQueue* cmdQueue = new CommandQueue;
	X_Command *xCmd=new X_Command;
	Y_Command *yCmd = new Y_Command;

	cmdQueue->AddCommand(xCmd);
	cmdQueue->AddCommand(yCmd);
	cmdQueue->AddCommand(yCmd);
	cmdQueue->AddCommand(yCmd);
	cmdQueue->AddCommand(xCmd);

	cmdUser.SetCommandQueue(cmdQueue);
	cmdUser.SendCmd();

	std::cout << "************************************************" << std::endl;
}
