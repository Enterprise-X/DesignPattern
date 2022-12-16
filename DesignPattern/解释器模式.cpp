#include "������ģʽ.h"
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

// ������ʽ��
class Expression {
public:
	virtual ~Expression() { }
	virtual double interpreter(unordered_map<string, double> var) = 0;
};

// ����������
class VarExpression : public Expression {
public:
	VarExpression(string key) : m_key(key) { }

	double interpreter(unordered_map<string, double> var) override {
		return var[m_key];
	}

private:
	string m_key;
};

// ����������Ž�����
class SymbolExpression : public Expression {
public:
	SymbolExpression(Expression* left, Expression* right)
		: m_left(left), m_right(right) { }

	virtual double interpreter(unordered_map<string, double>) = 0;

protected:
	Expression* m_left;
	Expression* m_right;
};

// �ӷ�������
class AddExpression : public SymbolExpression {
public:
	AddExpression(Expression* left, Expression* right)
		: SymbolExpression(left, right) { }

	double interpreter(unordered_map<string, double> var) override {
		return m_left->interpreter(var) + m_right->interpreter(var);
	}
};

// ����������
class SubExpression : public SymbolExpression {
public:
	SubExpression(Expression* left, Expression* right)
		: SymbolExpression(left, right) { }

	double interpreter(unordered_map<string, double> var) override {
		return m_left->interpreter(var) - m_right->interpreter(var);
	}
};

// ��������װ��
class Calculator {
public:
	Calculator(vector<string> expStr) {
		stack<Expression*> stack;
		Expression* left;
		Expression* right;

		for (int i = 0; i < expStr.size(); ++i) {
			if (expStr[i] == "+") { // �ӷ�
				left = stack.top(), stack.pop();
				right = new VarExpression(expStr[++i]);
				stack.push(new AddExpression(left, right));
			}
			else if (expStr[i] == "-") { // ����
				left = stack.top(), stack.pop();
				right = new VarExpression(expStr[++i]);
				stack.push(new SubExpression(left, right));
			}
			else { // ����
				stack.push(new VarExpression(expStr[i]));
			}
		}

		this->m_expression = stack.top();
	}

	double run(unordered_map<string, double> var) {
		return this->m_expression->interpreter(var);
	}

private:
	// ������ʽ
	Expression* m_expression;
};

// �ͻ���

// ��ñ��ʽ
void getExpStr(vector<string>& expStr) {
	cout << "��������ʽ��" << endl;
	string str;
	int currentIndex = 0;
	getline(cin, str);
	string temp;
	int len = 0;
	for (int i = 0; i < str.size(); ++i) {
		switch (str[i]) {
		case '+':
			len = i - currentIndex;
			temp = str.substr(currentIndex, len);
			// �������Ŀո�
			temp.erase(remove(temp.begin(), temp.end(), ' '), temp.end());
			expStr.push_back(temp);
			expStr.push_back("+");
			currentIndex = i + 1;
			break;
		case '-':
			len = i - currentIndex;
			temp = str.substr(currentIndex, len);
			temp.erase(remove(temp.begin(), temp.end(), ' '), temp.end());
			expStr.push_back(temp);
			expStr.push_back("-");
			currentIndex = i + 1;
			break;
		}
	}
	temp = str.substr(currentIndex);
	temp.erase(remove(temp.begin(), temp.end(), ' '), temp.end());
	expStr.push_back(temp);
}

void getValue(unordered_map<string, double>& var, vector<string>& expStr) {
	for (const auto& key : expStr) {
		if (key != "+" && key != "-") {
			if (var.find(key) == var.end()) {
				cout << "������ " << key << " ��ֵ��" << endl;
				cin >> var[key];
			}
		}
	}
}

string vector_to_string(vector<string>& expStr) {
	string str;
	for (const auto& expstr : expStr) {
		str.append(expstr);
		str.append(" ");
	}
	str.pop_back();
	return str;
}

void ������ģʽ::����()
{
	std::cout << "********************������ģʽ********************" << std::endl;

	vector<string> expStr;
	unordered_map<string, double> var;
	getExpStr(expStr);
	getValue(var, expStr);

	Calculator* calcutor = new Calculator(expStr);

	cout << "��������" << vector_to_string(expStr)
		<< " = " << calcutor->run(var) << endl;

	std::cout << "************************************************" << std::endl;
}