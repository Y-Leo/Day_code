#if 0

//冒泡排序
#include<iostream>
using namespace std;
#include<vector>

void BubbleSort(vector<int>& v)
{
	int n = v.size();
	if (n <= 1)
	{
		return;
	}

	else
	{
		//控制循环次数，一次排序只能让一个元素有序
		for (int i = 0; i < n; ++i)
		{
			//相邻两个元素比较，满足需要则交换
			bool flag = false;
			for (int j = 0; j < n - i - 1; ++j) //n-i-1,减1是为了数组访问不越界
			{
				if (v[j]>v[j + 1])
				{
					flag = true;
					//交换
					swap(v[j], v[j + 1]);
				}
			}
			if (!flag)
			{
				break;
			}
		}
	}
}

int main()
{
	vector<int> v{2, 23, 45, 531, 1, 33, 1};
	BubbleSort(v);
	for (auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}

#endif



#if 0
//插入排序
#include<iostream>
using namespace std;
#include<vector>

void InsertSort(vector<int>& v)
{
	int n = v.size();
	if (n <= 1)
	{
		return;
	}

	else
	{
		//待排序的第一个元素
		for (int i = 1; i < n; ++i)
		{
			//value则为待排序元素
			int value = v[i];
			//找到要插入位置
			//j则为以排序元素的最后一个元素
			int j = i - 1;
				for (j=i-1; j >= 0; j--)
				{
					if (v[j]>value)
					{
						v[j + 1] = v[j];
					}
					else
					{
						break;
					}
				}
				//找到了要插入的位置
				v[j + 1] = value;
		}
	}
}

int main()
{
	vector<int> v{ 3, 4, 5, 1, 3, 2 };
	InsertSort(v);
	for (auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}

#endif



#if 1
//插入排序
#include<iostream>
using namespace std;
#include<vector>

void BinaryInsertSort(vector<int>& v)
{
	int n = v.size();
	if (n <= 1)
	{
		return;
	}
	else
	{
		for (int i = 1; i < n; i++)
		{
			//已排序的第一个元素
			int value = v[i];
			int low = 0;
			int high = i - 1;
			int j = i - 1;
			while (low <= high)
			{
				//寻找中间位置
			    //int mid = (low + high) / 2;    //有可能溢出
				int mid = low + (high - low)/2;
				if (v[mid] < value)
				{
					low = mid + 1;
				}
				else
				{
					high = mid - 1;
				}
			}
			//已找到插入位置high + 1
			for (j = i - 1; j >= high + 1; j--)
			{
				v[j + 1] = v[j];
			}
			v[j + 1] = value;
		}
	}
}

int main()
{
	vector<int> v{ 3, 4, 5, 1, 3, 2 };
	BinaryInsertSort(v);
	for (auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}

#endif
