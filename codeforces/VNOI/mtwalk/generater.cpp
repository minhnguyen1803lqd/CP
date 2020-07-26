#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 7;

int n;
int a[N][N];

int main() {
    srand(time(NULL));
    freopen ("mtwalk.inp", "w", stdout);
    n = rand() % 10 + 1;
    cout << n << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int tmp = rand() % 15 + 1;
            cout << tmp << " ";
        }
        cout << endl;
    }
    return (0);
}