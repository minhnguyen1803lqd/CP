#include <bits/stdc++.h>

using namespace std;

int main() {
    srand(time(NULL));
    freopen ("str.inp", "w", stdout);
    int n = rand() % 100 + 1;
    int m = rand() % 100 + 1;
    int l = int('a');
    int r = int('z');
    for (int i = 1; i <= n; i++) {
        cout << char(rand() % (r - l + 1) + l);
    }
    cout << endl;
    for (int i = 1; i <= m; i++) {
        cout << char(rand() % (r - l + 1) + l);
    }
    cout << endl;
    return (0);
}