#pragma once
#include "设计模式基类.h"

class 装饰模式 :public 设计模式基类
{
public:
	void 运行() override;

};

/*

优点:
对于扩展一个类的新功能，装饰模式比继承更加灵活；
动态扩展一个对象的功能；
可以对一个对象进行多次装饰；
具体构件类和具体装饰类可以独立变化和扩展，符合开闭原则。

缺点:
装饰模式中会增加很多小的对象，对象的区别主要在于各种装饰的连接方式不同，而并不是职责不同，大量小对象的产生会占用较多的系统资源；
装饰模式比继承模式更灵活，但也更容易出错，更难于排错。

适用场景:
在不影响其他对象的情况下，给单个对象动态扩展职责；
不适宜采用继承的方式进行扩展的时候，可以考虑使用装饰模式。

*/