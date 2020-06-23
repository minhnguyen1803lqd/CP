#include <bits/stdc++.h>

using namespace std;

int main() {
    srand(time(NULL));
    freopen ("dq.inp", "w", stdout);
    int n = rand() % 10 + 1;
    cout << n << endl;
    for (int i = 1; i <= n; i++) {
        int r = rand() % 20 + 1;
        int l = rand() % r + 1;
        int c = rand() % 20 + 1;
        cout << l << " " << r << " " << c << endl;
    }
    return (0);
}