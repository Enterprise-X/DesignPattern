#pragma once
#include "设计模式基类.h"

class 简单工厂模式 :public 设计模式基类
{
public:
	void 运行() override;

};


/*

优点:
工厂类提供创建具体产品的方法，并包含一定判断逻辑，客户不必参与产品的创建过程；
客户只需要知道对应产品的参数即可，参数一般简单好记，如数字、字符或者字符串等。

缺点:
违背了开闭原则（对扩展开放，对修改关闭），即在扩展功能时修改了既有的代码；
另一方面，简单工厂模式所有的判断逻辑都在工厂类中实现，一旦工厂类设计故障，则整个系统都受之影响！

*/