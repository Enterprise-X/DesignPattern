#pragma once
#include "设计模式基类.h"

class 工厂方法模式 :public 设计模式基类
{
public:
	void 运行() override;

};

/*

如果用户想使用IntA，只需要增加一个IntA工厂（Facory_IntA），
然后在客户端代码中修改具体工厂类的类名，而原有的类的代码无需修改。
由此可看到，相较简单工厂模式，工厂方法模式更加符合开闭原则。工厂方法是使用频率最高的设计模式之一，是很多开源框架和API类库的核心模式。

优点:
工厂方法用于创建客户所需产品，同时向客户隐藏某个具体产品类将被实例化的细节，用户只需关心所需产品对应的工厂；
工厂自主决定创建何种产品，并且创建过程封装在具体工厂对象内部，多态性设计是工厂方法模式的关键；
新加入产品时，无需修改原有代码，增强了系统的可扩展性，符合开闭原则。

缺点:
添加新产品时需要同时添加新的产品工厂，系统中类的数量成对增加，增加了系统的复杂度，更多的类需要编译和运行，增加了系统的额外开销；
工厂和产品都引入了抽象层，客户端代码中均使用的抽象层（AbstractFactory和AbstractIntProduct ），增加了系统的抽象层次和理解难度。

适用环境:
客户端不需要知道它所需要创建的对象的类；
抽象工厂类通过其子类来指定创建哪个对象（运用多态性设计和里氏代换原则）

*/