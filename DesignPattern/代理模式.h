#pragma once
#include "设计模式基类.h"

class 代理模式 :public 设计模式基类
{
public:
	void 运行() override;

};

/*

优点:
代理模式能够协调调用者和被调用者，降低系统耦合度；
客户端针对抽象主题角色编程，如果要增加或替换代理类，无需修改源代码，符合开闭原则，系统扩展性好；
远程代理优点：为两个位于不同地址空间的对象的访问提供解决方案，可以将一些资源消耗较多的对象移至性能较好的计算机上，提高系统整体性能；
虚拟代理优点：通过一个资源消耗较少的对象来代表一个消耗资源较多的对象，节省系统运行开销；
缓冲代理优点：为某一个操作结果提供临时的存储空间，可以在后续操作中使用这些结果，缩短了执行时间；
保护代理优点：:控制对一个对象的访问权限，为不同客户提供不同的访问权限。

缺点:
增加了代理类和代理对象，增加了代理对象中的某些处理流程，可能会使得系统响应变慢；
有的代理模式（如远程代理）实现代码较为复杂。

适用环境:
当客户端对象需要访问远程主机中的对象——可以使用远程代理；
当需要用一个资源消耗较少的对象来代表一个资源消耗较多的对象——虚拟代理；
当需要限制不同用户对一个独享的访问权限——保护代理；
当需要为一个频繁访问的操作结果提供临时存储空间——缓冲代理；
当需要为一个对象的访问提供一些额外的操作——智能引用代理。

*/