#include <bits/stdc++.h>

using namespace std;

int query;

int main()
{
	cout << "query: ";
	cin >> query;

	srand(time(NULL));

	for (int qq = 0; qq < query; qq++) {
		ofstream fo ("MERGENUM.inp");
		int n = rand() % 8 + 1;
		int m = rand() % 8 + 1;
		for (int i = 1; i <= n; i++) {
			if (i == 1) {
				fo << rand() % 9 + 1;
			} else {
				fo << rand() % 10;	
			}
		}
		fo << " ";
		for (int i = 1; i <= m; i++) {
			if (i == 1) {
				fo << rand() % 9 + 1;
			} else {
				fo << rand() % 10;	
			}
		}
		fo << endl;
		fo.close();

		system("./MERGENUM");
		system("./MERGENUMRand");

		ifstream f1 ("MERGENUM.out");
		ifstream f2 ("MERGENUM.ans");
		string min1, max1, min2, max2;
		f1 >> min1 >> max1;
		f2 >> min2 >> max2;

		if (min1 == min2 && max1 == max2) {
			cout << "Pass test " << qq << endl;
		} else {
			cout << "WA on test " << qq << endl;
			exit(0);
		}
		f1.close();
		f2.close();
	}

	return 0;
}