//在有序数组里找和为n的最小的两个数
#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		int i = 0, j = array.size() - 1;
		vector<int> ret;
		vector<int> tmp;
		int mul = array[j] * array[j];
		// bool flag = true;
		for (i; i < j; ++i)
		{
			while (i < j)
			{
				if ((array[i] + array[j]) == sum)
				{
					tmp.push_back(array[i]);
					tmp.push_back(array[j]);

					if (array[i] * array[j] < mul)
					{
						mul = array[i] * array[j];
						ret.push_back(tmp[0]);
						ret.push_back(tmp[1]);
						tmp.clear();
					}
					break;
				}
				--j;
			}
			j = array.size() - 1;
		}
		return ret;
	}
};
int main()
{
	vector<int> v = { 1,2,4,7,11,15 };
	int n = 15;
	Solution A;
	A.FindNumbersWithSum(v, n);
	return 0;
}