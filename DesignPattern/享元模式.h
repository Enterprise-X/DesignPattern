#pragma once
#include "设计模式基类.h"

class 享元模式 :public 设计模式基类
{
public:
	void 运行() override;

};

/*

优点:
极大减少内存中对象的数量，使得相同对象或相似对象在内存中只保存一份；
享元对象的外部状态相对独立，而且不会影响其内部状态，从而使得享元对象可以在不同的环境中被共享。

缺点:
享元模式使得系统更加复杂，需要分离出内部状态和外部状态，从而使得程序的逻辑复杂化。
为了使对象可以共享，享元模式需要将享元对象的状态外部化，而读取外部状态使得运行时间变长。

适用环境:
当一个系统有大量相同或相似的对象，由于这些对象的大量使用，造成内存的大量耗费；使用享元模式可以节约内存空间，提高系统的性能
对象的大部分状态都可以外部化，可以将这些外部状态传入对象中；
比如一个字符串中存在很多重复的字符，可以针对每一个不同的字符创建一个享元对象，将其放在享元池中，需要时再从享元池取出。

*/