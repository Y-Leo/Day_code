#if 0
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	// IO��OJ���ܻ��ж��������������������Ҫ������������������������ 
	int n;
	while (cin >> n)
	{
		long long sum = 0;
		vector<int> a;
		a.resize(3 * n);
		for (int i = 0; i < (3 * n); i++)
		{
			cin >> a[i];
		}
		/*
		����Ȼ��ȡ�±�Ϊ3n - 2��3n - 4 ��3n - 4... n+2��nλ�õ�Ԫ���ۼӼ��ɣ� 
		�൱�±�Ϊ[0,n-1]��n������ÿ�������ߵ�����ʣ�µ�2����������Ϊһ�飬 
		���ֵ�����ұߵ������δ�����м�ֵ��������ǰ�����δ��ֵ������
		*/
		sort(a.begin(), a.end());
		for (int i = n; i <= 3 * n - 2; i += 2)
		{
			sum += a[i];
		}
		cout << sum << endl;
	}
}
#endif

#if 0
//2. ����:ɾ�������ַ� | ʱ������ : 1�� | �ڴ����� : 32768K 
//���������ַ������ӵ�һ�ַ�����ɾ���ڶ����ַ��������е��ַ���
//���磬���롱They are students.���͡�aeiou������ɾ��֮��ĵ�һ���ַ�����ɡ�Thy r stdnts.��
//�������� :
//ÿ�������������2���ַ���
//������� : ���ɾ������ַ���

#include<iostream>
#include<string>
using namespace std;

int main() {
	// ע�����ﲻ��ʹ��cin���գ���Ϊcin�����ո�ͽ����ˡ� // oj��IO�����ַ������ʹ��getline��
	string str1, str2;
	//cin>>str1;
	//cin>>str2;
	getline(cin, str1);
	getline(cin, str2);
	// ʹ�ù�ϣӳ��˼����str2ͳ���ַ����ֵĴ��� 
	int hashtable[256] = {0};
	for (size_t i = 0; i < str2.size(); ++i) {
		hashtable[str2[i]]++;
	}
	// ����str1��str1[i]ӳ��hashtable��Ӧλ��Ϊ0�����ʾ����ַ���
	// str2��û�г��ֹ�������+=��ret��ע��������ò�Ҫstr1.erases(i) // ��Ϊ�߱�������erase�����׳���
	string ret;
	for (size_t i = 0; i < str1.size(); ++i)
	{
		if (hashtable[str1[i]] == 0)
			ret += str1[i];
	}

			cout << ret << endl;
		return 0;
	}

#endif

#if 0
//3�������ǹ�
//֪��A-B B-C A+B B+C����ABC�������򷵻�A��B��C����û���򷵻�NO

//˼·;�ܱ����Ľⷨ��������ѧʽ�ӱ�ʾ��ABC�����֮���ٻ�ȥ��֤����Ƿ���ȷ
#include<iostream>
using namespace std;
#include<vector>

void CountCandy(vector<int> v)
{
	v.resize(4, 0);
	int A, B, C;
	while (cin >> v[0] >> v[1] >> v[2] >> v[3])
	{
		A = (v[0] + v[2]) / 2;
		B = (v[1] + v[3]) / 2;
		C = v[3] - B;
		if ((A - B == v[0]) && (B - C == v[1]) && (A + B == v[2]) && (B + C == v[3]))
		{
			cout << A << " " << B << " " << C << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
}

int main()
{
	vector<int> v;
	CountCandy(v);
	return 0;
}
#endif

#if 1
//4������ת��
//����һ��ʮ����������ɵ��������֮���ת��

//˼·��
//1��ʮ����ת�������ƣ���Ȩȡ�൹�Ŷ�
//2��M���ϴ�Nֱ��MΪ�㣬ȡ������Ӧ���浽s��������s���
//3��ע�⼸�������
//                  1>��������תΪ����������ٲ��ϡ�-��
//                  2>��������9��ֱ�Ӵ���ss������Ӧ���棬��10��Ӧ����ΪA

#include<iostream>
using namespace std;
#include<string>
#include<algorithm>

string Transformation(int M, int N)
{
	bool flag = false;//��M<0���⻯����
	string s;
	string ss = "0123456789ABCDEF";  //Ϊ�˱�����������9�����
	if (M<0)
	{
		M = 0 - M;
		flag = true;
	}
	while (M)
	{
		s += ss[M%N];
		M /= N;
	}
	if (flag)
	{
		s += '-';
	}
	reverse(s.begin(), s.end());
	return s;
}

int main()
{
	int M;
	int N;
	while (cin >> M >> N)
	{
		cout << Transformation(M, N) << endl;
	}
	return 0;
}


#endif