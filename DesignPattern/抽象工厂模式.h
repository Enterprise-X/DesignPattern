#pragma once
#include "设计模式基类.h"

class 抽象工厂模式 :public 设计模式基类
{
public:
	void 运行() override;

};
/*

优点:
工厂方法用于创建客户所需产品，同时向客户隐藏某个具体产品类将被实例化的细节，用户只需关心所需产品对应的工厂；
新加入产品系列时，无需修改原有系统，增强了系统的可扩展性，符合开闭原则。

缺点:
在已有产品系列中添加新产品时需要修改抽象层代码，对原有系统改动较大，违背开闭原则

适用环境:
一系列/一族产品需要被同时使用时，适合使用抽象工厂模式；
产品结构稳定，设计完成之后不会向系统中新增或剔除某个产品

*/