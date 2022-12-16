#pragma once
#include "设计模式基类.h"

class 迭代器模式 :public 设计模式基类
{

public:
	void 运行() override;

};

/*

优点:
支持以不同的方式遍历一个聚合对象，在同一个聚合对象上可以定义多个遍历方式。
简化了聚合类，使得聚合类的职责更加单一；
迭代器模式中引入抽象层，易于增加新的迭代器类，便于扩展，符合开闭原则。

缺点:
将聚合类中存储对象和管理对象的职责分离，增加新的聚合类时同样需要考虑增加对应的新的迭代器类，类的个数成对增加，不利于系统管理和维护；
设计难度较大，需要充分考虑将来系统的扩展。

适用环境:
以下场景可以考虑使用迭代器模式：
访问一个聚合对象而无需暴露它的内部结构；
需要为一个聚合对象提供多种遍历方法。

*/