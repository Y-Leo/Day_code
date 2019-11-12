#if 0

//ð������
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
		//����ѭ��������һ������ֻ����һ��Ԫ������
		for (int i = 0; i < n; ++i)
		{
			//��������Ԫ�رȽϣ�������Ҫ�򽻻�
			bool flag = false;
			for (int j = 0; j < n - i - 1; ++j) //n-i-1,��1��Ϊ��������ʲ�Խ��
			{
				if (v[j]>v[j + 1])
				{
					flag = true;
					//����
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
//��������
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
		//������ĵ�һ��Ԫ��
		for (int i = 1; i < n; ++i)
		{
			//value��Ϊ������Ԫ��
			int value = v[i];
			//�ҵ�Ҫ����λ��
			//j��Ϊ������Ԫ�ص����һ��Ԫ��
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
				//�ҵ���Ҫ�����λ��
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
//��������
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
			//������ĵ�һ��Ԫ��
			int value = v[i];
			int low = 0;
			int high = i - 1;
			int j = i - 1;
			while (low <= high)
			{
				//Ѱ���м�λ��
			    //int mid = (low + high) / 2;    //�п������
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
			//���ҵ�����λ��high + 1
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
