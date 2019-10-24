#include<iostream>
using namespace std;
#include<string>

char* deleteRepeatedChars(char* parr)
{
	if (NULL == parr || 1 == strlen(parr))
		return parr;
	const int tableSize = 256;
	bool hashTable[tableSize];
	memset(hashTable, 0, sizeof(hashTable));

	char* slow = parr;
	char* fast = parr;
	while (*fast != '\0')
	{
		if (!hashTable[*fast])
		{
			hashTable[*fast] = 1;
			*slow = *fast;
			slow++;
		}
		fast++;
	}
	*slow = '\0';
	return parr;
}


int main()
{
	char arr[] = "goole";
	char *parr = arr;

	parr = deleteRepeatedChars(parr);
	cout << parr << endl;
	return 0;
}