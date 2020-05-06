#include <bits/stdc++.h>

using namespace std;

int query;

int main() {
    cout << "query: ";
    cin >> query;

    for (int qq = 1; qq <= query; qq++) {
        ofstream fo ("thi-sinh-may-man.inp");
        long long n = rand() % 10000 + 1;
        long long k = rand() % 1000000000000000000 + 1;
        fo << n << " " << k << endl;
        for (int i = 1; i <= n; i++) {
            fo << rand() % 1000000000000000000 - rand() % 1000000000 << " ";
        }
        fo.close();
        system("thi-sinh-may-man.exe");
        system("bruce.exe");
        ifstream f1 ("thi-sinh-may-man.out");
        ifstream f2 ("thi-sinh-may-man.ans");
        int tmp1, tmp2;
        f1 >> tmp1;
        f2 >> tmp2;
        if (tmp1 != tmp2) {
            cout << "WA on test " << qq << endl;
            exit(0);
        } else {
            cout << "Pass test " << qq << endl;
        }
        f1.close();
        f2.close();
    }

    return 0;
}