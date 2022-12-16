#include "������ģʽ.h"
#include <string>
#include <list>

class Product;

#pragma region ������

// ���������
class Vistor {
public:
	void SetName(std::string name) {
		name_ = name;
	}

	virtual void Visit(Product* prd) = 0;
protected:
	std::string name_;
};


// �����������: Customer_1
class Vistor_1 : public Vistor {
public:
	void Visit(Product* prd);

};


// ����������ࣺ ����Ա
class User_1 : public Vistor {
public:
	void Visit(Product* prd);
	
};

#pragma endregion

#pragma region ��Ʒ
// ����Ԫ����
class Product {
public:
	virtual void Accept(Vistor* vistor) = 0;
	int m_type = 0;
};

// �����Ʒ��: A��
class Product_A : public Product {
public:
	Product_A()
	{
		m_type = 1;
	}
	void Accept(Vistor* vistor) override {
		vistor->Visit(this);
	}
};

// �����Ʒ��: B��
class Product_B : public Product {
public:
	Product_B()
	{
		m_type = 2;
	}
	void Accept(Vistor* vistor) override {
		vistor->Visit(this);
	}
};

// ��Ʒ/����������
class ProductContainer {
public:
	void Accept(Vistor* vistor) {
		for (auto prd : prd_list_) {
			prd->Accept(vistor);
		}
	}

	void AddProduct(Product* product) {
		prd_list_.push_back(product);
	}

	void RemoveProduct(Product* product) {
		prd_list_.remove(product);
	}

private:
	std::list<Product*> prd_list_;
};
#pragma endregion


void Vistor_1::Visit(Product* prd)
{
	std::cout << "Vistor_1:" << name_ << "���ʲ�Ʒ:" << prd->m_type << std::endl;
}

void User_1::Visit(Product* prd)
{
	std::cout << "User_1:" << name_ << "ʹ�ò�Ʒ:" << prd->m_type << std::endl;
}


void ������ģʽ::����()
{
	std::cout << "********************������ģʽ********************" << std::endl;


	Product_A prd_A;
	Product_B prd_B;
	ProductContainer prdContainer;

	prdContainer.AddProduct(&prd_B);
	prdContainer.AddProduct(&prd_A);

	Vistor_1 v1;
	v1.SetName("������1��");
	prdContainer.Accept(&v1);

	User_1 v2;
	v2.SetName("ʹ����1��");
	prdContainer.Accept(&v2);


	std::cout << "**************************************************" << std::endl;
}
