//�ٴ�ģ��ʵ��String��

#include<iostream>
using namespace std;
#include<assert.h>

namespace lxy
{

class String
{
public:
	///////////////////////////////////////////////////////����������
	String(const char* str ="")   //����
	{
		_size = strlen(str);
		_capacity = _size;
		_str = new char[_capacity + 1];
//		strcpy(_str, str);
	}

	String(const String& s)     //��������
		:_str(nullptr)
		, _size(0)
		, _capacity(0)
	{
		String strTmp(s);
		this->Swap(strTmp);
	}

	String& operator=(String s)   //��ֵ���������
	{
		this->Swap(s);
		return *this;
	}

	~String()       //����
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
	////////////////////////////////////////////////////////////////������

	//iterator begin()
	//{
	//	return _str;
	//}

	/*iterator  end()
	{
		return _str + _size;
	}*/

	///////////////////////////////////////////////////////////////////�޸�
	void Push_Back(char c)
	{
		if (_size == _capacity)
		{
			Reserve(_capacity * 2);     //��2���������ٿռ�
		}
		_str[_size++] = c;
		_str[_size] = '\0';
	}

	String& operator+=(char c)
	{
		Push_Back(c);
		return *this;
	}

	///////////////////////////////////////����ʵ��
	void Clear()
	{
		_size = 0;
		_str[_size] = '\0';
	}

	void Swap(String& s)
	{
		swap(_str, s._str);
		swap(_size, s._size);
		swap(_capacity, s._capacity);
	}

	const char* C_Str()const
	{
		return _str;
	}

	///////////////////////////////////////////��������
	size_t Size()const
	{
		return this->_size;
	}

	size_t Capacity()const
	{
		return this->_capacity;
	}

	bool Empty()const
	{
		if (_str)
		{
			return false;
		}
		else
			return true;
	}

	void Resize(size_t newSize, char c = '\0')
	{
		if (newSize > _size)
		{
			if (newSize > _capacity)
			{
				Reserve(newSize);
			}

			memset(_str + _size, c, newSize - _size);
		}
		_size = newSize;
		_str[newSize] = '\0';
	}

	void Reserve(size_t newCapacity)
	{
		if (newCapacity > _capacity)
		{
			char* str = new char[newCapacity + 1];
			//  strcpy(str, _str);

			delete[]_str;//�ͷžɿռ�
			_str = str;
			_capacity = newCapacity;
		}
	}

	////////////////////////////////////////////////////access

	char& operator[](size_t index)
	{
		assert(index < _size);
		return _str[index];
	}

	const char& operator[](size_t index)const
	{
		assert(index < _size);
		return _str[index];
	}

	////////////////////////////////////////////////////

	size_t Find(char c, size_t pos = 0)const
	{

	}

private:
	char* _str;
	size_t _capacity;
	size_t _size;
};

}

int main()
{


	return 0;
}