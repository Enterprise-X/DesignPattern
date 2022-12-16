#include "����¼ģʽ.h"
#include <string>
#include <vector>
///ʹ�ñ���¼ģʽ����һ���汾������

using namespace std;

//����¼
class Memento
{
public:
	Memento() {}
	Memento(int iVersion, string iDate, string iLabel) {
		version = iVersion;
		date = iDate;
		label = iLabel;
	}
	void setVersion(int iVersion) {
		version = iVersion;
	}
	int getVersion() {
		return version;
	}
	void setLabel(string iLabel) {
		label = iLabel;
	}
	string getLabel() {
		return label;
	}
	void setDate(string iDate) {
		date = iDate;
	}
	string getDate() {
		return date;
	}
private:
	int version;
	string date;
	string label;
};


// ԭ������CodeVersion
class CodeVersion
{
public:
	CodeVersion() {
		version = 0;
		date = "1900-01-01";
		label = "none";
	}
	CodeVersion(int iVersion, string iDate, string iLabel) {
		version = iVersion;
		date = iDate;
		label = iLabel;
	}
	// �������
	Memento* save() {
		return new Memento(this->version, this->date, this->label);
	}
	// ���˰汾
	void restore(Memento* memento) {
		setVersion(memento->getVersion());
		setDate(memento->getDate());
		setLabel(memento->getLabel());
	}
	void setVersion(int iVersion) {
		version = iVersion;
	}
	int getVersion() {
		return version;
	}
	void setLabel(string iLabel) {
		label = iLabel;
	}
	string getLabel() {
		return label;
	}
	void setDate(string iDate) {
		date = iDate;
	}
	string getDate() {
		return date;
	}
private:
	// ����汾
	int version;
	// �����ύ����
	string date;
	// �����ǩ
	string label;
};


// ������
class CodeManager
{
public:
	CodeManager() {}
	void commit(Memento* m) {
		printf("�ύ���汾-%d, ����-%s, ��ǩ-%s\n", m->getVersion(), m->getDate().c_str(), m->getLabel().c_str());
		mementoList.push_back(m);
	}
	// �л���ָ���İ汾�������˵�ָ���汾
	Memento* switchToPointedVersion(int index) {
		mementoList.erase(mementoList.begin() + mementoList.size() - index, mementoList.end());
		return mementoList[mementoList.size() - 1];
	}
	// ��ӡ��ʷ�汾
	void codeLog() {
		for (int i = 0; i < mementoList.size(); i++) {
			printf("[%d]���汾-%d, ����-%s, ��ǩ-%s\n", i, mementoList[i]->getVersion(),
				mementoList[i]->getDate().c_str(), mementoList[i]->getLabel().c_str());
		}
	}
private:
	vector<Memento*> mementoList;
};

void ����¼ģʽ::����()
{
	std::cout << "********************����¼ģʽ********************" << std::endl;
	CodeManager* codeMgr = new CodeManager();

	CodeVersion* codeVer = new CodeVersion(1001, "2019-11-03", "Initial version");

	// �ύ��ʼ�汾
	printf("�ύ��ʼ�汾:\n");
	codeMgr->commit(codeVer->save());

	// �޸�һ���汾����������־����
	printf("\n�ύһ���汾����������־����:\n");
	codeVer->setVersion(1002);
	codeVer->setDate("2019-11-04");
	codeVer->setLabel("Add log funciton");
	codeMgr->commit(codeVer->save());

	// �޸�һ���汾��������QtͼƬ�����
	printf("\n�ύһ���汾��������QtͼƬ�����:\n");
	codeVer->setVersion(1003);
	codeVer->setDate("2019-11-05");
	codeVer->setLabel("Add Qt Image Browser");
	codeMgr->commit(codeVer->save());

	// �鿴�ύ��ʷ
	printf("\n�鿴�ύ��ʷ\n");
	codeMgr->codeLog();

	// ���˵���һ���汾
	printf("\n���˵���һ���汾\n");
	codeVer->restore(codeMgr->switchToPointedVersion(1));

	// �鿴�ύ��ʷ
	printf("\n�鿴�ύ��ʷ\n");
	codeMgr->codeLog();

	std::cout << "**************************************************" << std::endl;
}
