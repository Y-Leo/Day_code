//×Ö·û´®Í¨Åä·û

#include<iostream>
using namespace std;
#include<string>

bool Cmp(const char* s, const char* s1)
{
	if (*s == '\0'&&*s1 == '\0')
		return true;
	if (*s == '\0' || *s1 == '\0')
		return false;

	if (*s == '?')
		return Cmp(s + 1, s1 + 1);
	else if (*s == '*')
		return Cmp(s + 1, s1) || Cmp(s + 1, s1 + 1) || Cmp(s, s1 + 1);
	else if (*s == *s1)
		return Cmp(s + 1, s1 + 1);
	return false;
}

int main()
{
	string s;
	string s1;
	while (cin >> s >> s1)
	{
		if (Cmp(s.c_str(), s1.c_str()))
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	return 0;
}
