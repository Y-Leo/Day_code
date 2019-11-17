
#if 0
#include<iostream>
using namespace std;
#include<vector>

//��Ŀһ��������
//����һ��
class Board {
public:
	bool checkWon(vector<vector<int> > board) {
		// write code here
		int n = board.size();

		for (int i = 0; i<n; ++i)
		{
			bool row = true;
			bool col = true;
			for (int j = 0; j<n; ++j)
			{
				if (board[i][j] != 1)
					row = false;
				if (board[j][i] != 1)
					col = false;
				if (!row&&!col)
				{
					break;
				}
			}
			if (row || col)
				return true;
		}

		//�Խ���
		bool row = true;
		bool col = true;
		for (int i = 0; i<n; ++i)
		{
			if (board[i][i] != 1)
				row = false;
			if (board[i][n - 1 - i] != 1)
				col = false;
		}
		if (row || col)
			return true;

		return false;
	}
};

//�����������Ż���ʱ�临�Ӷȸ���


class Board {
public:
	bool checkWon(vector<vector<int> > board) 
	{
		int n = board.size();
		int LtoR = 0;
		int RtoL = 0;
		for (int i = 0; i<n; ++i)
		{
			int col = 0;
			int row = 0;
			LtoR += board[i][i];
			RtoL += board[i][n - 1 - i];
			for (int j = 0; j<n; ++j)
			{
				col += board[i][j];
				row += board[j][i];
			}
			if (col == n || row == n || RtoL == n || LtoR == n)
				return true;
		}
		return false;
	}
};

#endif

//��Ŀ��������ǿ��

#include<iostream>
using namespace std;
#include<string>

void PasswordRank(string& s)
{
	int count = 0;
	//���볤��
	if (s.size() <= 4)
		count += 5;
	else if (s.size() >= 5 && s.size() <= 7)
		count += 10;
	else
		count += 25;

	//ͳ����ĸ,����,����
	int ch_num = 0;
	int CH_num = 0;
	int n_num = 0;
	int s_num = 0;
	for (int i = 0; i<s.size(); ++i)
	{
		if (s[i] >= 65 && s[i] <= 90)
			CH_num++;
		else if (s[i] >= 97 && s[i] <= 122)
			ch_num++;
		else if (s[i] >= 48 && s[i] <= 57)
			n_num++;
		else
			s_num++;
	}

	//��ĸ
	//ȫΪ��Сд��ĸ
	if (ch_num == s.size() || CH_num == s.size())
		count += 10;
	//��Сд���д
	else if (ch_num&&CH_num)
		count += 20;
	//û����ĸ
	else if (!(ch_num + CH_num))
		count += 0;

	//����
	//û������
	if (!n_num)
		count += 0;
	else if (n_num == 1)
		count += 10;
	else if (n_num>1)
		count += 20;

	//����
	//û�з���
	if (!s_num)
		count += 0;
	else if (s_num == 1)
		count += 10;
	else if (s_num>1)
		count += 25;

	//����
	//��ĸ������
	if (n_num && (ch_num + CH_num) && !s_num)
		count += 2;
	else if (n_num && (ch_num + CH_num) && s_num)
		count += 3;
	else if (n_num&&ch_num&&CH_num&&s_num)
		count += 5;

	//�жϵȼ�
	if (count >= 90)
		cout << "VERY_SECURE" << endl;
	else if (count >= 80 && count<90)
		cout << "SECURE" << endl;
	else if (count >= 70 && count<80)
		cout << "VERY_STRONG" << endl;
	else if (count >= 60 && count<70)
		cout << "STRONG" << endl;
	else if (count >= 50 && count<60)
		cout << "AVERAGE" << endl;
	else if (count >= 25 && count<50)
		cout << "WEAK" << endl;
	else
		cout << "VERY_WEAK" << endl;
}

int main()
{
	string s;
	while (cin >> s)
		PasswordRank(s);
	return 0;
}