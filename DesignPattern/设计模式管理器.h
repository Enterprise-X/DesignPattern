#pragma once
#include "设计模式基类.h"

/*
设计模式分类:

创建型:
#单例1_____简单工厂2_____工厂方法3_____抽象工厂4_____原型5_____建造者6#

结构型:
#适配器7_____桥接器8_____组合9_____装饰10_____外观11_____享元12_____代理13#

行为型:
#职责链14_____命令15_____解释器16_____迭代器17_____中介者18_____备忘录19_____观察者20_____状态21_____策略22_____模板方法23_____访问者24#

特殊型:
#PIMPL100
*/

enum 枚举_设计模式
{
	/// 创建型
	单例 = 1,
	简单工厂 = 2,
	工厂方法 = 3,
	抽象工厂 = 4,
	原型 = 5,
	建造者 = 6,
	/// 结构型	
	适配器=7,
	桥接器 = 8,
	组合 = 9,
	装饰=10,
	外观 = 11,
	享元=12,
	代理=13,
	/// 行为型
	职责链=14,
	命令 = 15,
	解释器=16,
	迭代器=17,
	中介者=18,
	备忘录=19,
	观察者 = 20,
	状态=21,
	策略 = 22,
	模板方法=23,
	访问者=24,

	///特殊型
	PIMPL=100,
};
class 设计模式管理器
{
public:
	void 运行(枚举_设计模式 设计模式);
};

