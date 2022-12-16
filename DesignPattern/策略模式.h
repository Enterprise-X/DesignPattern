#pragma once
#include "设计模式基类.h"
class 策略模式 :public 设计模式基类
{

public:
	void 运行() override;

};

/*

优点:
符合开闭原则，策略模式易于扩展，增加新的算法时只需继承抽象策略类，新设计实现一个具体策略类即可；
客户端可以无差别地通过公共接口调用，利用里式替换原则，灵活使用不同的算法策略；
提供了一个算法族管理机制和维护机制。

缺点:
客户端必须要知道所有的策略，以便在使用时按需实例化具体策略；
系统会产生很多单独的类，增加系统中类的数量；
客户端在同一时间只能使用一种策略。

适用环境:
系统需要在一个算法族中动态选择一种算法，可以将这些算法封装到多个具体算法类中，这些算法类都有共同的基类，即可以通过一个统一的接口调用任意一个算法，客户端可以使用任意一个算法；
不希望客户端知道复杂的、与算法相关的数据结构，在具体策略类中封装与算法相关的数据结构，可以提高算法的安全性。

#策略和命令的不同:
策略模式是将执行对象和策略解耦，是两层结构（执行对象和策略）
命令模式是命令和执行者解耦，有三层结构（请求命令者、命令和执行者）

*/