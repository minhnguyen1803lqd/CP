#include <bits/stdc++.h>

using namespace std;

int main()
{
	srand(time(NULL));

	int query;
	cout << "query: ";
	cin >> query;
	ifstream fi ("BTA.inp");
	ofstream flog ("BTALog.out");
	for (int qq = 1; qq <= query; qq++) {
		ofstream fo ("BTA.inp");
		int n = rand() % 10 + 1;
		int m = rand() % 10 + 1;
		fo << n << " " << m << endl;
		for (int i = 1; i <= n; i++) {
			fo << rand() % 10 + 1 << " ";
		}
		fo << endl;
		for (int i = 1; i <= m; i++) {
			fo << rand() % 10 + 1 << " ";
		}
		fo << endl;
		system("./BTA");
		system("./BTARand");
		ifstream f1 ("BTA.out");
		ifstream f2 ("BTARand.out");
		int tmp1, tmp2;
		f1 >> tmp1;
		f2 >> tmp2;
		if (tmp1 == tmp2) {
			cout << "Passed test " << qq << endl;
		}
		else {
			cout << "WA on test " << qq << endl;
			
			int n, m;
			int a[10000], b[10000];
			fi >> n >> m;
			for (int i = 1; i <= n; i++) {
				fi >> a[i];
			}
			for (int i = 1; i <= m; i++) {
				fi >> b[i];
			}
			flog << n << " " << m << endl;
			for (int i = 1; i <= n; i++) {
				flog << a[i] << " ";
			}
			flog << endl;
			for (int i = 1; i <= m; i++) {
				flog << b[i] << " ";
			}
			flog << endl;
		}
	}
	return 0;
}