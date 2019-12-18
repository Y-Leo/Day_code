
//Ï´ÅÆ
#include <iostream>
using namespace std;
int main() {
	int i, j;
	long T;
	long n_k[100][2] = { 0 };
	long num[100][200] = { 0 };
	cin >> T;
	for (i = 0; i < T; i++) {
		cin >> n_k[i][0] >> n_k[i][1];
		for (j = 0; j < 2 * n_k[i][0]; j++) {
			cin >> num[i][j];
		}
	}
	for (i = 0; i < T; i++) {
		long array1[100], array2[100];
		for (int x = 0; x < n_k[i][1]; x++) {
			for (j = 0; j < n_k[i][0]; j++) {
				array1[j] = num[i][j];
				array2[j] = num[i][j + n_k[i][0]];
			}
			for (int y = 0; y < 2 * n_k[i][0]; y++) {
				if (y % 2 == 0) {
					num[i][y] = array1[y / 2];
				}
				else {
					num[i][y] = array2[(y - 1) / 2];
				}
			}
		}
		for (int t = 0; t < 2 * n_k[i][0] - 1; t++) {
			cout << num[i][t] << " ";
		}
		cout << num[i][2 * n_k[i][0] - 1] << endl;
	}
	return 0;
}