#include<iostream>
using namespace std;
#include<vector>

//杨辉三角
//               1
//           1   2   1
//        1    3   3    1
//     1     4   6    4    1  
class solution
{
public:
	vector<vector<int>> generatr(int numRows)
	{
		vector<vector<int>> vv;
		//开辟空间
		vv.resize(numRows);
		for (size_t i = 1; i <= numRows; ++i)
		{
			vv[i - 1].resize(i, 0);
			vv[i - 1][0] = 1;
			vv[i - 1][i - 1] = 1;
		}
		//赋值
		for (size_t i = 0; i < vv.size(); ++i)
		{
			for (size_t j = 0; j < vv[i].size(); ++j)
			{
				if (0 == vv[i][j])
				{
					vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
				}
				cout << vv[i][j] << ' ';
			}
			cout << endl;
		}
		return vv;
	}
};

int main()
{
	solution VV;
	VV.generatr(5);

	return 0;
}