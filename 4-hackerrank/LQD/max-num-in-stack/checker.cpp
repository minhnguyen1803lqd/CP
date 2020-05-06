#include <bits/stdc++.h>

using namespace std;

int query;

int main() {
    srand(time(NULL));
    cout << "query: " << query;
    cin >> query;
    for (int qq = 1; qq <= query; qq++) {
        ofstream fo ("max-num-in-stack.inp");
        int q = rand() % 100 + 1;
        fo << q << endl;
        for (int i = 1; i <= q; i++) {
            int type = rand() % 3 + 1;
            fo << type << " ";
            if (type == 1) {
                int x = rand() % 100 + 1;
                fo << x << endl;
            } else {
                fo << endl;
            }
        }
        fo.close();
        system("burce.exe");
        system("max-num-in-stack.exe");
        ifstream f1 ("max-num-in-stack.out");
        ifstream f2 ("burce.out");
        vector < int > tmp1;
        vector < int > tmp2;
        while (f1.eof() == false) {
            int x;
            f1 >> x;
            tmp1.push_back(x);
        }
        while (f2.eof() == false) {
            int x;
            cin >> x;
            tmp2.push_back(x);
        }
        if (tmp1.size() != tmp2.size()) {
            cout << "WA on test " << qq << endl;
            exit(0);
        } else {
            int flag = 0;
            for (int i = 0; i < tmp1.size(); i++) {
                if (tmp1 != tmp2) {
                    flag = 1;
                    cout << "WA in test " << qq << endl;
                    exit(0);
                }
            }
            if (flag == 0) {
                cout << "Pass test " << qq << endl;
            }
        }
        f1.close();
        f2.close();
    }
}