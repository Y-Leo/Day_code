#include<iostream>
using namespace std;



//��Ŀһ�����һ���࣬����ֻ���ڶ��ϴ�������

//������1������Ĺ��캯��˽�У���������������˽�С���ֹ���˵��ÿ�����ջ�����ɶ���
//      2���ṩһ����̬�ĳ�Ա�������ڸþ�̬��Ա��������ɶѶ���Ĵ���

class HeapOnly
{
public:
	static HeapOnly* Createobject()
	{
		return new HeapOnly;
	}
private:
	HeapOnly()//����Ĺ��캯��˽��
	{}

	//C++98
	//1��ֻ��������ʵ�֡���Ϊʵ�ֿ��ܻ���鷳�����Լ�������Ҫ
	//2��������˽��

	//HeapOnly(const HeapOnly&);//��������������˽��

	//or

	//C++11
	HeapOnly(const HeapOnly&) = delete;//��������������˽��
};


//��Ŀ�������һ���࣬����ֻ����ջ�ϴ�������

//����һ����������

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



//��������1��ֻ����ջ�ϴ�������Ҫ��new�Ĺ������ε�����Ϊnew�ڶ��϶�̬����ռ䣩,�����캯����Ϊ˽�е�
//      2������operator new�Ͷ�λnew���ʽ����������operator new ��ʵ����Ҳ����λnew �����ˣ�

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