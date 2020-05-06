#include <bits/stdc++.h>

using namespace std;

int main()
{
	int query;
	cout << "query: ";
	cin >> query;
	char chr[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

	srand(time(NULL));

	for (int qq = 1; qq <= query; qq++) {
		ofstream fo ("RGS.inp");
		int n = rand() % 20 + 1;
		for (int i = 1; i <= n; i++) {
			fo << chr[rand() % 26];
		}
		fo.close();

		system("./RGS");
		system("./RGSRand");

		ifstream f1 ("RGS.out");
		ifstream f2 ("RGS.ans");
		int tmp1, tmp2;
		f1 >> tmp1;
		f2 >> tmp2;
		cout << tmp1 << " " << tmp2 << endl;
		if (tmp1 == tmp2) {
			cout << "Pass test " << qq << endl;
		} else {
			cout << "WA on test " << qq << endl;
			exit(0);
		}
	}
	return 0;
}