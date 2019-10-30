#include<iostream>
using namespace std;



//题目一：设计一个类，该类只能在堆上创建对象

//方法：1、将类的构造函数私有，拷贝构造声明成私有。防止别人调用拷贝在栈上生成对象。
//      2、提供一个静态的成员函数，在该静态成员函数中完成堆对象的创建

class HeapOnly
{
public:
	static HeapOnly* Createobject()
	{
		return new HeapOnly;
	}
private:
	HeapOnly()//将类的构造函数私有
	{}

	//C++98
	//1、只声明，不实现。因为实现可能会很麻烦，而自己本身不需要
	//2、声明成私有

	//HeapOnly(const HeapOnly&);//拷贝构造声明成私有

	//or

	//C++11
	HeapOnly(const HeapOnly&) = delete;//拷贝构造声明成私有
};


//题目二：设计一个类，该类只能在栈上创建对象

//方法一：类似上面

class StackOnly
{
public:
	static StackOnly CreateObject()
	{
		return StackOnly();
	}
private:
	StackOnly()
	{}
};



//方法二：1、只能在栈上创建，则要将new的功能屏蔽掉（因为new在堆上动态申请空间）,将构造函数给为私有的
//      2、屏蔽operator new和定位new表达式，（屏蔽了operator new ，实际上也将定位new 屏蔽了）

class StackOnly2
{
public:
	StackOnly2()
	{}
private:
	void* operator new(size_t size);
	void operator delete(void* p);
};

int main()
{


	return 0;
}